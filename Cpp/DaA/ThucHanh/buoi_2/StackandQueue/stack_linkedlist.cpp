/*Cac khai bao */
#include <iostream>
#include <cmath>
using namespace std;

typedef float Pt;
typedef struct Nt
{
	Pt ND;
	Nt *LK;
} Nut;
typedef Nut *Ngan_Xep;

/*Khai báo các hàm nguyên mau tai dây*/
Ngan_Xep S_KhoiTao();			  // Khoi tao mot ngan xep rong (nul)
void V_HuyBo(Ngan_Xep &S);		  // Xoa bo mot ngan xep S cho truoc: giai phong bo nho
bool S_KTRong(Ngan_Xep S);		  // Kiem tra xem ngan xep S co rong (True) hay khong (False)
void S_DayVao(Ngan_Xep &S, Pt X); // Chen them (day vao) phan tu co noi dung X vao vi tri dinh cua ngan xep S
Pt S_LayRa(Ngan_Xep &S);		  // lay noi dung phan tu tren dinh cua ngan xep S, sau do xoa phan tu do khoi ngan xep
void printStack(Ngan_Xep S);

/*viet ham main tai day*/
int main()
{
	Pt getElem;
	Ngan_Xep stack;
	stack = S_KhoiTao();
	S_DayVao(stack, 1);
	S_DayVao(stack, 2);
	S_DayVao(stack, 3);
	S_DayVao(stack, 4);
	S_DayVao(stack, 5);
	printStack(stack);
	getElem = S_LayRa(stack);
	cout << "Phan tu da lay ra: " << getElem << endl;
	cout << "Stack sau khi da lay ra phan tu" << getElem << ": ";
	printStack(stack);
	V_HuyBo(stack);
	return 0;
}

/*Dinh nghia các ham tai day */
Ngan_Xep S_KhoiTao()
{
	Ngan_Xep stack;
	return stack = nullptr;
}

void V_HuyBo(Ngan_Xep &S)
{
	if (S == nullptr)
	{
		return;
	}
	Nut *old;
	while (S != nullptr)
	{
		old = S;
		S = S->LK;
		delete old;
	}
}
bool S_KTRong(Ngan_Xep S)
{
	return S == nullptr;
}

void S_DayVao(Ngan_Xep &S, Pt X)
{
	Nut *newElem = new Nut;
	newElem->ND = X;
	newElem->LK = S;
	S = newElem;
}

Pt S_LayRa(Ngan_Xep &S)
{
	Pt getElem;

	getElem = S->ND;
	Nut *old = S;
	S = S->LK;
	delete old;
	return getElem;
}
void printStack(Ngan_Xep S)
{
	Nut *p = S;
	while (p != nullptr)
	{
		cout << p->ND << " ";
		p = p->LK;
	}
	cout << endl;
}
