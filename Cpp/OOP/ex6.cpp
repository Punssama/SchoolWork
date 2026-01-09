#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct HocSinh
{
    string MaHS;
    string HoTenHS;
    string Lop;
    double Diem;
};

void Menu()
{
    cout << "Ban chon: " << endl;
}

void input(HocSinh &hs, vector<HocSinh> &ds)
{
    cout << "Nhap ma hoc sinh: ";
    getline(cin, hs.MaHS);
    for (int i = 0; i < ds.size(); i++)
    {
        if (hs.MaHS == ds[i].MaHS)
        {
            cout << "Khong the them!";
            return;
        }
    }
    cout << "Nhap ten hoc sinh: ";
    getline(cin, hs.HoTenHS);
    cout << "Nhap Lop: ";
    getline(cin, hs.Lop);
    cout << "Nhap diem: ";
    cin >> hs.Diem;
    cin.ignore();
}

void output(HocSinh hs)
{
    cout << endl
         << hs.MaHS << "\t"
         << hs.HoTenHS << "\t"
         << hs.Lop << "\t"
         << hs.Diem << endl;
}

void insertStu(vector<HocSinh> &ds)
{

    HocSinh student;
    input(student, ds);
    if (student.MaHS != "")
    {
        ds.push_back(student);
        cout << "Them thanh cong!";
    }
}

void delStu(vector<HocSinh> &ds)
{
    string ma;
    cout << "Nhap vao ma hoc sinh can xoa: ";
    getline(cin, ma);
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i].MaHS == ma)
            ds.erase(ds.begin() + i);
        cout << "Da xoa thanh cong!" << endl;
    }
}

void searchStu(vector<HocSinh> &ds)
{
    string ma;
    cout << "Nhap vao ma hoc sinh can tim: ";
    getline(cin, ma);
    cout << "MSV\tTEN\tLOP\tDIEM";
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i].MaHS == ma)
        {
            output(ds[i]);
        }
    }
}

void listStuByClass(vector<HocSinh> &ds)
{
    string lop;
    cout << "Nhap lop: ";
    getline(cin, lop);
    cout << "MSV\tTEN\tLOP\tDIEM";
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i].Lop == lop)
        {
            output(ds[i]);
        }
    }
}

void listAllStu(vector<HocSinh> &ds)
{
    cout << "MSV\tTEN\tLOP\tDIEM";
    for (int i = 0; i < ds.size(); i++)
    {
        output(ds[i]);
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
        cout << "4.Liet ke danh sach hoc sinh theo lop" << endl;
        cout << "5.Liet ke danh sach tat ca hoc sinh" << endl;
        cout << "6.Thoat" << endl;
        cout << "Ban chon: ";
        cin >> input;
        getchar();
        switch (input)
        {
        case 1:
            insertStu(danhsach);
            break;
        case 2:
            delStu(danhsach);
            break;
        case 3:
            searchStu(danhsach);
            break;
        case 4:
            listStuByClass(danhsach);
            break;
        case 5:
            listAllStu(danhsach);
            break;

        default:
            break;
        }

    } while (input != 6);
}