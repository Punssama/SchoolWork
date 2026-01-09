#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class SANPHAM
{
private:
    string ten;
    string nsx;

public:
    SANPHAM()
    {
        ten = "";
        nsx = "";
    }
    SANPHAM(string tenSP, string tenNSX)
    {
        ten = tenSP;
        nsx = tenNSX;
    }
    virtual ~SANPHAM() {};
    void set()
    {
        cout << "Nhap ten san pham: ";
        getline(cin, ten);
        cout << "Nhap nam san xuat: ";
        getline(cin, nsx);
    }
    virtual void print() const
    {
        cout << "Ten san pham: " << ten << endl;
        cout << "Nha san xuat: " << nsx << endl;
    }
};

class BANLE : public SANPHAM
{
private:
    double giaBanLe;
    int soLuong;

public:
    BANLE() {};
    BANLE(string const tenSP, string const tenNSX, double giaBan, int soLuongTon)
        : SANPHAM(tenSP, tenNSX) {};

    void set()
    {
        SANPHAM::set();
        do
        {
            /* code */
            cout << "Nhap vao so luong(<10): ";
            cin >> soLuong;
        } while (soLuong >= 10);
        cout << "Nhap vao gia ban le: ";
        cin >> giaBanLe;
    }

    void print() const override
    {
        SANPHAM::print();
        cout << "So luong: " << soLuong << endl;
        cout << "Gia ban le: " << giaBanLe << endl;
    }

    double ThanhToan()
    {
        return giaBanLe * soLuong;
    }
};

class BANSI : public SANPHAM
{
private:
    double giaBanSi;
    int soLuong;

public:
    BANSI() {};
    BANSI(string const tenSP, string const tenNSX, double giaBan, int soLuongTon)
        : SANPHAM(tenSP, tenNSX) {};

    void set()
    {
        SANPHAM::set();
        do
        {
            /* code */
            cout << "Nhap vao so luong(>100): ";
            cin >> soLuong;
        } while (soLuong <= 100);
        cout << "Nhap vao gia ban si: ";
        cin >> giaBanSi;
    }

    void print() const override
    {
        SANPHAM::print();
        cout << "So luong: " << soLuong << endl;
        cout << "Gia ban le: " << giaBanSi << endl;
    }

    double ThanhToan()
    {
        return giaBanSi * soLuong;
    }
};
int main()
{
    int products;
    vector<SANPHAM *> sp;
    cout << "Nhap vao so san pham: ";
    cin >> products;
    getchar();
    for (int i = 0; i < products; ++i)
    {
        int typeOSale;
        cout << "(1)Ban le" << endl
             << "(2)Ban si" << endl
             << "Lua chon: ";
        cin >> typeOSale;
        getchar();
        if (typeOSale == 1)
        {
            BANLE *bl = new BANLE();
            bl->set();
            sp.push_back(bl);
        }
        else if (typeOSale == 2)
        {
            BANSI *bs = new BANSI();
            bs->set();
            sp.push_back(bs);
        }
        else
        {
            cout << "Lua chon khong hop le!";
        }
    }
    for (SANPHAM *x : sp)
    {
        x->print();
    }
}