#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  char str[10000], str2[10000];
  int i, a = 0;
  printf("Nhap vao xau: ");
  fgets(str, 1000, stdin);
  str[strlen(str) - 1] = '\0';
  if (strlen(str) == 0) {
    printf("xau dau vao rong!");
  } else {

    for (i = strlen(str) - 1; i >= 0; i--) {
      str2[a] = str[i];
      a++;
    }
    printf("Noi dung xau dau vao la: %s", str);
    printf("\nDo dai cua xau la: %d", strlen(str));
    printf("\nXau sau khi dao nguoc la: %s", str2);
  }
}
