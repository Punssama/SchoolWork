#include <math.h>
#include <stdio.h>

int main() {
  int n;
  float i;
  printf("Nhap vao N: ");
  scanf("%d", &n);

  printf("Cac so chinh phuong la: ");
  for (i = n; i < n * 3; i++) {
    int cp = sqrt(i);

    if (cp * cp == i) {
      printf("%g,", i);
    }
  }
}

/*
 * n nhap vao
 * int check = 1
*for i = 2 i<6 i++
 if(n%i == 0) {
   check = 0;
   break;
 }

if(check == 0) {
printf(n khong phai snt)
} else {
n la so nguyen to
}



*
*
*
*
*
* */
