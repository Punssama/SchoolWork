#include <iostream>

using namespace std;

typedef struct PhanTu
{
	int msv;
	float DKT;
	PhanTu *Tr;
	PhanTu *Sa;
} PT;

typedef PT *LIST;

/*Khai b�o c�c h�m nguy�n mau tai d�y*/
void KhoiTao(LIST &L);					 // Khoi tao danh sach rong
void ThemDauDS(LIST &L, int m, float d); // Them mot nut moi tai vi tri dau trong danh s�ch tro boi L
void DuyetDS(LIST L);					 // In ra man hinh noi dung cac nut cua danh sach L
void DuyetDS9(LIST L);					 // In ra man hinh c�c SV co diem lon hon 9
int DemSV9(LIST L);						 // Dem xem c� bao nhieu sinh vien co diem lon hon 9
void SapXep(LIST &L);					 // Sap xep danh sach theo thu tu tang dan cua diem

/*Chuong trinh chinh viet tai day*/
int main()
{
	LIST L;
	KhoiTao(L);

	int n;
	cout << "n = ";
	cin >> n;

	int m;
	float d;
	for (int i = 1; i <= n; i++)
	{
		cout << "nhap msv, diem kt cua SV thu " << i << " : ";
		cin >> m >> d;
		ThemDauDS(L, m, d);
	}

	cout << "\nMaSV\tDiemKT\n";
	DuyetDS(L);

	cout << "So sv diem tren 9 la: " << DemSV9(L) << " bao gom:" << endl;
	DuyetDS9(L);

	SapXep(L);
	cout << "Danh sach sau khi sap xep la: " << endl;
	DuyetDS(L);

	return 0;
}

/*Dinh nghia c�c ham tai day */
void KhoiTao(LIST &L)
{
	L = NULL;
}

void ThemDauDS(LIST &L, int m, float d)
{
	LIST P;
	P = new PT;
	P->msv = m;
	P->DKT = d;
	P->Tr = NULL;
	P->Sa = L;

	if (L != NULL)
		L->Tr = P;

	L = P;
}

void DuyetDS(LIST L)
{
	LIST P = L;
	while (P != NULL)
	{
		cout << P->msv << "\t" << P->DKT << endl;
		P = P->Sa;
	}
}

void DuyetDS9(LIST L)
{
	PT *p = L;
	while (p != NULL)
	{
		if (p->DKT > 9)
		{
			cout << p->msv << endl;
		}
		p = p->Sa;
	}
}

int DemSV9(LIST L)
{
	PT *p = L;
	int count = 0;
	while (p != NULL)
	{
		if (p->DKT > 9)
		{
			count++;
		}
		p = p->Sa;
	}
	return count;
}

void SapXep(LIST &L)
{
	LIST sortedList;
	KhoiTao(sortedList);
	PT *min = L;
	while (L != NULL)
	{
		PT *min = L, *minprev = NULL;
		PT *prev = NULL;

		for (PT *i = L; i != NULL; i = i->Sa)
		{
			if (i->DKT < min->DKT)
			{
				min = i;
				minprev = prev;
			}
			prev = i;
		}
		if (minprev == NULL)
		{
			L = L->Sa;
		}
		else
		{
			minprev->Sa = min->Sa;
		}
		min->Sa = NULL;
		if (sortedList == NULL)
		{
			sortedList = min;
		}
		else
		{
			PT *p = sortedList;
			while (p->Sa != nullptr)
			{
				p = p->Sa;
			}
			p->Sa = min;
		}
	}
	L = sortedList;
}
