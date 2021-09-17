#include <iostream>
using namespace std;

class Node {
private:
  int data;
  Node *next;

public:
  Node() {
    data = 0;
    next = nullptr;
  }
  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
  ~Node() {
    data = 0;
    delete next;
  }
  void setData(int data) { this->data = data; }
  int getData() { return this->data; }
  void setNext(Node *next) { this->next = next; }
  Node *getNext() { return this->next; }
};

class SingleLinkedList {
private:
  Node *head;
  int size;

public:
  SingleLinkedList() {
    size = 0;
    head = nullptr;
  }
  ~SingleLinkedList() {
    size = 0;
    delete head;
  }
  int getSize() { return size; }
  bool isEmpty() { return (bool)(getSize() == 0); }
  // ============ define add===========
  void addLast(int element) {
    if (isEmpty()) {
      head = new Node(element, nullptr);
      head->setNext(head);
    } else {
      Node *currentNode = head;
      // Loop until last node
      while (currentNode->getNext() != head) {
        currentNode = currentNode->getNext();
      }
      Node *newNode = new Node(element, nullptr);
      currentNode->setNext(newNode);
      newNode->setNext(head);
    }
    size++;
  }
  // ============ end define add===========

  void Show() {
    Node *currentNode = head;
    while (currentNode->getNext() != head) {
      cout << currentNode->getData() << " ";
      currentNode = currentNode->getNext();
    }
    cout << currentNode->getData() << endl;
  }
};

int main() {
  int n;
  SingleLinkedList *list = new SingleLinkedList();
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    list->addLast(x);
  }
  list->Show();
  return 0;
}
