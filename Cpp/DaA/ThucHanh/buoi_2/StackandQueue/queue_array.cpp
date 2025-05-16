#include <iostream>
using namespace std;

typedef int T;

T *queueInit(int capacity)
{
    return new T[capacity];
}

void inputInitialValue(T arr[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void printQueue(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void enqueue(T arr[], T elem, int &n, int capacity)
{
    if (n < capacity)
    {
        arr[n++] = elem;
    }
    else
    {
        cout << "Queue day, khong the them phan tu!\n";
    }
}

T dequeue(T arr[], int &n)
{
    if (n == 0)
    {
        cout << "Queue rong!\n";
        return -1;
    }
    T front = arr[0];
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    return front;
}

int main()
{
    int n;
    cout << "Nhap vao n: ";
    cin >> n;
    int capacity = n + 5;
    T *queue = queueInit(capacity);
    inputInitialValue(queue, n);
    printQueue(queue, n);

    T k;
    cout << "Nhap vao phan tu k: ";
    cin >> k;
    enqueue(queue, k, n, capacity);
    printQueue(queue, n);

    cout << "Hang doi sau khi lay phan tu " << dequeue(queue, n) << ": ";
    printQueue(queue, n);

    delete[] queue;
    return 0;
}
