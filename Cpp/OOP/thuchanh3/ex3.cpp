#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
protected:
    string tensv;
    int masv;
    char gioitinh;

public:
    SinhVien() : tensv("Nguyen Van A"), masv(1), gioitinh('M') {}
    SinhVien(string t, int m, char gt) : tensv(t), masv(m), gioitinh(gt) {}

    void nhapDL()
    {
        cout << "Nhap ten SV: ";
        getline(cin >> ws, tensv);
        cout << "Nhap ma SV: ";
        cin >> masv;
        cout << "Nhap gioi tinh (M/F): ";
        cin >> gioitinh;
    }

    void hienThi()
    {
        cout << "SV: " << tensv << " | MSV: " << masv << " | Phai: " << gioitinh << endl;
    }

    // Getter/Setter co ban
    string getTen() { return tensv; }
    void setTen(string t) { tensv = t; }
};

class KhoaHoc
{
protected:
    string tenkh;
    int hocky;
    string mucdo;

public:
    KhoaHoc() : tenkh("Ky su Cong nghe thong tin"), hocky(1), mucdo("Trung binh") {}
    KhoaHoc(string t, int hk, string md) : tenkh(t), hocky(hk), mucdo(md) {}

    void nhapDL()
    {
        cout << "Nhap ten khoa hoc: ";
        getline(cin >> ws, tenkh);
        cout << "Nhap hoc ky: ";
        cin >> hocky;
        cout << "Nhap muc do: ";
        cin >> mucdo;
    }

    void hienThi()
    {
        cout << "Khoa hoc: " << tenkh << " | Hoc ky: " << hocky << " | Do kho: " << mucdo << endl;
    }
};

class HocBong : public SinhVien, public KhoaHoc
{
private:
    double giatri;

public:
    HocBong() : SinhVien(), KhoaHoc(), giatri(30000000) {}

    HocBong(string t1, int m, char gt, string t2, int hk, string md, double gtr)
        : SinhVien(t1, m, gt), KhoaHoc(t2, hk, md), giatri(gtr) {}

    void nhapDL()
    {
        SinhVien::nhapDL();
        KhoaHoc::nhapDL();
        cout << "Nhap gia tri hoc bong: ";
        cin >> giatri;
    }

    void hienThi()
    {
        cout << "--- THONG TIN HOC BONG ---" << endl;
        SinhVien::hienThi();
        KhoaHoc::hienThi();
        cout << "Gia tri hoc bong: " << (long long)giatri << " VND" << endl;
    }

    double getGiaTri() { return giatri; }
    void setGiaTri(double g) { giatri = g; }
};

int main()
{
    HocBong hb1;
    cout << "Du lieu mac dinh:" << endl;
    hb1.hienThi();

    cout << "\nNhap du lieu moi cho hoc bong:" << endl;
    HocBong hb2;
    hb2.nhapDL();
    hb2.hienThi();

    return 0;
}