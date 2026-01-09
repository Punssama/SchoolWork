#include <iostream>
#include <math.h>
#include <algorithm>
#include <complex>

using namespace std;
class SoPhuc
{
public:
    SoPhuc() {};
    void input();
    void output();
    complex<double> sum();
    complex<double> minus();
    complex<double> divide();
    complex<double> multiply();

private:
    complex<double> a;
    complex<double> b;
};

void SoPhuc::input()
{
    double real1, real2, img1, img2;
    cout << "Nhap so phuc thu 1: ";
    cin >> real1 >> img1;
    a = complex<double>(real1, img1);
    cout << "Nhap so phuc thu 2: ";
    cin >> real2 >> img2;
    b = complex<double>(real2, img2);
}
void SoPhuc::output()
{
    cout << "So phuc thu nhat la: " << a << endl;
    cout << "So phuc thu hai la: " << b << endl;
}

complex<double> SoPhuc::sum()
{
    return a + b;
}
int main()
{
    SoPhuc sp1;
    sp1.input();
    sp1.output();
    cout << "tong 2 so phuc la: " << sp1.sum();
}