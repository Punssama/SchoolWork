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

int ifsnt(int x) {
  int i, flag = 0;
  if (x == 1) {
    return flag = 0;
  } else {

    for (i = 2; i < x; i++) {
      if (x % i == 0) {
        flag = 0;
        break;
      } else
        flag = 1;
    }
  }
  return flag;
}
int main() {
  int arr[1000];
  int i, n, dnt = 0, dcp = 0;

  do {
    printf("Nhap vao N: ");
    scanf("%d", &n);
  } while (n <= 2 || n >= 20);
  for (i = 0; i < n; i++) {
    printf("Nhap vao A[%d]: ", i + 1);
    scanf("%d", &arr[i]);
  }

  printf("\nCac phan tu trong mang la:");
  for (i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }
  printf("\nCac so chinh phuong la:");
  for (i = 0; i < n; i++) {
    if (ifcp(arr[i]) == 1) {
      printf(" %d", arr[i]);
      dcp++;
    }
  }
  printf("\nCo %d so chinh phuong!", dcp);
  printf("\nCac so nguyen to la:");
  for (i = 0; i < n; i++) {
    if (ifsnt(arr[i]) == 1) {
      printf(" %d", arr[i]);
      dnt++;
    }
  }
  printf("\nCo %d so nguyen to!", dnt);
}
