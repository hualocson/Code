#include "DefaultDoublyLinkedList.cpp"
using namespace std;

int main() {
  try {
    DoublyLinkedList<string> *demo = new DoublyLinkedList<string>();
    string str1 = "ahihi";
    string str2 = "ahuhu";
    string first, last;
    first = "First";
    last = "Last";
    demo->add(&str1);
    demo->add(&str2);
    cout << demo->toString() << endl;
    demo->addFirst(&first);
    demo->addLast(&last);
    cout << demo->toString() << endl;
    demo->Clear();
    cout << demo->toString() << endl;

    system("pause");
    return 0;
  } catch (exception const &ex) {
    cerr << "Exception: " << ex.what() << endl;
    return -1;
  }
}
