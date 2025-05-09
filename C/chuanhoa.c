#include <stdio.h>
#include <string.h>

char *remspc(char *w) {
  int i, j = 0;
  for (i = 0; i < strlen(w); i++) {
    if (w[i] == ' ' && w[i + 1] == ' ') {
      for (int t = i; t < strlen(w); t++)
        w[t] = w[t + 1];
      i--;
    }
  }
  return w;
}

int main() {
  int i, j = 0;
  char w[10000], rs[10000], rs2[10000];
  printf("Nhap W = ");
  fgets(w, 10000, stdin);
  w[strcspn(w, "\n")] = '\0';

  if (w[0] == ' ' && w[strlen(w) - 1] == ' ') {
    for (i = 1; i < strlen(remspc(w)); i++) {
      rs[j] = remspc(w)[i];
      j++;
    }
    strncpy(rs2, rs, strlen(rs) - 1);
    printf("Chuan hoa = %s", rs2);
  } else if (w[0] == ' ') {
    for (i = 1; i < strlen(remspc(w)); i++) {
      rs[j] = remspc(w)[i];
      j++;
    }
    printf("Chuan hoa = %s", rs);
  } else if (w[strlen(w) - 1] == ' ') {
    strncpy(rs, remspc(w), strlen(remspc(w)) - 1);
    printf("Chuan hoa = %s", rs);
  } else {
    printf("Chuan hoa = %s", remspc(w));
  }
}
