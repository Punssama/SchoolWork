/*Cac khai bao */
typedef float Pt;
typedef struct Nt
  { Pt ND;
    Nt* LK_Truoc;
    Nt* LK_Sau;
  } Nut;
typedef struct Nut* Danh_Sach;

/*Khai báo các hàm nguyên mau tai dây*/
Danh_Sach L_KhoiTao(); //Khoi tao mot danh sach rong (nul)
void L_HuyBo(Danh_Sach &L); //Xoa bo mot danh sach L cho truoc: giai phong bo nho
bool L_KTRong(Danh_Sach L); //Kiem tra xem danh sach L co rong (True) hay khong (False)
Pt L_XemPTDau(Danh_Sach L); //lay ra noi dung cua phan tu dau tien cua dah sach L
Pt L_XemPTCuoi(Danh_Sach L); //lay ra noi dung cua phan tu cuoi cung cua dah sach L
void L_ChenPTDau(Danh_Sach &L, Danh_Sach P, Pt X); //Chen them phan tu co noi dung X vao vi tri tro boi P trong danh sach L
Pt L_XoaPTDau(Danh_Sach &L, Danh_Sach P); //lay noi dung phan tu tro boi P trong danh sach L, sau do xoa phan tu do khoi danh sach

int main()
  { //Chuong trinh chinh dethu nghiem cac ham da viet tai day
  };
  
/*Dinh nghia các ham tai day */

