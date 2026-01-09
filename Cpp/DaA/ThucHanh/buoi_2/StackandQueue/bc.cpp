#include <iostream>

using namespace std;

int a[20], n;

void print(int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
}

void np(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
            print(n);
        else
            np(i + 1);
    }
}

int main()
{
    cin >> n;
    np(1);
}