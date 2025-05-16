#include <iostream>
#include <iomanip>
using namespace std;
/*Cac khai bao */
typedef float Pt;
typedef struct Nt
{
  Pt ND;
  Nt *LK;
} Nut;
typedef Nut *Hang_Doi;

/*Khai b�o c�c h�m nguy�n mau tai d�y*/
void printQueue(Hang_Doi Q);
Hang_Doi Q_KhoiTao();             // Khoi tao mot hang doi rong (nul)
void Q_HuyBo(Hang_Doi &Q);        // Xoa bo mot hang doi Q cho truoc: giai phong bo nho
bool Q_KTRong(Hang_Doi Q);        // Kiem tra xem hang doi Q co rong (True) hay khong (False)
void Q_DayVao(Hang_Doi &Q, Pt X); // Chen them (day vao) phan tu co noi dung X vao vi tri cuoi cung cua hang doi Q
Pt Q_LayRa(Hang_Doi &Q);          // lay noi dung phan tu dau hang doi Q, sau do xoa phan tu do khoi hang doi

int main()
{ // Chuong trinh chinh de thu nghiem cac ham da viet tai day
  Pt getelem;
  Hang_Doi Q;
  Q = Q_KhoiTao();
  Q_DayVao(Q, 1);
  Q_DayVao(Q, 2);
  Q_DayVao(Q, 3);
  Q_DayVao(Q, 4);
  printQueue(Q);
  getelem = Q_LayRa(Q);
  cout << "Phan tu duoc lay ra la: " << getelem << endl;
  printQueue(Q);
  Q_HuyBo(Q);
  cout << "Hang doi sau khi huy bo la: ";
  printQueue(Q);
};

/*Dinh nghia c�c ham tai day */
void Q_HuyBo(Hang_Doi &Q)
{
  if (Q_KTRong(Q)) // Proper function call
  {
    return;
  }

  while (Q != nullptr)
  {
    Nut *p = Q;
    Q = Q->LK;
    delete p;
  }
}

Hang_Doi Q_KhoiTao()
{
  Hang_Doi queue;
  return queue = nullptr;
}

bool Q_KTRong(Hang_Doi Q)
{
  return Q == nullptr;
}
void Q_DayVao(Hang_Doi &Q, Pt x)
{
  Nut *v = new Nut;
  v->ND = x;
  v->LK = nullptr;
  if (Q == nullptr)
  {
    Q = v;
  }
  else
  {
    Nut *p = Q;
    while (p->LK != nullptr)
    {
      p = p->LK;
    }
    p->LK = v;
  }
}

Pt Q_LayRa(Hang_Doi &Q)
{
  Pt getData;
  getData = Q->ND;
  Nut *old = Q;
  Q = Q->LK;
  delete old;
  return getData;
}

void printQueue(Hang_Doi Q)
{
  if (Q == nullptr)
  {
    cout << "Queue is empty!" << endl;
    return;
  }

  cout << "╔══════╗" << endl;

  Nut *p = Q;
  while (p != nullptr)
  {
    cout << "║  " << setw(2) << p->ND << "   ║";

    if (p == Q)
      cout << "  ← front";
    else if (p->LK == nullptr)
      cout << "  ← rear";

    cout << endl;
    p = p->LK;
  }

  cout << "╚══════╝" << endl;
}
