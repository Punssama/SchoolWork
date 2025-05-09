#include <cmath>
#include <iostream>

using namespace std;

bool isSquared(int n) {
  bool flag = false;
  int s = sqrt(n);
  if (s * s == n)
    return flag = true;
  return flag;
}

int main() {
  int n;
  cout << "Nhap N = ";
  cin >> n;
  if (n < 0)
    cout << "n khong duong!";
  else {
    cout << "So chinh phuong:";
    for (int i = 0; i < n; i++) {
      if (isSquared(i)) {
        cout << " " << i;
      }
    }
  }
}
