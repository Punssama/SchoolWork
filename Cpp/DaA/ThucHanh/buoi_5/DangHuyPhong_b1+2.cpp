
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void bai1()
{
    priority_queue<int> pq;
    int values[] = {8, 3, 9, 1, 7, 5, 6, 4};

    for (int val : values)
    {
        pq.push(val);
    }

    cout << "Cac phan tu trong hang doi uu tien (max-heap):\n";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

template <typename T>
void doiCho(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

void sapXep(vector<string> &a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < a.size() - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                doiCho(a[j], a[j + 1]);
            }
        }
    }
}

void sapXepGiam(vector<string> &b, vector<int> &f)
{
    for (size_t i = 0; i < f.size(); i++)
    {
        for (size_t j = 0; j < f.size() - i - 1; j++)
        {
            if (f[j] < f[j + 1])
            {
                doiCho(f[j], f[j + 1]);
                doiCho(b[j], b[j + 1]);
            }
        }
    }
}

void bai2()
{
    int n;
    cout << "Nhap so xau: ";
    cin >> n;
    cin.ignore();

    vector<string> a(n);
    cout << "Nhap cac xau:\n";
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }

    sapXep(a);

    vector<string> b;
    vector<int> f;

    for (size_t i = 0; i < a.size();)
    {
        int count = 1;
        size_t j = i + 1;
        while (j < a.size() && a[j] == a[i])
        {
            count++;
            j++;
        }
        b.push_back(a[i]);
        f.push_back(count);
        i = j;
    }

    sapXepGiam(b, f);

    cout << "\nKet qua:\n";
    for (size_t i = 0; i < b.size(); i++)
    {
        cout << setw(15) << left << b[i] << f[i] << endl;
    }
}

int main()
{
    cout << "===== BAI 1 =====\n";
    bai1();
    cout << "\n===== BAI 2 =====\n";
    bai2();
    return 0;
}