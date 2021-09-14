#include <iostream>
using namespace std;

bool isPerfectNum(int n);
int theNPerfectNum(int n);

int main() {
  int n;
  cout << "Nhap n: ";
  cin >> n;
  int kq = theNPerfectNum(n);
  cout << "KQ: " << kq;
  cout << endl;
  system("pause");
}
int theNPerfectNum(int n) {
  int count = 0, num = 10;
  while (count < n) {
    num += 9;
    if (isPerfectNum(num))
      count++;
  }
  return num;
}

bool isPerfectNum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  if (sum == 10)
    return 1;
  return 0;
}
