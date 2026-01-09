

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
    ~Sinhvien()
    {
        delete[] diem;
    }
};

void khoitaoSv(Sinhvien *ptr);
void hienthiSv(Sinhvien *ptr);

int main()
{
    int soLuongSv, maSvXoa;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuongSv;
    Sinhvien *lop = new Sinhvien[soLuongSv];
    getchar();
    for (int i = 0; i < soLuongSv; ++i)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        khoitaoSv(&lop[i]);
    }
    for (int i = 0; i < soLuongSv; ++i)
    {
        cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
        hienthiSv(&lop[i]);
        cout << endl;
    }

    cout << "nhap vao sinh vien can xoa: ";
    cin >> maSvXoa;
    for (int i = 0; i < soLuongSv; ++i)
    {
        if ((lop + i)->masv == maSvXoa)
        {
            for (int j = i; j < soLuongSv - 1; ++j)
            {
                lop[j] = lop[j + 1];
            }

            soLuongSv--;
        }
    }
    for (int i = 0; i < soLuongSv; ++i)
    {
        cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
        hienthiSv(&lop[i]);
        cout << endl;
    }

    delete[] lop;
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
