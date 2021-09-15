#include "node.h"
template <class T> Node<T>::Node(T *data, Node<T> *next) {
  this->data = data;
  this->next = next;
}

template <class T> Node<T>::~Node<T>() {
  delete data;
  delete next;
}

template <class T> T *Node<T>::getData() { return this->data; }
template <class T> void Node<T>::setData(T *data) { this->data = data; }
template <class T> Node<T> *Node<T>::getNext() { return this->next; }
template <class T> void Node<T>::setNext(Node<T> *next) { this->next = next; }

template <class T> bool Node<T>::Equal(Node<T> *node) {
  if (this->getData() != node->getData())
    return false;
  if (this->getNext() != node->getNext())
    return false;
  return true;
}

template <class T> std::string Node<T>::toString() {
  std::stringstream ss;
  if (this->data == nullptr)
    ss << "NULL";
  else
    ss << *data;
  return ss.str();
}
