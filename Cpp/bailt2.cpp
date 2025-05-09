#include <iostream>

using namespace std;

void inputarr(int arr[], int &n) {
  cout << "Nhap vao n = ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Nhap A[" << i + 1 << "] = ";
    cin >> arr[i];
  }
}

void print(int arr[], int n) {

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

double aver(int arr[], int n) {
  double d = 0, rs = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] % 5 == 0) {
      d++;
      rs += arr[i];
    }
  }
  return rs / d;
}

int main() {
  int n, arr[10000];

  inputarr(arr, n);

  print(arr, n);
  cout << endl;
  cout << "trung binh cong cac so la boi cua 5 la: " << aver(arr, n);
}
