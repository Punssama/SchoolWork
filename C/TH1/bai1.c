#include <stdio.h>
#include <string.h>

char *removespc(char *c) {
  for (int i = 0; i < strlen(c); i++) {
    if (c[i] == ' ' && c[i + 1] == ' ') {
      for (int j = i; j < strlen(c); j++) {
        c[j] = c[j + 1];
      }
      i--;
    }
  }
  return c;
}
int main() {
  int j = 0;
  char arr[10000], arr1[10000], rs[10000], rs1[10000];
  printf("Nhap vao xau: ");
  fgets(arr, 10000, stdin);
  // arr[strlen(arr) - 1] = '\0';
  arr[strcspn(arr, "\n")] = '\0';
  if (arr[0] == ' ' && arr[strlen(arr) - 1] == ' ') {
    for (int i = 1; i < strlen(removespc(arr)); i++) {
      rs[j] = removespc(arr)[i];
      j++;
    }
    strncpy(rs1, rs, strlen(rs) - 1);
    printf("Xau da chuan hoa: %s", rs1);
    printf("\n");
  }
}
