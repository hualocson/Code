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
