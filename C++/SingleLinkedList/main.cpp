#include "main.h"
#include "SingleLinkedList.cpp"
using namespace std;
int main() {
  string str1 = "str1";
  string str2 = "str2";
  string str3 = "str3";
  SingleLinkedList<string> *demo = new SingleLinkedList<string>();
  cout << demo->toString() << endl;
  demo->add(&str1);
  demo->add(&str2);
  demo->addFirst(&str3);
  cout << demo->toString() << endl;
  /* cout << *demo->removeFirst() << endl; */
  int ind = demo->indexOf(&str1);
  cout << ind << endl;
  cout << *demo->removeAt(ind) << endl;
  cout << demo->toString() << endl;
  demo->Print();
  return 0;
}
