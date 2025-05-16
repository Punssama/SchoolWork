#include <iostream>
using namespace std;

/* Các khai báo */
typedef float Pt;
typedef struct Nt
{
	Pt ND;
	Nt *LK_Truoc;
	Nt *LK_Sau;
} Nut;
typedef Nut *Danh_Sach;

/* Khai báo các hàm nguyên mẫu */
Danh_Sach L_KhoiTao();				  // Khởi tạo danh sách rỗng
void L_HuyBo(Danh_Sach &L);			  // Hủy danh sách
bool L_KTRong(Danh_Sach L);			  // Kiểm tra rỗng
Pt L_XemPTDau(Danh_Sach L);			  // Xem phần tử đầu
Pt L_XemPTCuoi(Danh_Sach L);		  // Xem phần tử cuối
void L_ChenPTDau(Danh_Sach &L, Pt X); // Chèn vào đầu
Pt L_XoaPTDau(Danh_Sach &L);		  // Xóa đầu
void L_HienThi(Danh_Sach L);		  // Hiển thị danh sách

/* Định nghĩa các hàm */
Danh_Sach L_KhoiTao()
{
	return NULL;
}

void L_HuyBo(Danh_Sach &L)
{
	while (L != NULL)
	{
		Danh_Sach tmp = L;
		L = L->LK_Sau;
		delete tmp;
	}
}

bool L_KTRong(Danh_Sach L)
{
	return L == NULL;
}

Pt L_XemPTDau(Danh_Sach L)
{
	return L->ND;
}

Pt L_XemPTCuoi(Danh_Sach L)
{
	while (L->LK_Sau != NULL)
		L = L->LK_Sau;
	return L->ND;
}

void L_ChenPTDau(Danh_Sach &L, Pt X)
{
	Danh_Sach newNode = new Nut;
	newNode->ND = X;
	newNode->LK_Truoc = NULL;
	newNode->LK_Sau = L;
	if (L != NULL)
		L->LK_Truoc = newNode;
	L = newNode;
}

Pt L_XoaPTDau(Danh_Sach &L)
{
	if (L == NULL)
		return -1;
	Pt X = L->ND;
	Danh_Sach temp = L;
	L = L->LK_Sau;
	if (L != NULL)
		L->LK_Truoc = NULL;
	delete temp;
	return X;
}

void L_HienThi(Danh_Sach L)
{
	while (L != NULL)
	{
		cout << L->ND << " ";
		L = L->LK_Sau;
	}
	cout << endl;
}

int main()
{
	Danh_Sach list = L_KhoiTao();
	int n;
	cout << "Nhap n =  ";
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		Pt x;
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		L_ChenPTDau(list, x);
	}

	cout << "Danh sach: ";
	L_HienThi(list);

	L_XoaPTDau(list);
	cout << "Danh sach sau khi xoa dau: ";
	L_HienThi(list);

	Pt k;
	cout << "Nhap phan tu muon them vao dau: ";
	cin >> k;
	L_ChenPTDau(list, k);
	cout << "Danh sach sau khi chen " << k << " vao dau: ";
	L_HienThi(list);

	cout << "Phan tu o dau la: " << L_XemPTDau(list) << endl;
	cout << "Phan tu o cuoi la: " << L_XemPTCuoi(list) << endl;

	L_HuyBo(list);
	return 0;
}
