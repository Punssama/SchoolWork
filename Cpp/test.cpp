#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

void TestCase()
{
  string s;
  cin >> s;
  for (int i = 1; i < s.length(); ++i)
  {
    if (abs(s[i] - s[i - 1]) != 1)
    {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main()
{
  int T;
  cin >> T;
  while (T--)
    TestCase();
  return 0;
}
