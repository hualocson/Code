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
  T *removeLast();
  T *remove(Node<T> *);
  bool remove(T *);
  T *removeAt(int);

  int indexOf(T *);
  bool contains(T *);

  void Print();

  std::string toString();
};
#endif /* ifndef SINGLELINKEDLIST_H */
