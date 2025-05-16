/*Cac khai bao */
#include <iostream>
using namespace std;

typedef float Pt;
typedef struct Nt
{
	Pt ND;
	Nt *LK;
} Nut;
typedef Nut *Danh_Sach;

/*Khai báo các hàm nguyên mau tai dây*/
Danh_Sach L_KhoiTao();				  // Khoi tao mot danh sach rong (nul)
void L_HuyBo(Danh_Sach &L);			  // Xoa bo mot danh sach L cho truoc: giai phong bo nho
bool L_KTRong(Danh_Sach L);			  // Kiem tra xem danh sach L co rong (True) hay khong (False)
Pt L_XemPT(Danh_Sach L);			  // lay ra noi dung cua phan tu tai con tro L
void L_ChenPTDau(Danh_Sach &L, Pt X); // Chen them phan tu co noi dung X vao sau vi tri tro boi L
void L_XoaPTDau(Danh_Sach &L, Pt &X); // lay noi dung phan tu sau con tro L, sau do xoa phan tu do khoi danh sach

/*Dinh nghia các ham tai day */

Danh_Sach L_KhoiTao()
{
	return NULL;
}

void L_HuyBo(Danh_Sach &L)
{
	if (L == NULL)
		return;
	Danh_Sach p = L->LK;
	while (p != L)
	{
		Danh_Sach temp = p;
		p = p->LK;
		delete temp;
	}
	delete L;
	L = NULL;
}

bool L_KTRong(Danh_Sach L)
{
	return (L == NULL);
}

Pt L_XemPT(Danh_Sach L)
{
	if (L == NULL)
	{
		cout << "Danh sach rong!" << endl;
		return -1;
	}
	return L->LK->ND;
}

void L_ChenPTDau(Danh_Sach &L, Pt X)
{
	Danh_Sach p = new Nut;
	p->ND = X;
	if (L == NULL)
	{
		p->LK = p;
		L = p;
	}
	else
	{
		p->LK = L->LK;
		L->LK = p;
	}
}

void L_XoaPTDau(Danh_Sach &L, Pt &X)
{
	if (L == NULL)
	{
		cout << "Danh sach rong khong the xoa!" << endl;
		return;
	}
	Danh_Sach p = L->LK;
	X = p->ND;
	if (p == L)
	{
		delete p;
		L = NULL;
	}
	else
	{
		L->LK = p->LK;
		delete p;
	}
}

void L_Print(Danh_Sach L)
{
	if (L == NULL)
	{
		cout << "Danh sach rong!" << endl;
		return;
	}
	Danh_Sach p = L->LK;
	do
	{
		cout << p->ND << " ";
		p = p->LK;
	} while (p != L->LK);
	cout << endl;
}

void L_MoveNext(Danh_Sach &L)
{
	if (L != NULL)
		L = L->LK;
}

Pt L_Back(Danh_Sach L)
{
	if (L != NULL)
		return L->ND;
	return -1;
}

Pt L_Front(Danh_Sach L)
{
	if (L != NULL)
		return L->LK->ND;
	return -1;
}
int main()
{
	Danh_Sach list = L_KhoiTao();
	int n;
	cout << "Nhap so luong phan tu n = ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		Pt x;
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		L_ChenPTDau(list, x);
	}
	cout << "Danh sach: ";
	L_Print(list);

	Pt k;
	cout << "Nhap vao phan tu k: ";
	cin >> k;
	L_ChenPTDau(list, k);
	cout << "Danh sach sau khi chen phan tu " << k << " vao la: ";
	L_Print(list);

	Pt temp;
	L_XoaPTDau(list, temp);
	cout << "Danh sach sau khi xoa la: ";
	L_Print(list);

	cout << "Phan tu tai curson: " << L_Back(list) << endl;
	cout << "Phan tu sau curson: " << L_Front(list) << endl;

	L_HuyBo(list);

	return 0;
}
