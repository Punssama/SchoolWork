#include <string>
#include <iostream>
#include <cctype>
using namespace std;

bool isWord(string s)
{
    bool flag = false;
    int letterCount = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        if (letterCount == 2)
        {
            flag = true;
            break;
        }
        if (isalpha(s[i]))
            letterCount += 1;
    }
    return flag;
}

int main()
{
    string a;
    cout << "Nhap vao mot tu: ";
    getline(cin, a);
    if (isWord(a))
    {
        string s = a.reserve();
        cout << a;
    }
    else
    {
        cout << "notAword";
    }
}