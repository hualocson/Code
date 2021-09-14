#ifndef NODE_H
#define NODE_H
#include "main.h"

template <class T> class Node {
private:
  T *data;
  Node<T> *next;

public:
  Node<T>(T *, Node<T> *);
  ~Node<T>();

  void setData(T *);
  T *getData();
  void setNext(Node<T> *);
  Node<T> *getNext();

  std::string toString();
};

#endif /* ifndef NODE_H */
