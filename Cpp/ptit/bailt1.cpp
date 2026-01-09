
#include <cmath>
#include <iostream>

using namespace std;

bool isSquare(int n) {
  int a = sqrt(n);
  bool flag = false;

  if (a * a == n)
    return flag = true;
  return flag;
}

void printSquare(int n) {
  do {
    cout << "Nhap n = ";
    cin >> n;

  } while (n <= 0 || n >= 100);
  cout << "Cac so chinh phuong nho hon n la: ";
  for (int i = 0; i < n; i++)
    if (isSquare(i))
      cout << i << " ";
}

int main() {
  int n;
  printSquare(n);
  return 0;
}
