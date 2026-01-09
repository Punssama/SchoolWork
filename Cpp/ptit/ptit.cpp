#include <iostream>
using namespace std;
void testcase()
{
    int n;
    int check = 0;
    cin >> n;
    int k;
    while (n > 0)
    {

        k = n % 10;
        if (k == 6 || k == 8 || k == 0)
        {
            n /= 10;
        }
        else
        {

            check = 1;
            break;
        }
    }
    if (check == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        testcase();
    }
    return 0;
}