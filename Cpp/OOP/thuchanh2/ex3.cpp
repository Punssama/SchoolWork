#include <iostream>
#include <cmath>

using namespace std;

int myGCD(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b > 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class HuuTi
{
private:
    int tu;
    int mau;

    void simplify()
    {
        if (mau == 0)
        {
            tu = 0;
            mau = 1;
            return;
        }

        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }

        int ucln = myGCD(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }

public:
    HuuTi() : tu(0), mau(1) {}
    HuuTi(int t) : tu(t), mau(1) {}
    HuuTi(int t, int m) : tu(t), mau(m)
    {
        simplify();
    }

    friend istream &operator>>(istream &is, HuuTi &ht)
    {
        cout << "Nhap tu so: ";
        is >> ht.tu;
        cout << "Nhap mau so: ";
        is >> ht.mau;
        ht.simplify();
        return is;
    }

    friend ostream &operator<<(ostream &os, const HuuTi &ht)
    {
        if (ht.mau == 1)
            os << ht.tu;
        else
            os << ht.tu << "/" << ht.mau;
        return os;
    }

    HuuTi operator+(const HuuTi &other) const
    {
        int tuMoi = tu * other.mau + other.tu * mau;
        int mauMoi = mau * other.mau;
        return HuuTi(tuMoi, mauMoi);
    }

    HuuTi operator-(const HuuTi &other) const
    {
        int tuMoi = tu * other.mau - other.tu * mau;
        int mauMoi = mau * other.mau;
        return HuuTi(tuMoi, mauMoi);
    }

    HuuTi operator*(const HuuTi &other) const
    {
        return HuuTi(tu * other.tu, mau * other.mau);
    }

    HuuTi operator/(const HuuTi &other) const
    {
        return HuuTi(tu * other.mau, mau * other.tu);
    }

    bool operator==(const HuuTi &other) const
    {
        return tu * other.mau == other.tu * mau;
    }

    bool operator<(const HuuTi &other) const
    {
        return tu * other.mau < other.tu * mau;
    }

    bool operator>(const HuuTi &other) const
    {
        return tu * other.mau > other.tu * mau;
    }

    bool operator<=(const HuuTi &other) const
    {
        return !(*this > other);
    }

    bool operator>=(const HuuTi &other) const
    {
        return !(*this < other);
    }
};

int main()
{
    HuuTi a, b;
    cout << "--- Nhap so huu ti A ---\n";
    cin >> a;
    cout << "--- Nhap so huu ti B ---\n";
    cin >> b;

    cout << "\nA = " << a << endl;
    cout << "B = " << b << endl;

    cout << "A + B = " << a + b << endl;
    cout << "A - B = " << a - b << endl;
    cout << "A * B = " << a * b << endl;
    cout << "A / B = " << a / b << endl;

    cout << "\nSo sanh:\n";
    if (a == b)
        cout << "A bang B\n";
    else if (a > b)
        cout << "A lon hon B\n";
    else
        cout << "A nho hon B\n";

    return 0;
}