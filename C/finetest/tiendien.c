#include <math.h>
#include <stdio.h>

int main() {
  int n;
  float rs;
  printf("N =");
  scanf("%d", &n);

  if (n <= 50) {
    rs = n * 1.484;
  } else if (n >= 51 && n <= 100) {
    rs = 50 * 1.484 + (n - 50) * 1.533;
  } else if (n >= 101 && n <= 200) {
    rs = 50 * 1.484 + 50 * 1.553 + (n - 100) * 1.768;
  } else if (n >= 201 && n <= 300) {
  }
}
