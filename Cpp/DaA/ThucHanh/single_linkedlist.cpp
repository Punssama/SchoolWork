#include <iostream>

using namespace std;

typedef float fl;

typedef struct l
{
    fl Data;
    l *next;
} node;

typedef node *list;

list listInit()
{
    return nullptr;
}

void insertFirst(list &l, fl data)
{
    node *newNode = new node;
    newNode->Data = data;
    newNode->next = l;
    l = newNode;
}

void delFirst(list &l)
{
    node *old;
    old = l;
    l = l->next;
    delete old;
}

void inputList(list &l)
{
    int n;
    fl pt;
    cout << "Nhap vao n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao phan tu thu " << i + 1 << ": ";
        cin >> pt;
        insertFirst(l, pt);
    }
}
void printList(list l)
{
    node *p = l;
    while (p != nullptr)
    {
        cout << p->Data << " ";
        p = p->next;
    }
    cout << endl;
}

bool ifNull(list l)
{
    return l == nullptr;
}

int main()
{
    list ds;
    ds = listInit();
    inputList(ds);
    printList(ds);
    delFirst(ds);
    printList(ds);
}