#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct MucTu
{
    string tuTiengAnh;
    string nghiaTiengViet;
};

struct TuDien
{
    MucTu *table;
    bool *trong;
    int tableSize;
};

string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int hamBam(string tuTiengAnh, int tableSize)
{
    int hashVal = 0;
    tuTiengAnh = toLower(tuTiengAnh);
    for (char c : tuTiengAnh)
        hashVal += c;
    return hashVal % tableSize;
}

void khoiTaoTD(TuDien &td, int size = 101)
{
    td.tableSize = size;
    td.table = new MucTu[size];
    td.trong = new bool[size];
    for (int i = 0; i < size; ++i)
        td.trong[i] = true;
}

void huyTD(TuDien &td)
{
    delete[] td.table;
    delete[] td.trong;
    td.table = nullptr;
    td.trong = nullptr;
    td.tableSize = 0;
}

int timChiSo(TuDien &td, string tu)
{
    tu = toLower(tu);
    int idx = hamBam(tu, td.tableSize);
    int start = idx;
    while (!td.trong[idx])
    {
        if (toLower(td.table[idx].tuTiengAnh) == tu)
            return idx;
        idx = (idx + 1) % td.tableSize;
        if (idx == start)
            break;
    }
    return -1;
}

void chenMucTu(TuDien &td, MucTu mt)
{
    if (timChiSo(td, mt.tuTiengAnh) != -1)
    {
        cout << "Tu da ton tai trong tu dien.\n";
        return;
    }
    string tu = toLower(mt.tuTiengAnh);
    int idx = hamBam(tu, td.tableSize);
    while (!td.trong[idx])
        idx = (idx + 1) % td.tableSize;
    td.table[idx] = mt;
    td.trong[idx] = false;
}

string nghiaTiengViet(TuDien &td, string tuTiengAnh)
{
    int idx = timChiSo(td, tuTiengAnh);
    return (idx != -1) ? td.table[idx].nghiaTiengViet : "";
}

int demSoLuongMucTu(TuDien &td)
{
    int count = 0;
    for (int i = 0; i < td.tableSize; ++i)
        if (!td.trong[i])
            ++count;
    return count;
}

void capNhatNghia(TuDien &td, string tuTA, string nghiaMoi)
{
    int idx = timChiSo(td, tuTA);
    if (idx != -1)
        td.table[idx].nghiaTiengViet = nghiaMoi;
    else
        cout << "Tu khong ton tai.\n";
}

void xoaMucTu(TuDien &td, string tuTA)
{
    int idx = timChiSo(td, tuTA);
    if (idx != -1)
        td.trong[idx] = true;
    else
        cout << "Tu khong ton tai de xoa.\n";
}

int main()
{
    TuDien td;
    khoiTaoTD(td);

    MucTu mt1 = {"computer", "may tinh"};
    MucTu mt2 = {"memory", "bo nho"};
    MucTu mt3 = {"hard disk", "dia cung"};
    MucTu mt4 = {"priority queue", "hang doi uu tien"};

    chenMucTu(td, mt1);
    chenMucTu(td, mt2);
    chenMucTu(td, mt3);
    chenMucTu(td, mt4);

    string tuTA;
    cout << "Nhap tu tieng Anh: ";
    getline(cin, tuTA);

    string nghiaTV = nghiaTiengViet(td, tuTA);
    if (nghiaTV == "")
        cout << "Tu vua nhap khong co trong tu dien\n";
    else
        cout << "Nghia cua tu vua nhap la: " << nghiaTV << endl;

    cout << "So muc tu hien co: " << demSoLuongMucTu(td) << endl;
    huyTD(td);
    return 0;
}