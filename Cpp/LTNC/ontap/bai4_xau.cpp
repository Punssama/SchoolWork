#include <cctype>
#include <iostream>
#include  <string>
using namespace std;

int countWords(const string &xau) {
  int dem = 0;
  bool trongTu = false;

  for (char c : xau) {
    if (c != ' ' && c != '\t' && c != '\n') {
      if (!trongTu) {
        dem++;
        trongTu = true;
      }
    } else {
      trongTu = false;
    }
  }

  return dem;
}
string removeNumbers(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) {
      for (int t = i; t < s.size(); t++) {
        s[t] = s[t + 1];
      }
      i--;
    }
  }
  return s;
}
void showString(string s) {
  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
  }
}

int main() {
  string s;
  cout << "Nhap xau S:";
  getline(cin, s);
  cout << "So tu cua S:" << countWords(s);
  cout << endl;
  s = removeNumbers(s);
  cout << "Xau S sau khi xoa:";
  showString(s);
}
