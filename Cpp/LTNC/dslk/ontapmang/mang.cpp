#include <iostream>
using namespace std;

void input(double a[], int &n) {
  do {
    cout << "Cho n = ";
    cin >> n;
  } while (n < 5 || n > 100);

  for (int i = 0; i < n; i++) {
    cout << "Nhap phan tu thu " << i + 1 << ": ";
    cin >> a[i];
  }
}

void output(double a[], double n) {
  cout << "Hien thi danh sach:";
  for (int i = 0; i < n; i++)
    cout << " " << a[i];
  cout << endl;
}

void deleteFirst(double a[], int &n) {
  for (int i = 0; i < n - 1; i++) {
    a[i] = a[i + 1];
  }
  n--;
}

void deleteLast(double a[], int &n) {
  if (n > 0) {
    n--;
  }
}

void insertFirst(double a[], int &n, double x) {
  for (int i = n; i > 0; i--) {
    a[i] = a[i - 1];
  }
  a[0] = x;
  n++;
}

void insertLast(double a[], int &n, double x) {
  n++;
  a[n - 1] = x;
}

double sum(double a[], double n) {
  double s = 0;
  for (int i = 0; i < n; i++)
    s += a[i];
  return s;
}

int main() {
  double a[100], x;
  int n;

  input(a, n);
  output(a, n);

  // cout << "Hay xoa phan tu o dau va cuoi danh sach!" << endl;
  // deleteFirst(a, n);
  // deleteLast(a, n);
  // output(a, n);

  cout << "Cho x = ";
  cin >> x;
  // cout << "\nHay them x vao dau va cuoi danh sach!" << endl;
  // insertFirst(a, n, x);
  insertLast(a, n, x);
  output(a, n);

  cout << "Tong cac phan tu: " << sum(a, n) << endl;
}
