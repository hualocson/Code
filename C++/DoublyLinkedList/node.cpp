#include "main.h"

template <class T> class Node {
private:
  T *data;
  Node<T> *pNext;
  Node<T> *pPrev;

public:
  Node<T>(T *data, Node<T> *pPrev, Node<T> *pNext) {
    this->data = data;
    this->pPrev = pPrev;
    this->pNext = pNext;
  }
  ~Node<T>() {
    delete data;
    delete pNext;
    delete pPrev;
  }

  std::string toString() {
    std::stringstream ss;
    if (data == nullptr)
      ss << "NULL";
    else
      ss << *data;
    return ss.str();
  }

  T *getData() { return data; }
  void setData(T *data) {
    delete this->data;
    this->data = data;
  }
  Node<T> *getPNext() { return pNext; }
  void setPNext(Node<T> *next) { this->pNext = next; }
  Node<T> *getPPrev() { return pPrev; }
  void setPPrev(Node<T> *prev) { this->pPrev = prev; }
};
