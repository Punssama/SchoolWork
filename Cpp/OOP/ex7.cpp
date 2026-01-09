#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HocSinh
{
public:
    HocSinh() {};
    void hienthi();
    void nhap(vector<HocSinh> &ds);
    double getDiem() { return Diem; };
    string getMaHS() { return MaHS; };
    string getLop() { return Lop; };

private:
    string MaHS;
    string HotenHS;
    string Lop;
    double Diem;
};

void HocSinh::nhap(vector<HocSinh> &ds)
{
    cout << "Nhap vao ma sinh vien: ";
    getline(cin, MaHS);
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i].MaHS == MaHS)
        {
            cout << "Hoc sinh da ton tai!";
            return;
        }
    }
    cout << "Nhap ten: ";
    getline(cin, HotenHS);
    cout << "Nhap lop: ";
    getline(cin, Lop);
    cout << "Nhap diem: ";
    cin >> Diem;
    cin.ignore();
}

void HocSinh::hienthi()
{
    cout << MaHS << "\t"
         << HotenHS << "\t"
         << Lop << "\t" << Diem << endl;
}

void insert(vector<HocSinh> &ds)
{
    HocSinh hs;
    hs.nhap(ds);
    ds.push_back(hs);
    cout << "Them thanh cong!" << endl;
}

void del(vector<HocSinh> &ds)
{
    string ma;
    cout << "Nhap vao ma sinh vien: ";
    getline(cin, ma);
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i].getMaHS() == ma)
        {
            ds.erase(ds.begin() + i);
            cout << "Xoa thanh cong!";
        }
    }
}

void findStuByID(vector<HocSinh> &ds)
{
    string ma;
    cout << "Nhap vao ma sinh vien: ";
    getline(cin, ma);
    cout << "MSV\tTEN\tLOP\tDIEM";
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i].getMaHS() == ma)
        {
            ds[i].hienthi();
        }
    }
}

void listStuByMark(vector<HocSinh> &ds)
{
    for (int i = 0; i < ds.size(); i++)
    {
        cout << "MSV\tTEN\tLOP\tDIEM";
        if (ds[i].getDiem() > 5.5)
        {
            ds[i].hienthi();
        }
    }
}

void listStuByClass(vector<HocSinh> &ds)
{
    string lop;
    cout << "Nhap vao lop: ";
    getline(cin, lop);
    for (int i = 0; i < ds.size(); i++)
    {
        cout << "MSV\tTEN\tLOP\tDIEM";
        if (ds[i].getLop() == lop)
        {
            ds[i].hienthi();
        }
    }
}
void listAllStu(vector<HocSinh> &ds)
{
    for (HocSinh hs : ds)
    {
        hs.hienthi();
    }
}

int main()
{
    vector<HocSinh> danhsach;
    int input;
    do
    {
        cout << "\n1.Them moi hoc sinh" << endl;
        cout << "2.Xoa hoc sinh khoi danh sach" << endl;
        cout << "3.Tim kiem hoc sinh theo ma" << endl;
        cout << "4.Liet ke danh sach hoc sinh co diem tren 5.5" << endl;
        cout << "5.Liet ke danh sach hoc sinh theo lop" << endl;
        cout << "6.Liet ke danh sach tat ca hoc sinh" << endl;
        cout << "7.Thoat" << endl;
        cout << "Ban chon: ";
        cin >> input;
        getchar();

        switch (input)
        {
        case 1:
            insert(danhsach);
            break;
        case 2:
            del(danhsach);
            break;
        case 3:
            findStuByID(danhsach);
            break;
        case 4:
            listStuByMark(danhsach);
            break;
        case 5:
            listStuByClass(danhsach);
            break;
        case 6:
            listAllStu(danhsach);
            break;

        default:
            break;
        }

    } while (input != 7);
}