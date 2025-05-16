#include <iostream>
using namespace std;

typedef int T;

T *stackInit(int n)
{
    return new T[n];
}

void addInitialElem(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void printStack(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
T getElem(T arr[], int &n)
{
    T getElem = arr[n - 1];
    n--;
    return getElem;
}
void addElem(T arr[], T elem, int &n)
{
    n++;
    arr[n - 1] = elem;
}

int main()
{
    T *arr;
    int n;
    T elem;
    cout << "nhap vao so phan tu cua stack n: ";
    cin >> n;
    arr = stackInit(n);
    addInitialElem(arr, n);
    printStack(arr, n);
    elem = getElem(arr, n);
    cout << "Stack sau khi lay ra phan tu " << elem << " la: ";
    printStack(arr, n);
    T k;
    cout << "Nhap vao phan tu k: ";
    cin >> k;
    addElem(arr, k, n);
    cout << "Stack sau khi them phan tu " << k << " la: ";
    printStack(arr, n);
    delete[] arr;
    return 0;
}