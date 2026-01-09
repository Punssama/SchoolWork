#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main()
{

  int arr[] = {5, 6, 1, 4, 2, 0};
  int n = sizeof(arr) / sizeof(arr[0]);

  int tmp = 0;
  for (int i = 0; i < n - 1; i++)
  {
    cout << "day so truoc ";
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
    cout << "a[" << i << "]: " << arr[i] << " ";
    cout << " day so sau: ";
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
    for (int j = i + 1; j < n; j++)
    {
      // cout << "a[j]; " << arr[j] << " ";
      if (arr[j] < arr[i])
      {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}