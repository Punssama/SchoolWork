#include <iostream>

using namespace std;

int sum(int n) {
  int rs = 0;
  for (int i = 2; i <= n; i++) {
    rs += ((i - 1) * i * (i + 1));
  }
  return rs + 1;
}
int main() {
  int n;
  cout << "N = ";
  cin >> n;
  if (n <= 2 || n >= 20) {
    cout << "N khong thoa man!";

  } else {
    cout << "Tong A = " << sum(n);
  }
}
