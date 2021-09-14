#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include "node.cpp"
template <class T> class SingleLinkedList {
private:
  int size;
  Node<T> *head;

public:
  SingleLinkedList<T>();
  ~SingleLinkedList<T>();

  void Clear();
  int getSize();
  bool isEmpty();

  void add(T *);
  void addFirst(T *);
  void addLast(T *);

  /* get element */
  T *peekFirst();
  T *peekLast();

  /* remove element */
  T *removeFirst();

  std::string toString();
};
#endif /* ifndef SINGLELINKEDLIST_H */
