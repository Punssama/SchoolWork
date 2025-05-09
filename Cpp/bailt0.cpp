#include <iostream>

using namespace std;

int Fibo(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return 2 * (n - 1) + (n - 2);
}

int main() {}
