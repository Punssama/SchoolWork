#include <math.h>
#include <stdio.h>
int cp(int n) {

  int can = sqrt(n);
  if (can * can == n) {
    return 1;
  } else {
    return 0;
  }
}

int snt(int t) {
  int i;
  if (t == 1 || t < 0) {
    return 0;
  } else if (t == 2) {
    return 1;

  } else {
    for (i = 2; i <= t; i++) {
      if (t % i == 0) {
        return 0;
        break;
      } else {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int n, i, arr[10], r = 0;
  float avr = 0;
  do {
    printf("nhap vao N: ");
    scanf_s("%d", &n);
  } while (n < 2 || n > 20);
  // cau a
  for (i = 0; i < n; i++) {
    printf("nhap vao Arr[%d]: ", i);
    scanf_s("%d", &arr[i]);
  }
  printf("phan tu trong mang la:");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    r += arr[i];
  }
  avr = r * 1.0 / n * 1.0;
  printf("\nTong phan tu cua mang la: %d", r);
  printf("\nTrung binh cong cac phan tu cua mang la: %g", avr);
  printf("\nso chinh phuong trong mang la: ");
  for (i = 0; i < n; i++) {
    if (cp(arr[i]) == 1) {
      printf(" %d", arr[i]);
    }
  }
  printf("\nso nguyen to trong mang la:");
  for (i = 0; i < n; i++) {
    if (snt(arr[i]) == 1) {
      printf(" %d", arr[i]);
    }
  }
}
