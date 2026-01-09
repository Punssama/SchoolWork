#include <iostream>

using namespace std;

class SoPhuc
{
private:
    float thuc;
    float ao;

public:
    SoPhuc(float r = 0, float i = 0) : thuc(r), ao(i) {}

    float getThuc() const { return thuc; }
    float getAo() const { return ao; }

    SoPhuc operator+(const SoPhuc &other) const
    {
        return SoPhuc(thuc + other.thuc, ao + other.ao);
    }

    SoPhuc operator-(const SoPhuc &other) const
    {
        return SoPhuc(thuc - other.thuc, ao - other.ao);
    }

    SoPhuc operator*(const SoPhuc &other) const
    {
        return SoPhuc(thuc * other.thuc - ao * other.ao,
                      thuc * other.ao + ao * other.thuc);
    }

    SoPhuc operator/(const SoPhuc &other) const
    {
        float mau = other.thuc * other.thuc + other.ao * other.ao;
        if (mau == 0)
        {
            return SoPhuc();
        }
        float thucMoi = (thuc * other.thuc + ao * other.ao) / mau;
        float aoMoi = (ao * other.thuc - thuc * other.ao) / mau;
        return SoPhuc(thucMoi, aoMoi);
    }

    friend istream &operator>>(istream &is, SoPhuc &sp)
    {
        cout << "Nhap phan thuc: ";
        is >> sp.thuc;
        cout << "Nhap phan ao: ";
        is >> sp.ao;
        return is;
    }

    friend ostream &operator<<(ostream &os, const SoPhuc &sp)
    {
        os << sp.thuc;
        if (sp.ao >= 0)
            os << " + " << sp.ao << "i";
        else
            os << " - " << -sp.ao << "i";
        return os;
    }
};

int main()
{
    SoPhuc sp1, sp2;

    cout << "--- Nhap So Phuc 1 ---\n";
    cin >> sp1;
    cout << "--- Nhap So Phuc 2 ---\n";
    cin >> sp2;

    cout << "\nSP1: " << sp1 << endl;
    cout << "SP2: " << sp2 << endl;

    cout << "Tong: " << sp1 + sp2 << endl;
    cout << "Hieu: " << sp1 - sp2 << endl;
    cout << "Tich: " << sp1 * sp2 << endl;
    cout << "Thuong: " << sp1 / sp2 << endl;

    return 0;
}