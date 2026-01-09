#include <iostream>
using namespace std;
/*Cac khai bao */
typedef char Pt;
typedef struct Nt
{
  Pt ND;
  Nt *LK_Trai;
  Nt *LK_Phai;
} Nut;
typedef Nut *BieuThuc;

/*Khai b�o c�c h�m nguy�n mau tai d�y*/
BieuThuc KhoiTao(); // Khoi tao mot cay nhi phan BT rong (nul)
void ThemNutLa(BieuThuc &B, Pt X);
void TaoCayBT(BieuThuc &B, Pt *X, int n, int i);
void DuyetCay(BieuThuc B);

/*Chuong trinh chinh*/
int main()
{
  BieuThuc B = KhoiTao();

  Pt X[] = {'B', '*', '+', '7', '8', '-', 'B', 'B', 'B', 'B', '6', '4'};
  int n = 11, i = 1;
  TaoCayBT(B, X, n, i);

  cout << "Bieu thuc trung to la:" << endl;
  DuyetCay(B);

  return 0;
};

/*Dinh nghia c�c ham tai day */
BieuThuc KhoiTao()
{
  return (NULL);
};

void ThemNutLa(BieuThuc &B, Pt X)
{
  B = new Nut;
  B->LK_Phai = NULL;
  B->LK_Trai = NULL;
  B->ND = X;
};

void TaoCayBT(BieuThuc &B, Pt *X, int n, int i)
{
  ThemNutLa(B, X[i]);
  if ((X[i * 2] != 'B') && (i * 2 <= n))
    TaoCayBT(B->LK_Trai, X, n, i * 2);
  if ((X[i * 2 + 1] != 'B') && (i * 2 + 1 <= n))
    TaoCayBT(B->LK_Phai, X, n, i * 2 + 1);
};

void DuyetCay(BieuThuc B)
{
  if (B != NULL)
  {
    bool dau = (B->LK_Phai != NULL || B->LK_Trai != NULL);
    if (dau)
    {
      cout << "(";
    }
    DuyetCay(B->LK_Trai);
    cout << B->ND;
    DuyetCay(B->LK_Phai);
    if (dau)
    {
      cout << ")";
    }
  }
}
