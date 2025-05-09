#include <math.h>
#include <stdio.h>

int main() {
  int a, b, c;
  printf("Nhap vao a: ");
  scanf("%d", &a);
  printf("Nhap vao b: ");
  scanf("%d", &b);
  printf("Nhap vao c: ");
  scanf("%d", &c);

  if (a > 31 || a == 0 || b > 12 || b == 0 || c < 100 || c == 0 ||
      (a > 29 && b == 2)) {
    // check xem so nhap vao co theo thu tu ngay thang nam khong
    printf("Ba so nhap vao khong phai ngay thang nam.");
  } else {
    // check xem nam la nam nhuan hay khong
    if (c % 400 == 0 || (c % 4 == 0 && c % 100 != 0)) {
      printf("Nam %d la nam nhuan", c);
      // check xem co roi vao thang 2 cua nam nhuan hay khong
      if (b == 2) {
        // check xem co roi vao ngay 29 khong
        if (a == 29) {
          printf("\nNgay tiep theo la %d/%d/%d", a, b, c);
        }
        // check xem co roi vao ngay 28 hoac nho hon khong
        if (a <= 28) {
          printf("\nNgay tiep theo la %d/%d/%d", a + 1, b, c);
        }
      } else {
        // cac thang co 30 ngay
        if (b == 4 || b == 6 || b == 9 || b == 11) {
          // check xem co roi vao ngay 30 khong
          if (a < 30) {
            printf("\nNgay tiep theo la %d/%d/%d", a + 1, b, c);
          } else if (a == 30)
            printf("\nNgay tiep theo la %d/%d/%d", a, b, c);
          // cac thang co 31 ngay
        } else {
          // check xem co roi vao ngay 31 khong
          if (a == 31) {
            printf("\nNgay tiep theo la %d/%d/%d", a, b, c);
          } else if (a < 31) {
            printf("\nNgay tiep theo la %d/%d/%d", a + 1, b, c);
          }
        }
      }
    } else {
      // roi vao nhung nam khac nam nhuan
      if (a == 29 && b == 2) {
        printf("Ba so nhap vao khong phai ngay thang nam.");
      } else if (a == 28 && b == 2) {
        printf("Ngay tiep theo la %d/%d/%d", a, b, c);
      } else if (b == 4 || b == 6 || b == 9 || b == 11) {
        if (a < 30) {
          printf("Ngay tiep theo la %d/%d/%d", a + 1, b, c);
        } else if (a == 30)
          printf("Ngay tiep theo la %d/%d/%d", a, b, c);
        else if (a == 31) {
          printf("Ba so nhap vao khong phai ngay thang nam.");
        }
      } else {
        if (a == 31) {
          printf("Ngay tiep theo la %d/%d/%d", a, b, c);
        } else if (a < 31) {
          printf("Ngay tiep theo la %d/%d/%d", a + 1, b, c);
        }
      }
    }
  }
}
