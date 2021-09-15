#include "SingleLinkedList.h"
template <class T> SingleLinkedList<T>::SingleLinkedList() {
  this->size = 0;
  this->head = nullptr;
}
template <class T> SingleLinkedList<T>::~SingleLinkedList<T>() {
  this->size = 0;
  delete head;
}

template <class T> int SingleLinkedList<T>::getSize() { return this->size; }
template <class T> bool SingleLinkedList<T>::isEmpty() {
  return (bool)(getSize() == 0);
}

template <class T> void SingleLinkedList<T>::Clear() {
  Node<T> *currentNode = head;
  Node<T> *nextNode = nullptr;

  while (currentNode != nullptr) {
    nextNode = currentNode->getNext();
    currentNode->setNext(nullptr);
    free(currentNode);
    currentNode = nextNode;
  }
  head = nullptr;
  size = 0;
}

/* ================= Define Add =============*/
template <class T> void SingleLinkedList<T>::add(T *element) {
  addLast(element);
}
template <class T> void SingleLinkedList<T>::addFirst(T *element) {
  if (isEmpty()) {
    head = new Node<T>(element, nullptr);
  } else {
    Node<T> *newNode = new Node<T>(element, nullptr);
    newNode->setNext(head);
    head = newNode;
  }
  size++;
}
template <class T> void SingleLinkedList<T>::addLast(T *element) {
  if (isEmpty()) {
    head = new Node<T>(element, nullptr);
  } else {
    Node<T> *currentNode = head;
    // Loop until last node
    while (currentNode->getNext() != nullptr) {
      currentNode = currentNode->getNext();
    }
    Node<T> *newNode = new Node<T>(element, nullptr);
    currentNode->setNext(newNode);
  }
  size++;
}
/* ================= End Add =============*/

/* ================= Define get element =============*/
template <class T> T *SingleLinkedList<T>::peekFirst() {
  if (isEmpty())
    throw std::out_of_range("Empty Linked List");
  return head->getData();
}

template <class T> T *SingleLinkedList<T>::peekLast() {
  if (isEmpty())
    throw std::out_of_range("Empty Linked List");
  Node<T> *currentNode = head;
  while (currentNode->getNext() != nullptr) {
    currentNode = currentNode->getNext();
  }
  return currentNode->getData();
}
/* ================= End Define get element =============*/

/* ================= Define remove Element =============*/
template <class T> T *SingleLinkedList<T>::removeFirst() {
  if (isEmpty())
    throw std::out_of_range("Empty Linked List!");
  T *data = head->getData();
  Node<T> *temp = head;
  head = head->getNext();

  /* remove node */
  temp->setNext(nullptr);
  free(temp);
  size--;

  return data;
}

template <class T> T *SingleLinkedList<T>::removeLast() {
  if (isEmpty())
    throw std::out_of_range("Empty Linked List!");
  Node<T> *currentNode = head;
  /* previous last node */
  Node<T> *prevNode = head;
  while (currentNode->getNext() != nullptr) {
    prevNode = currentNode;
    currentNode = currentNode->getNext();
  }

  T *data = currentNode->getData();

  /* set prev last node point to null */
  prevNode->setNext(nullptr);
  /* remove node */
  free(currentNode);
  size--;

  return data;
}

template <class T> T *SingleLinkedList<T>::remove(Node<T> *node) {
  /* node is head */
  if (node->Equal(head))
    return removeFirst();
  /* node is tail*/
  if (node->getNext() == nullptr)
    return removeLast();
  Node<T> *currentNode = head;
  Node<T> *prevNode = head;
  while (currentNode != nullptr) {
    prevNode = currentNode;
    currentNode = currentNode->getNext();
    if (currentNode->Equal(node))
      break;
  }
  prevNode->setNext(currentNode->getNext());
  /* remove node */
  currentNode->setNext(nullptr);
  free(currentNode);
  size--;

  T *data = node->getData();
  return data;
}

template <class T> bool SingleLinkedList<T>::remove(T *obj) {
  Node<T> *currentNode = head;
  if (obj == nullptr) {
    while (currentNode != nullptr) {
      if (currentNode->getData() == nullptr) {
        remove(currentNode);
        return true;
      }
      currentNode = currentNode->getNext();
    }
  } else {
    while (currentNode != nullptr) {
      if (*currentNode->getData() == *obj) {
        remove(currentNode);
        return true;
      }
      currentNode = currentNode->getNext();
    }
  }
  return false;
}

template <class T> T *SingleLinkedList<T>::removeAt(int index) {
  if (index < 0 || index > size)
    throw std::out_of_range("Index is illegal!");
  Node<T> *currentNode = head;
  int i = 0;
  while (i != index) {
    currentNode = currentNode->getNext();
    i++;
  }
  return remove(currentNode);
}

/* ================= End Define remove element =============*/

template <class T> int SingleLinkedList<T>::indexOf(T *obj) {
  int index = 0;
  Node<T> *currentNode = head;

  if (obj == nullptr) {
    while (currentNode != nullptr) {
      if (currentNode->getData() == nullptr) {
        return index;
      }
      currentNode = currentNode->getNext();
      index++;
    }
  } else {
    while (currentNode != nullptr) {
      if (*currentNode->getData() == *obj) {
        return index;
      }
      currentNode = currentNode->getNext();
      index++;
    }
  }
  return -1;
}

template <class T> void SingleLinkedList<T>::Print() {
  Node<T> *currentNode = head;
  while (currentNode != nullptr) {
    std::cout << currentNode << " " << std::endl;
    currentNode = currentNode->getNext();
  }
}

template <class T> bool SingleLinkedList<T>::contains(T *obj) {
  return (bool)(indexOf(obj) == -1);
}
template <class T> std::string SingleLinkedList<T>::toString() {
  if (isEmpty())
    return "[]";
  std::stringstream ss;
  ss << "[";
  Node<T> *currentNode = head;
  while (currentNode != nullptr) {
    ss << currentNode->toString();
    if (currentNode->getNext() != nullptr)
      ss << ", ";
    currentNode = currentNode->getNext();
  }
  ss << "]";
  return ss.str();
}
