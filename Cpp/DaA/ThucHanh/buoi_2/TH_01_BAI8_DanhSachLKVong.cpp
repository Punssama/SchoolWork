/*Cac khai bao */
typedef float Pt;
typedef struct Nt
  { Pt ND;
    Nt* LK;
  } Nut;
typedef Nut* Danh_Sach;

/*Khai báo các hàm nguyên mau tai dây*/
Danh_Sach L_KhoiTao(); //Khoi tao mot danh sach rong (nul)
void L_HuyBo(Danh_Sach &L); //Xoa bo mot danh sach L cho truoc: giai phong bo nho
bool L_KTRong(Danh_Sach L); //Kiem tra xem danh sach L co rong (True) hay khong (False)
Pt L_XemPT(Danh_Sach L); //lay ra noi dung cua phan tu tai con tro L
void L_ChenPTDau(Danh_Sach &L, Pt X); //Chen them phan tu co noi dung X vao sau vi tri tro boi L
void L_XoaPTDau(Danh_Sach &L, Pt &X); //lay noi dung phan tu sau con tro L, sau do xoa phan tu do khoi danh sach

int main()
  { //Chuong trinh chinh dethu nghiem cac ham da viet tai day
  };
  
/*Dinh nghia các ham tai day */

