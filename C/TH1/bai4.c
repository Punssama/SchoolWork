#include "math.h"
#include "stdio.h"
// gt = giai thua
float gt(int x) { // giai thua cua 2 = 2
  int i, rs = 1;  // result
  for (i = 1; i <= x; i++) {
    rs *= i;
  }
  return rs;
}
// scope
int main() {
  int i, n;
  float rs = 0, rs2 = 1;
  printf("Nhap vao N: ");
  scanf("%d", &n);

  for (i = 1; i < n + 1; i++) { // n=3
    for (int j = 1; j <= i; j++) {
      rs2 *= j;
    }
    rs += (1 / rs2);
  }
  printf("S = %g", rs);
}

/*
 * 1+1/2!+1/3!
 *
 *
 *
 *
 *
 *
 * */
