// so sphenic
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

void Testcase()
{
  int d = 0, t, rs = 1, flag = 2;
  vector<int> sphenic;

  cin >> t;

  while (t != 1)
  {
    if (d == 4)
    {
      break;
    }
    if (t % flag != 0)
    {
      flag++;
    }
    else
    {
      t /= flag;
      sphenic.push_back(flag);
    }
  }

  if (sphenic.size() == 3 && sphenic[0] != sphenic[1] &&
      sphenic[1] != sphenic[2])
  {
    cout << "1\n";
    return;
  }
  cout << "0\n";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    Testcase();
  }
  return 0;
}
