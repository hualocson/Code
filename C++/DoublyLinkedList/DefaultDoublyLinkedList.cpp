#include "node.cpp"
template <class T> class DoublyLinkedList {
private:
  int size;
  Node<T> *head;
  Node<T> *tail;

public:
  DoublyLinkedList<T>() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
  }

  ~DoublyLinkedList<T>() {
    this->size = 0;
    delete head;
    delete tail;
  }

  void Clear() {
    Node<T> *currentNode = head;
    Node<T> *nextNode = nullptr;
    // While have current node -> delete current node
    while (currentNode != nullptr) {
      nextNode = currentNode->getPNext();
      /* remove current node*/
      currentNode->setPNext(nullptr);
      currentNode->setPPrev(nullptr);
      free(currentNode);
      currentNode = nextNode;
    }
    head = tail = nullptr;
    size = 0;
  }

  int getSize() { return size; }

  bool isEmpty() { return (bool)(getSize() == 0); }

  void add(T *element) { addLast(element); }

  void addFirst(T *element) {
    if (isEmpty()) {
      head = tail = new Node<T>(element, nullptr, nullptr);
    } else {
      Node<T> *newNode = new Node<T>(element, nullptr, head);
      head->setPPrev(newNode);
      head = head->getPPrev();
    }
    size++;
  }

  void addLast(T *element) {
    if (isEmpty()) {
      head = tail = new Node<T>(element, nullptr, nullptr);
    } else {
      Node<T> *newNode = new Node<T>(element, tail, nullptr);
      tail->setPNext(newNode);
      tail = tail->getPNext();
    }
    size++;
  }

  /* get First elemet */
  T *peekFirst() {
    if (isEmpty())
      throw std::out_of_range("Empty Linked List");
    return head->getData();
  }

  /* get Last elemet */
  T *peekLast() {
    if (isEmpty())
      throw std::out_of_range("Empty Linked List");
    return tail->getData();
  }

  T *removeFirst() {
    if (isEmpty())
      throw std::out_of_range("Empty Linked List");
    T *data = head->getData();
    Node<T> *temp = head;
    head = head->getPNext();

    /* remove old head */
    temp->setPNext(nullptr);
    temp->setPPrev(nullptr);
    free(temp);

    size--;
    if (isEmpty())
      tail = nullptr;
    else
      head->setPPrev(nullptr);
    return data;
  }

  T *removeLast() {
    if (isEmpty())
      throw std::out_of_range("Empty Linked List");
    T *data = tail->getData();
    Node<T> *temp = tail;
    tail = tail->getPPrev();

    /* remove old tail*/
    temp->setPNext(nullptr);
    temp->setPPrev(nullptr);
    free(temp);

    size--;
    if (isEmpty())
      head = nullptr;
    else
      tail->setPNext(nullptr);
    return data;
  }

  T *remove(Node<T> *node) {
    /* node is head */
    if (node->getPPrev() == nullptr)
      removeFirst();
    /* node is tail*/
    if (node->getPNext() == nullptr)
      removeLast();

    Node<T> *temp = node->getPPrev();
    temp->setPNext(node->getPNext());
    temp = node->getPNext();
    temp->setPPrev(node->getPPrev());

    /* remove Node */
    node->setPNext(nullptr);
    node->setPPrev(nullptr);
    T *data = node->getData();
    free(node);

    size--;
    return data;
  }

  bool remove(T *obj) {
    Node<T> *currentNode = head;

    if (obj == nullptr) {
      while (currentNode != nullptr) {
        if (currentNode->getData() == nullptr) {
          remove(currentNode);
          return true;
        }
        currentNode = currentNode->getPNext();
      }
    } else {
      while (currentNode != nullptr) {
        if (*currentNode->getData() == *obj) {
          remove(currentNode);
          return true;
        }
        currentNode = currentNode->getPNext();
      }
    }

    return false;
  }

  T *removeAt(int index) {
    if (index < 0 || index > size)
      throw std::out_of_range("Index is illegal!");
    Node<T> *currentNode;
    int i;
    if (index < size / 2) {
      currentNode = head;
      i = 0;
      while (i != index) {
        currentNode = currentNode->getPNext();
        i++;
      }
    } else {
      currentNode = tail;
      i = size - 1;
      while (i != index) {
        currentNode = currentNode->getPPrev();
        i--;
      }
    }
    return remove(currentNode);
  }

  int indexOf(T *obj) {
    int index = 0;
    Node<T> *currentNode = head;

    if (obj == nullptr) {
      while (currentNode != nullptr) {
        if (currentNode->getData() == nullptr) {
          return index;
        }
        currentNode = currentNode->getPNext();
        index++;
      }
    } else {
      while (currentNode != nullptr) {
        if (*currentNode->getData() == *obj) {
          return index;
        }
        currentNode = currentNode->getPNext();
        index++;
      }
    }
    return -1;
  }

  bool contains(T *obj) { return (bool)(indexOf(obj) != -1); }

  std::string toString() {
    if (isEmpty()) {
      return "[]";
    }
    std::stringstream ss;
    ss << "[";
    Node<T> *currentNode = head;

    while (currentNode != nullptr) {
      ss << currentNode->toString();
      if (currentNode->getPNext() != nullptr)
        ss << ", ";
      currentNode = currentNode->getPNext();
    }
    ss << "]";
    return ss.str();
  }
};
