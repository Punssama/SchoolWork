#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Hinh2D
{
protected:
    string mauSac;

public:
    Hinh2D() {};
    virtual void nhap();
    virtual void xuat() const;
    virtual double tinhdientich() = 0;
};
void Hinh2D::xuat() const
{
    cout << "Mau sac cua hinh la: " << mauSac << endl;
}
void Hinh2D::nhap()
{
    cout << "Nhap vao mau: ";
    getline(cin, mauSac);
}

class HinhTron : public Hinh2D
{
private:
    double bankinh;

public:
    HinhTron() {};
    void nhap() override
    {
        Hinh2D::nhap();
        cout << "Nhap vao ban kinh: ";
        cin >> bankinh;
        getchar();
    }

    void xuat() const override
    {
        cout << "----------HinhTron---------" << endl;
        Hinh2D::xuat();
        cout << "Ban kinh hinh tron la: " << bankinh << endl;
    }
    double tinhdientich() override
    {
        return (const double)bankinh * 3.14;
    }
};

class HinhChuNhat : public Hinh2D
{
private:
    double chieudai;
    double chieurong;

public:
    HinhChuNhat() {};
    void nhap() override
    {
        Hinh2D::nhap();
        cout << "Nhap vao chieu dai va chieu rong: ";
        cin >> chieudai >> chieurong;
        getchar();
    }
    void xuat() const override
    {
        cout << "----------HinhChuNhat---------" << endl;
        Hinh2D::xuat();
        cout << "Chieu dai: " << chieudai << endl;
        cout << "Chieu rong: " << chieurong << endl;
    }
    double tinhdientich() override
    {
        return chieudai * chieurong;
    }
};

class HinhTamGiac : public Hinh2D
{
private:
    double a, b, c;

public:
    HinhTamGiac() {};
    void nhap() override
    {
        Hinh2D::nhap();
        cout << "Nhap vao 3 canh cua tam giac: ";
        cin >> a >> b >> c;
        getchar();
    }
    void xuat() const override
    {
        cout << "----------HinhTamGiac---------" << endl;
        Hinh2D::xuat();
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;
    }
    double tinhdientich() override
    {
        double sum = (a + b + c) * (a + b - c) * (b + c - a) * (c + a - b);
        return (double)1 / 4 * (double)1 / 4 * sqrt(sum);
    }
};

const int operator+(Hinh2D &val1, Hinh2D &val2)
{
    return val1.tinhdientich() + val2.tinhdientich();
};
int main()
{
    HinhChuNhat cn1;
    HinhTamGiac tg1;
    HinhTron ht1;
    cn1.nhap();
    cn1.xuat();
    tg1.nhap();
    tg1.xuat();
    ht1.nhap();
    ht1.xuat();
}