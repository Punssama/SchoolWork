#include <iostream>
#include <string>
using namespace std;

double aver(string s) {
  double d = 0, rs = 0;

  for (int i = 0; i < s.size(); i++) {
    if ((s[i] - '0') % 2 == 0) {
      d++;
      rs += (s[i] - '0');
    }
  }
  return rs / d;
}

void print(string s) {
  for (int i = 0; i < s.size(); i++)
    cout << s[i];
}

int main() {
  string s;
  cout << "Nhap vao xau s: ";
  getline(cin, s);
  cout << "xau: ";
  print(s);
  cout << endl;
  cout << "TBC cac so chan trong xau: " << aver(s);
}
