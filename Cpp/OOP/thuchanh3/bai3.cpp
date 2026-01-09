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
    SinhVien() : tensv("Student A"), masv(1001), gioitinh('F') {}
    SinhVien(string t, int m, char gt) : tensv(t), masv(m), gioitinh(gt) {}

    void nhapDL()
    {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, tensv);
        cout << "Nhap ma so: ";
        cin >> masv;
        cout << "Nhap gioi tinh (M/F): ";
        cin >> gioitinh;
    }

    void hienThi()
    {
        cout << "Hoc vien: " << tensv << " (ID: " << masv << ") [" << gioitinh << "]" << endl;
    }

    // Các hàm truy cập
    string getTen() { return tensv; }
    int getMa() { return masv; }
    char getGioiTinh() { return gioitinh; }
};

class KhoaHoc
{
protected:
    string tenkh;
    int hocky;
    string mucdo;

public:
    KhoaHoc() : tenkh("Data Science 101"), hocky(2), mucdo("Advanced") {}
    KhoaHoc(string t, int hk, string md) : tenkh(t), hocky(hk), mucdo(md) {}

    void nhapDL()
    {
        cout << "Ten khoa hoc: ";
        getline(cin >> ws, tenkh);
        cout << "Hoc ky: ";
        cin >> hocky;
        cout << "Muc do (Basic/Advanced): ";
        cin >> mucdo;
    }

    void hienThi()
    {
        cout << "Khoa: " << tenkh << " | Ky: " << hocky << " | Level: " << mucdo << endl;
    }
};

class HocBong : public SinhVien, public KhoaHoc
{
private:
    double giatri;

public:
    HocBong() : SinhVien(), KhoaHoc(), giatri(50000000) {}

    HocBong(string t1, int m, char gt, string t2, int hk, string md, double gtr)
        : SinhVien(t1, m, gt), KhoaHoc(t2, hk, md), giatri(gtr) {}

    void nhapDL()
    {
        cout << "--- NHAP THONG TIN XET HOC BONG ---" << endl;
        SinhVien::nhapDL();
        KhoaHoc::nhapDL();
        cout << "Gia tri hoc bong cap: ";
        cin >> giatri;
    }

    void hienThi()
    {
        cout << "\n====================================" << endl;
        cout << "        CHUNG NHAN HOC BONG         " << endl;
        SinhVien::hienThi();
        KhoaHoc::hienThi();
        cout << "SO TIEN HO TRO: " << (long long)giatri << " VNĐ" << endl;
        cout << "====================================" << endl;
    }
};

int main()
{
    HocBong hb("Le Van Luyen", 2024, 'M', "Machine Learning", 1, "Hard", 15000000);
    hb.hienThi();
    return 0;
}