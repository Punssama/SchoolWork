#include <stdio.h>

int main() {
  int ar[100], i, n, k, x;

  do {
    printf("nhap vao do dai mang: ");
    scanf_s("%d", &n);
  } while (n <= 0 || n >= 10);

  for (i = 0; i < n; i++) {
    printf("nhap vao a[%d]: ", i + 1);
    scanf_s("%d", &ar[i]);
  }
  printf("mang ban dau la: ");
  for (i = 0; i < n; i++) {
    printf("%d", ar[i]);
  }
  printf("\n");
  printf("Nhap vao x: ");
  scanf_s("%d", &x);
  printf("Nhap vao chi so k: ");
  scanf_s("%d", &k);
  for (i = n - 1; i >= k; i--) {
    ar[i + 1] = ar[i];
  }
  ar[k] = x;
  n++;

  printf("mang sau khi chen la: ");
  for (i = 0; i < n; i++) {
    printf("%d", ar[i]);
  }

  return 0;
}
