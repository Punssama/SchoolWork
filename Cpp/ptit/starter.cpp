#include <iostream>
using namespace std;
int ktra(int n)
{
    int k;
    while (n > 0)
    {
        k = n % 10;
        if (k == 6 || k == 8 || k == 0)
            n /= 10;
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (ktra(n) == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}