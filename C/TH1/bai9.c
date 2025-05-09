#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  char a[1000], ch;
  int d = 0;
  printf("Nhap vao xau A: ");
  gets(a);
  a[strlen(a) - 1] = '\0';
  printf("Nhap vao ki tu ch: ");
  scanf("%c", &ch);

  for (int i = 0; i < strlen(a); i++) {
    if (a[i] == ch) {
      d++;
    }
  }
  if (d == 0) {
    printf("ki tu %c khong xuat hien trong xau A", ch);
  } else {
    printf("ki tu %c xuat hien trong xau A %d lan", ch, d);
  }
}
