#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void checkCS(string s) {
  int d = 0;
  int arr[100];
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) {
      arr[d] = i;
      d++;
    }
  }
  if (d == 0) {
    cout << "Khong co so trong xau";
  } else {
    cout << "Cac so trong xau la: ";
    for (int i = 0; i < d; i++) {
      cout << s[arr[i]] << " ";
    }
  }
}

using namespace std;

int main() {
  string s;
  getline(cin, s);
  checkCS(s);
}
