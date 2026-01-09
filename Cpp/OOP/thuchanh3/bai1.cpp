#include <iostream>
#include <string>
using namespace std;

class HoaDon
{
protected:
    int soLuong;
    double giaCa;

public:
    // Mặc định mua 1 cuốn sách giá 15.5 USD
    HoaDon()
    {
        soLuong = 1;
        giaCa = 15.5;
    }

    HoaDon(int sl, double gc) : soLuong(sl), giaCa(gc) {}

    double tongTien()
    {
        return (double)soLuong * giaCa;
    }

    void setGiaCa(double gc)
    {
        giaCa = gc;
    }

    virtual void inHoaDon()
    {
        cout << ">>> THONG TIN DON HANG <<<" << endl;
        cout << "- So luong sach: " << soLuong << endl;
        cout << "- Don gia: " << giaCa << " USD" << endl;
        cout << "- Tong cong: " << tongTien() << " USD" << endl;
    }
};

class HoaDonKM : public HoaDon
{
private:
    double giamGia;

public:
    // Mặc định giảm 3.5 USD cho khách hàng thân thiết
    HoaDonKM() : HoaDon()
    {
        giamGia = 3.5;
    }

    HoaDonKM(int sl, double gc, double gg) : HoaDon(sl, gc), giamGia(gg) {}

    double thanhToan()
    {
        return tongTien() - giamGia;
    }

    void inHoaDon() override
    {
        HoaDon::inHoaDon();
        cout << "- Voucher giam gia: -" << giamGia << " USD" << endl;
        cout << "=> SO TIEN PHAI TRA: " << thanhToan() << " USD" << endl;
    }
};

int main()
{
    HoaDonKM h1(3, 12.0, 5.0);
    h1.inHoaDon();
    return 0;
}