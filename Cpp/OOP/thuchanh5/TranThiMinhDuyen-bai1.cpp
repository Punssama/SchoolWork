#include <iostream>
using namespace std;

class DongVat
{
protected:
    double canNang;

public:
    DongVat() {};
    DongVat(double w)
    {
        canNang = w;
    }
    virtual void inDL() const
    {
        cout << "Can nang cua dong vat la: " << canNang << endl;
    }
};

class SuTu : public DongVat
{
private:
    double tocDo;

public:
    SuTu() {};
    SuTu(double w, double s) : DongVat(w)
    {
        tocDo = s;
    }

    void inDL() const override

    {
        cout << "Can nang cua su tu la: " << canNang << endl;
        cout << "Toc do cua su tu la: " << tocDo << endl;
    }
};

class TranNuoc : public DongVat
{
private:
    double chieudai;

public:
    TranNuoc() {};
    TranNuoc(double w, double t) : DongVat(w)
    {
        chieudai = t;
    };
    void inDL() const override
    {
        cout << "Can nang cua tran nuoc la: " << canNang << endl;
        cout << "Chieu dai cua tran nuoc la: " << chieudai << endl;
    }
};

int main()
{
    SuTu s1(100, 50);
    TranNuoc t1(100, 5);
    DongVat *dv1;
    dv1 = &s1;
    s1.inDL();
    t1.inDL();
    dv1->inDL();
}