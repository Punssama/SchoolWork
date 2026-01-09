#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sinhvien
{
    string tensv;
    int masv;
    int diem[3];
};

void khoitaoSv(Sinhvien *ptr);
void hienthiSv(Sinhvien *ptr);

int main()
{
    Sinhvien sv;
    Sinhvien *svPtr = &sv;
    khoitaoSv(&sv);
    hienthiSv(svPtr);
}

void khoitaoSv(Sinhvien *ptr)
{
    cout << "Nhap ten sinh vien: ";
    getline(cin, ptr->tensv);
    cout << "Nhap ma sinh vien: ";
    cin >> ptr->masv;
    for (int i = 0; i < 3; i++)
    {
        cout << "Nhap diem mon " << i + 1 << ": ";
        cin >> ptr->diem[i];
    }
}

void hienthiSv(Sinhvien *ptr)
{
    cout << "Ten sinh vien: " << ptr->tensv << endl;
    cout << "Ma sinh vien: " << ptr->masv << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Diem mon " << i + 1 << ": " << ptr->diem[i] << endl;
    }
}
