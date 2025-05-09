#include <math.h>
#include <stdio.h>

int main() {
  int a, b, c;
  printf("Nhap vao canh a: ");
  scanf_s("%d", &a);
  printf("Nhap vao canh b: ");
  scanf_s("%d", &b);
  printf("Nhap vao canh c: ");
  scanf_s("%d", &c);

  if (a + b < c || a + c < b || c + b < a)
    printf("khong phai la 3 canh tam giac");
  else if (a == b && b == c) {
    printf("day la tam giac deu");
  } else if (a == b || a == c || b == c) {
    printf("day la tam giac can");
  } else {
    printf("day la tam giac thuong");
  }
}
