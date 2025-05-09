#include <stdio.h>
#include <string.h>

int main()
{
  int j = 0, i, n, rs = 0;
  char lang[100][10000];
  printf("N = ");
  scanf("%d", &n);
  getchar();

  if (n == 0)
  {
    printf("Ngon ngu ngan nhat cuoi cung la: ");
    return 0;
  }
  else
  {
    for (i = 0; i < n; i++)
    {
      printf("Ten ngon ngu lap trinh thu %d: ", i + 1);
      fgets(lang[i], 100, stdin);
      lang[i][strlen(lang[i]) - 1] = '\0';
    }
    int min = strlen(lang[0]);
    for (i = 0; i < n; i++)
    {
      if (min >= strlen(lang[i]))
      {
        min = strlen(lang[i]);
        rs = i;
      }
    }

    printf("Ngon ngu ngan nhat cuoi cung la: %s", lang[rs]);
  }
}
