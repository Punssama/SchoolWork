#include <iostream>
using namespace std;

/*Cac khai bao */
typedef float Pt;

typedef struct Nt
{
  Pt ND;
  Nt *LK_Trai;
  Nt *LK_Phai;
} Nut;

typedef Nut *Tree;

/*Khai báo các hàm nguyên mẫu */
Tree T_KhoiTao();                // Khởi tạo cây rỗng
void T_XoaNutLa(Tree &T);        // Xoá 1 nút lá
void T_ThemNutLa(Tree &T, Pt X); // Thêm nút lá
void T_HuyBo(Tree &T);           // Hủy cây
bool T_KTRong(Tree T);           // Kiểm tra rỗng
bool T_KTTonTai(Tree T, Pt X);   // Kiểm tra tồn tại
void T_ThemNut(Tree &T, Pt X);   // Thêm nút
void T_XoaNut(Tree &T, Pt X);    // Xóa nút
void T_LNR(Tree T);              // Duyệt giua

/* Định nghĩa các hàm */

Tree T_KhoiTao() { return NULL; }

bool T_KTRong(Tree T) { return T == NULL; }

void T_XoaNutLa(Tree &T)
{
  delete T;
  T = NULL;
}

void T_ThemNutLa(Tree &T, Pt X)
{
  T = new Nut;
  T->ND = X;
  T->LK_Trai = NULL;
  T->LK_Phai = NULL;
}

bool T_KTTonTai(Tree T, Pt X)
{
  if (T == NULL)
    return false;
  if (T->ND == X)
    return true;
  if (X < T->ND)
    return T_KTTonTai(T->LK_Trai, X);
  else
    return T_KTTonTai(T->LK_Phai, X);
}

void T_ThemNut(Tree &T, Pt X)
{
  if (T == NULL)
  {
    T_ThemNutLa(T, X);
  }
  else if (X < T->ND)
  {
    T_ThemNut(T->LK_Trai, X);
  }
  else if (X > T->ND)
  {
    T_ThemNut(T->LK_Phai, X);
  }
}

void T_HuyBo(Tree &T)
{
  if (T != NULL)
  {
    T_HuyBo(T->LK_Trai);
    T_HuyBo(T->LK_Phai);
    T_XoaNutLa(T);
  }
}

void T_XoaNut(Tree &T, Pt X)
{
  if (T == NULL)
    return;

  if (X < T->ND)
  {
    T_XoaNut(T->LK_Trai, X);
  }
  else if (X > T->ND)
  {
    T_XoaNut(T->LK_Phai, X);
  }
  else
  {
    if (T->LK_Trai == NULL && T->LK_Phai == NULL)
    {
      T_XoaNutLa(T);
    }
    else if (T->LK_Trai == NULL)
    {
      Tree temp = T;
      T = T->LK_Phai;
      delete temp;
    }
    else if (T->LK_Phai == NULL)
    {
      Tree temp = T;
      T = T->LK_Trai;
      delete temp;
    }
    else
    {
      // Có 2 con: tìm phần tử nhỏ nhất bên phải thay thế
      Tree minRight = T->LK_Phai;
      while (minRight->LK_Trai != NULL)
        minRight = minRight->LK_Trai;
      T->ND = minRight->ND;
      T_XoaNut(T->LK_Phai, minRight->ND);
    }
  }
}

void T_LNR(Tree T)
{
  if (T != NULL)
  {
    T_LNR(T->LK_Trai);
    cout << T->ND << " ";
    T_LNR(T->LK_Phai);
  }
}

/* Chương trình chính */
int main()
{
  Tree T = T_KhoiTao();
  Pt ds[] = {5, 3, 8, 1, 4, 7, 10};
  for (Pt x : ds)
    T_ThemNut(T, x);

  cout << "duyet: ";
  T_LNR(T);
  cout << endl;
  Pt x = 4;
  if (T_KTTonTai(T, x))
    cout << "Ton tai " << x << " trong cay.\n";
  else
    cout << "Khong ton tai " << x << " trong cay.\n";

  cout << "Xoa nut " << x;
  cout << endl;
  T_XoaNut(T, x);

  cout << "Cay sau khi xoa " << x << ": ";
  T_LNR(T);
  cout << endl;

  T_HuyBo(T);
  return 0;
}
