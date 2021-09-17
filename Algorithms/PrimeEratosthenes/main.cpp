#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n);

int main(void) {
  int n;
  cin >> n;
  cout << isPrime(n) << endl;
  return 0;
}

bool isPrime(int n) {
  if (n <= 1)
    return false;
  int a = 2;
  vector<bool> mark;
  mark.resize(n, false);
  while (true) {
    if (a * a > n)
      break;
    int p = a * a;
    while (p <= n) {
      mark[p] = true;
      p += a;
    }
    ++a;
    while (a <= n && mark[a])
      ++a;
    if (a > n)
      break;
  }

  return !mark[n];
}
