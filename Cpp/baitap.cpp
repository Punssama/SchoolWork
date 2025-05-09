#include <iostream>

using namespace std;

double gt(int n)
{
  if (n <= 0)
  {
    return 1;
  }
  return n * gt(n - 1);
}

double mu(int so, int soMu)
{
  if (soMu == 1)
  {
    return so * 1;
  }
  return so * 1.0 * mu(so, soMu - 1);
}

double tinhTong(int n, int x)
{
  if (n == 1)
  {
    return x;
  }
  return mu(x, n) / gt(n) + tinhTong(x, n - 1);
}

int main()
{
  int n, x;
  cout << "Nhap vao x: ";
  cin >> x;
  cout << "Nhap vao n: ";
  cin >> n;
  cout << "ket qua la: " << tinhTong(n, x) << endl;
  return 0;
}
