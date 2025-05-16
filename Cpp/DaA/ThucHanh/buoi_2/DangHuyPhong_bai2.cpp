#include <iostream>
using namespace std;
/*Cac khai bao */
typedef float Pt;
typedef struct Nt {
  Pt ND;
  Nt *LK;
} Nut;
typedef Nut *Danh_Sach;

/*Khai báo các hàm nguyên mau tai dây*/
Danh_Sach L_KhoiTao(Danh_Sach &L); // Khoi tao mot danh sach rong (nul)
void L_HuyBo(
    Danh_Sach &L); // Xoa bo mot danh sach L cho truoc: giai phong bo nho
bool L_KTRong(
    Danh_Sach L); // Kiem tra xem danh sach L co rong (True) hay khong (False)
Pt L_XemPT(Danh_Sach L); // lay ra noi dung cua phan tu dau tien cua dah sach L
void L_ChenPTDau(Danh_Sach &L, Pt X); // Chen them phan tu co noi dung X vao vi
                                      // tri dau tien cua danh sach L
void L_XoaPTDau(Danh_Sach &L); // lay noi dung phan tu dau tien trong danh sach
                               // L, sau do xoa phan tu do khoi danh sach
/* Các hàm khó */
void DuyetDS(Danh_Sach L); // In ra màn hinh lan luot noi dung cua cac phan tu
                           // trong danh sach L
void L_ChenPT(Danh_Sach &L, Danh_Sach P,
              Pt X); // Chen phan tu co noi dung X vao vi tri truoc phan tu duoc
                     // tro boi P trong danh sach L
Pt L_XoaPT(Danh_Sach &L,
           Danh_Sach P); // lay ra noi dung cua phan tu thu duoc tro boi P, sau
                         // do xoa phan tu P khoi danh sach L

int main() { // Chuong trinh chinh dethu nghiem cac ham da viet tai day
  int n;
  Pt pt;
  Danh_Sach L;
  L = L_KhoiTao(L);

  cout << "Nhap vao n: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Nhap vao phan tu thu " << i + 1 << ": ";
    cin >> pt;
    L_ChenPTDau(L, pt);
  }
  cout << "danh sach la: ";
  DuyetDS(L);
  // xoa dau danh sach
  L_XoaPTDau(L);
  cout << "danh sach sau khi xoa phan tu dau la: ";
  DuyetDS(L);
  // huy bo
  cout << "danh sach sau khi huy bo la: ";
  L_HuyBo(L);
  DuyetDS(L);
};

/*Dinh nghia các ham tai day */
Danh_Sach L_KhoiTao(Danh_Sach &L) {
  L = nullptr;
  return L;
};
void L_XoaPTDau(Danh_Sach &L) {
  Nut *old = L;
  L = L->LK;
  delete old;
};

void L_HuyBo(Danh_Sach &L) { L = nullptr; };
bool L_KTRong(Danh_Sach L) { return (L->LK == nullptr); };
Pt L_XemPT(Danh_Sach L) { return L->ND; };
void L_ChenPTDau(Danh_Sach &L, Pt X) {
  Danh_Sach newNode = new Nut;
  newNode->ND = X;
  newNode->LK = L;
  L = newNode;
};

void DuyetDS(Danh_Sach L) {
  Nut *p = L;
  while (p != nullptr) {
    cout << L_XemPT(p) << " ";
    p = p->LK;
  }
  cout << endl;
}
