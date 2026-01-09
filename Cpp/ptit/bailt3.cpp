#include <cstdio>
#include <iostream>

using namespace std;

void inputMatrix(int arr[][100], int &n) {
  cout << "Nhap vao n = ";
  cin >> n;
  cout << "Nhap ma tran" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
}

void printMatrix(int arr[][100], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      cout << arr[i][j] << " ";
    }
    cout << arr[i][n - 1];
    cout << endl;
  }
}

void printMatrix(int arr[][100], int n, int k) {
  bool first = true;
  for (int i = 0; i < n; i++) {
    if (arr[k][i] % 2 != 0) {
      if (!first) {
        cout << ", ";
      }
      cout << "a[" << k << "][" << i << "]";
      first = false;
    }
  }
}

void MatranTamGiacTren(int arr[][100], int n) {
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < i; k++) {
      cout << " ";
    }
    for (int j = i; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
void MatranTamGiacDuoi(int arr[][100], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int arr[100][100];
  int k, n;
  freopen("input.txt", "r", stdin);
  inputMatrix(arr, n);
  cout << "Ma tran: " << endl;
  printMatrix(arr, n);
  cout << endl;
  // cout << "Nhap vao k = ";
  // cin >> k;
  // cout << "vi tri cua cac phan tu la: " << endl;
  // printMatrix(arr, n, k);
  // cout << endl;
  cout << "Ma tran tam giac tren: " << endl;
  MatranTamGiacTren(arr, n);
  cout << "Ma tran tam giac duoi: " << endl;
  MatranTamGiacDuoi(arr, n);
}
