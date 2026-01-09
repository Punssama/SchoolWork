#include <iostream>
#include <string>

using namespace std;

class HoaDon
{
protected:
    string maHang;
    int soLuong;
    double giaCa;

public:
    HoaDon()
    {
        soLuong = 1;
        giaCa = 10.0;
    }
    HoaDon(int sl, double gc)
    {
        soLuong = sl;
        giaCa = gc;
    }
    double tongTien()
    {
        return soLuong * giaCa;
    };
    void setGiaCa(double gc)
    {
        giaCa = gc;
    }
    void setSoLuong(int sl)
    {
        soLuong = sl;
    }
    void inHoaDon()
    {
        cout << "So luong: " << soLuong << endl;
        cout << "Gia ca: " << giaCa << endl;
        cout << "Tong tien: " << tongTien() << endl;
    }
    friend const HoaDon operator+(const HoaDon &hd1, const HoaDon &hd2)
    {
        HoaDon result;
        result.soLuong = hd1.soLuong + hd2.soLuong;
        result.giaCa = hd1.giaCa + hd2.giaCa;
        return result;
    }
    friend bool operator==(const HoaDon &hd1, const HoaDon &hd2)
    {
        return (hd1.soLuong == hd2.soLuong && hd1.giaCa == hd2.giaCa) ? true : false;
    }
};

class HoaDonKM : public HoaDon
{
private:
    double giamGia;

public:
    HoaDonKM() : HoaDon(1, 10.0) {};
    HoaDonKM(int sl, double gc, double gg)
    {
        soLuong = sl;
        giaCa = gc;
        giamGia = gg;
    }
    double thanhToan()
    {
        return tongTien() - giamGia;
    }
    void inHoaDon()
    {
        cout << "Tong tien: " << tongTien() << endl;
        cout << "Tong tien sau KM: " << thanhToan() << endl;
        cout << "Giam gia: " << giamGia << endl;
    }
};

int main()
{
    cout << "Hoa don thuong: " << endl;
    HoaDon hd1;
    hd1.setGiaCa(20.0);
    hd1.setSoLuong(3);
    hd1.inHoaDon();

    cout << "\nHoa don khuyen mai: " << endl;
    HoaDonKM hd2(2, 15.0, 5.0);
    hd2.inHoaDon();
}