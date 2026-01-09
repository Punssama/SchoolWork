
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
    int soLuongDiem;
    int *diem;
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
    cout << "Nhap so luong diem: ";
    cin >> ptr->soLuongDiem;
    getchar();
    cout << "Nhap ten sinh vien: ";
    getline(cin, ptr->tensv);
    cout << "Nhap ma sinh vien: ";
    cin >> ptr->masv;
    ptr->diem = new int[ptr->soLuongDiem];
    for (int i = 0; i < ptr->soLuongDiem; i++)
    {
        cout << "Nhap vao mot diem: ";
        cin >> ptr->diem[i];
    }
}

void hienthiSv(Sinhvien *ptr)
{
    cout << "Ten sinh vien: " << ptr->tensv << endl;
    cout << "Ma sinh vien: " << ptr->masv << endl;
    for (int i = 0; i < ptr->soLuongDiem; i++)
    {
        cout << "Diem mon " << i + 1 << ": " << ptr->diem[i] << endl;
    }
}
