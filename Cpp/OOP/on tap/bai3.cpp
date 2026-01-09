#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class NGUOI
{
protected:
    string maN, hoten, maDV;
    int namSinh;
    double heSoLuong;

public:
    NGUOI() {};
    NGUOI(string maN, string hoten, string maDV, int namSinh, double heSoLuong)
    {
        this->maN = maN;
        this->hoten = hoten;
        this->maDV = maDV;
        this->namSinh = namSinh;
        this->heSoLuong = heSoLuong;
    }
    virtual void nhap()
    {
        cout << "Nhap vao ma nguoi: ";
        getline(cin, maN);
        cout << "Nhap vao ho ten: ";
        getline(cin, hoten);
        cout << "Nhap vao nam sinh";
        cin >> namSinh;
        cout << "Nhap vao he so luong: ";
        cin >> heSoLuong;
        getchar();
    }
    virtual void xuat() const
    {
        cout << "Ma nguoi: " << maN << endl
             << "Ho va ten: " << hoten << endl
             << "Nam sinh: " << namSinh << endl
             << "He so luong: " << heSoLuong << endl;
    }
    friend ostream &operator<<(ostream &os, const NGUOI &n)
    {
        n.xuat();
        return os;
    };
    friend istream &operator>>(istream &is, NGUOI &n)
    {
        n.nhap();
        return is;
    };
    friend bool operator<(const NGUOI val1, const NGUOI val2)
    {
        return true;
    };
    virtual ~NGUOI() {};
};

class GIANGVIEN : public NGUOI
{
private:
    string monday;
    int soGioDayTrenThang;
    int soBaiBao;

public:
    GIANGVIEN() {};
    GIANGVIEN(string maN, string hoten, string maDV, int namSinh,
              double heSoLuong, string monday, int soGioDayTrenThang, int soBaiBao)
        : NGUOI(maN, hoten, maDV, namSinh, heSoLuong)
    {
        this->monday = monday;
        this->soGioDayTrenThang = soGioDayTrenThang;
        this->soBaiBao = soBaiBao;
    };
    double luongThang() const
    {
        double phuCapDungLop = (25 * 1200) / 100;
        return soGioDayTrenThang * 200 + phuCapDungLop;
    };

    void nhap() override
    {
        NGUOI::nhap();
        cout << "Nhap mon day: ";
        cin >> monday;
        cout << "Nhap soGioDayTrenThang: ";
        cin >> soGioDayTrenThang;
        cout << "Nhap so bai bao: ";
        cin >> soBaiBao;
        getchar();
    }

    void xuat() const override
    {
        NGUOI::xuat();
        cout << "Mon day: " << monday << endl;
        cout << "So gio day tren thang: " << soGioDayTrenThang << endl;
        cout << "So bai bao: " << soBaiBao << endl;
        cout << "Luong thang: " << luongThang() << endl;
    }

    friend double operator+(const GIANGVIEN &val1, const GIANGVIEN &val2)
    {
        return val1.luongThang() + val2.luongThang();
    };
    ~GIANGVIEN() {};
};

class SINHVIEN : public NGUOI
{
private:
    string monhoc;
    int soTinChi;
    double diemQuaTrinh;

public:
    SINHVIEN() {};
    SINHVIEN(string maN, string hoten, string maDV, int namSinh,
             double heSoLuong, string monhoc, int soTinChi, double diemQuaTrinh)
        : NGUOI(maN, hoten, maDV, namSinh, heSoLuong)

    {
        this->monhoc = monhoc;
        this->soTinChi = soTinChi;
        this->diemQuaTrinh = diemQuaTrinh;
    }
    double getDQT()
    {
        return diemQuaTrinh;
    }
    void nhap() override
    {
        NGUOI::nhap();
        cout << "Nhap vao mon hoc: ";
        getline(cin, monhoc);
        cout << "Nhap vao so tin chi: ";
        cin >> soTinChi;
        cout << "Nhap vao diem qua trinh: ";
        cin >> diemQuaTrinh;
        getchar();
    }
    ~SINHVIEN() {};
};

int main()
{
    vector<NGUOI *> ds;
    int n, i = 0, selection;
    do
    {
        cout << "Nhap vao so nguoi: ";
        cin >> n;
        getchar();
    } while (n < 0 && n > 100);
    while (i < n)
    {
        cout << "(1) Giang vien" << endl
             << "(2) Sinh vien" << endl
             << "Nhap vao lua chon: ";
        cin >> selection;
        getchar();
        if (selection == 1)
        {
            GIANGVIEN *gv = new GIANGVIEN();
            gv->nhap();
            ds.push_back(gv);
            i++;
        }
        else if (selection == 2)
        {
            SINHVIEN *sv = new SINHVIEN();
            sv->nhap();
            ds.push_back(sv);
            i++;
        }
        else
        {
            cout << "Khong hop le!";
            break;
        }
    }
    for (int i = 0; i < ds.size(); ++i)
    {
        for (int j = i + 1; j < ds.size(); ++j)
        {
            if (typeid(*ds[i]) == typeid(GIANGVIEN) && typeid(*ds[j]) == typeid(GIANGVIEN))
            {
                GIANGVIEN *gv1 = dynamic_cast<GIANGVIEN *>(ds[i]);
                GIANGVIEN *gv2 = dynamic_cast<GIANGVIEN *>(ds[j]);
                if (gv2->luongThang() > gv1->luongThang())
                {
                    NGUOI *tmp = ds[i];
                    ds[i] = ds[j];
                    ds[j] = tmp;
                }
            }
        }
    }
    for (NGUOI *x : ds)
    {
        if (typeid(*x) == typeid(GIANGVIEN))
        {
            x->xuat();
        }
    }
    cout << "SINH VIEN CAM THI: " << endl;
    for (NGUOI *x : ds)
    {
        if (typeid(*x) == typeid(SINHVIEN))
        {
            SINHVIEN *sv = dynamic_cast<SINHVIEN *>(x);
            if (sv->getDQT() < 4)
            {
                sv->xuat();
            }
        }
    }

    for (NGUOI *x : ds)
    {
        delete x;
    }
}