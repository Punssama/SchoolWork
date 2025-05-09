#include <math.h>
#include <stdio.h>

int ifcp(float x) {
  int sqr = sqrt(x);
  if (sqr * sqr == x) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int i, a = 0;
  float s, rs = 0;
  printf("nhap N: ");
  scanf("%f", &s);

  printf("Cac so chinh phuong co trong khoang tu N den 3N la:");
  for (i = s; i < s * 3; i++) {
    if (ifcp(i) == 1) {
      printf(" %d", i);
      rs += i;
      a++;
    }
  }
  printf("\nTrung binh cong cac so chinh phuong la %g", rs / a);
}
