
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

// ex1
class TamGiac
{
public:
    TamGiac() {};
    void checkType();
    void input();
    void output();

private:
    double a, b, c;
};

void TamGiac::input()
{
    cout << "Nhap vao canh a: ";
    cin >> a;
    cout << "Nhap vao canh b: ";
    cin >> b;
    cout << "Nhap vao canh c: ";
    cin >> c;
}
void TamGiac::output()
{
    cout << "3 canh cua tam giac la:" << a << ", " << b << ", " << c << endl;
}

void TamGiac::checkType()
{
    if (a + b > c && a + c > b && b + c > a)
    {

        if (a == b && a == c || b == c && b == a || c == a && c == b)
        {
            cout << "Day la tam giac can";
        }
        else if (a == b && a == c && c == b)
        {
            cout << "Day la tam giac can";
        }
        else
        {
            cout << "Day la tam giac thuong";
        }
    }
    else
    {
        cout << "Day khong phai tam giac";
    }
}

int main()
{
    TamGiac tg1;
    tg1.input();
    tg1.output();
    tg1.checkType();
}