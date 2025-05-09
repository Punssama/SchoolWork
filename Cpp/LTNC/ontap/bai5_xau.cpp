#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int dem(string s) {
  int dem = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
      dem++;
    }
  }
  return dem;
}

int demKTKhac(string s) {
  int demkt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (!isdigit(s[i]) && !isalpha(s[i])) {
      demkt++;
    }
  }
  return demkt;
}

string xoa(string s) {
  string xoakt = "";
  for (int i = 0; i < s.length(); i++) {
    if (isdigit(s[i]) || isalpha(s[i])) {
      xoakt += s[i];
    }
  }
  return xoakt;
}

int main() {
  string s;
  cout << "Nhap xau S:";
  getline(cin, s);
  if (s.size() == 0) {
    cout << "Xau rong!";
  } else {
    int soTu = dem(s);
    cout << "So tu cua S: " << soTu << endl;

    cout << "So ky tu khong la chu cai/chu so: " << demKTKhac(s) << endl;

    s = xoa(s);
    cout << "Xau S sau khi xoa:" << s;
  }
  return 0;
}
