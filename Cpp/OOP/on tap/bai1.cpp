#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class VIENCHUC
{
protected:
    string mvc, hoten;
    int namsinh;
    double HSL;

public:
    VIENCHUC() {};
    void set();
    void print() const;
    virtual double salary() = 0;
};

void VIENCHUC::set()
{
    cout << "Nhap vao ma vien chuc: ";
    getline(cin, mvc);
    cout << "Nhap vao ten vien chuc: ";
    getline(cin, hoten);
    cout << "Nhap vao nam sinh: ";
    cin >> namsinh;
    cout << "Nhap vao he so luong: ";
    cin >> HSL;
    getchar();
}
void VIENCHUC::print() const
{
    cout << "Thong tin cua vien chuc: " << endl
         << "MA VIEN CHUC: " << mvc << endl
         << "Ho va ten: " << hoten << endl
         << "Nam sinh: " << namsinh << endl;
}
class CBHANHCHINH : public VIENCHUC
{
private:
    string chucdanh;
    double phucap;

public:
    CBHANHCHINH()
    {
        chucdanh = "";
        phucap = 0;
    }
    void set()
    {
        VIENCHUC::set();
        cout << "Nhap vao chuc danh: ";
        getline(cin, chucdanh);
        cout << "Nhap vao phu cap: ";
        cin >> phucap;
        getchar();
    }

    double salary() override
    {
        return HSL * 2000 + phucap;
    }
    void print()
    {
        VIENCHUC::print();
        cout << "Chuc danh: " << chucdanh << endl;
        cout << "Luong thang: " << salary() << endl;
    }
};

class GIAOVIEN : public VIENCHUC
{
private:
    string monday;
    int thamnien;

public:
    GIAOVIEN()
    {
        monday = "";
        thamnien = 0;
    };
    void set()
    {
        VIENCHUC::set();
        cout << "Nhap vao mon day: ";
        getline(cin, monday);
        cout << "Nhap vao so nam day: ";
        cin >> thamnien;
        getchar();
    }
    double salary() override
    {
        return round(HSL * 2000000 * (130 + thamnien) / 100);
    }
    void print()
    {
        VIENCHUC::print();
        cout << "Mon day: " << monday << endl;
        cout << "Tham nien: " << thamnien << endl;
        cout << "Luong thang: " << fixed << salary() << endl;
    }
};

void nhapdulieu()
{
    vector<VIENCHUC *> professions;
    int numbers;
    int selection;
    cout << "Nhap vao so luong vien chuc: ";
    cin >> numbers;
    do
    {
        cout << "(1) Giao vien" << endl
             << "(2) Can bo hanh chinh" << endl
             << "(3) show thong tin vien chuc" << endl
             << "(0) EXIT" << endl
             << "Nhap vao lua chon: ";
        cin >> selection;
        getchar();
    } while (selection < 0 && selection > 3);
    if (selection == 1)
    {
        GIAOVIEN *gv = new GIAOVIEN();
        gv->set();
        professions.push_back(gv);
    }
    else if (selection == 2)
    {
        CBHANHCHINH *cbhc = new CBHANHCHINH();
        cbhc->set();
        professions.push_back(cbhc);
    }
    else if (selection == 3)
    {
        if (professions.size() == 0)
        {
            cout << "Khong co vien chuc de hien thi!";
            return;
        }
        else
        {
            for (VIENCHUC *vc : professions)
            {
                if (typeid(vc) == typeid(GIAOVIEN))
                {
                    cout << "------GIAOVIEN------" << endl;
                    vc->print();
                }
                else if (typeid(vc) == typeid(CBHANHCHINH))
                {
                    cout << "------CBHC------" << endl;
                    vc->print();
                }
            }
        }
    }
    else
    {
        return;
    }
}

int main()
{
    nhapdulieu();
}