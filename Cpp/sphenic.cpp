// so sphenic
#include <iostream>
#define endl '\n'
using namespace std;

void Testcase() {
  int d = 0, t, rs = 1, flag = 2;

  cin >> t;

  while (t != 1) {
    if(d == 4){
      break;
    }
    if (t % flag != 0) {
      flag++;
    } else {
      t /= flag;
      d++;
    }
  }

  if (d == 3) {
    cout << "1\n";
    return;
  }
 cout << "0\n";
  
}

int main() {
  int t;
  cin >> t;
  while(t--){
  Testcase();
  }
  return 0;
}
