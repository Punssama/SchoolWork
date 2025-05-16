#include <iostream>
using namespace std;

typedef int T;

struct DNode
{
    T elem;
    DNode *next;
    DNode *prev;
};

struct DList
{
    DNode *header;
    DNode *trailer;
    DNode *currentPos;
};

void dlistInit(DList &list)
{
    list.header = new DNode;
    list.trailer = new DNode;

    list.header->next = list.trailer;
    list.header->prev = nullptr;

    list.trailer->prev = list.header;
    list.trailer->next = nullptr;

    list.currentPos = list.trailer;
}

void dlistDestroy(DList &list)
{
    DNode *p = list.header;
    while (p != nullptr)
    {
        DNode *next = p->next;
        delete p;
        p = next;
    }
    list.header = list.trailer = list.currentPos = nullptr;
}

bool dlistIsEmpty(DList &list)
{
    return list.header->next == list.trailer;
}

T dlistFront(DList &list)
{
    return list.header->next->elem;
}

T dlistBack(DList &list)
{
    return list.trailer->prev->elem;
}

T dlistCurrent(DList &list)
{
    return list.currentPos->elem;
}

void dlistMoveNext(DList &list)
{
    if (list.currentPos != list.trailer)
        list.currentPos = list.currentPos->next;
}

void dlistMovePrev(DList &list)
{
    if (list.currentPos != list.header)
        list.currentPos = list.currentPos->prev;
}

void dlistMoveFront(DList &list)
{
    list.currentPos = list.header->next;
}

void dlistMoveBack(DList &list)
{
    list.currentPos = list.trailer->prev;
}

void dlistPushFront(DList &list, T e)
{
    list.currentPos = list.header->next;
    DNode *u = new DNode;
    u->elem = e;
    u->next = list.currentPos;
    u->prev = list.header;
    list.header->next->prev = u;
    list.header->next = u;
    list.currentPos = u;
}

void dlistPushBack(DList &list, T e)
{
    list.currentPos = list.trailer;
    DNode *u = new DNode;
    u->elem = e;
    u->next = list.trailer;
    u->prev = list.trailer->prev;
    list.trailer->prev->next = u;
    list.trailer->prev = u;
    list.currentPos = u;
}

void dlistPopFront(DList &list)
{
    if (!dlistIsEmpty(list))
    {
        list.currentPos = list.header->next;
        DNode *v = list.currentPos;
        list.header->next = v->next;
        v->next->prev = list.header;
        delete v;
        list.currentPos = list.header->next;
    }
}

void dlistPopBack(DList &list)
{
    if (!dlistIsEmpty(list))
    {
        list.currentPos = list.trailer->prev;
        DNode *v = list.currentPos;
        list.trailer->prev = v->prev;
        v->prev->next = list.trailer;
        delete v;
        list.currentPos = list.trailer;
    }
}

void dlistInsert(DList &list, T e)
{
    DNode *v = list.currentPos;
    DNode *u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
    list.currentPos = u;
}

void dlistRemove(DList &list)
{
    DNode *v = list.currentPos;
    if (v == list.header || v == list.trailer)
        return;
    DNode *u = v->prev;
    DNode *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
    list.currentPos = w;
}

void dlistPrint(DList &list)
{
    DNode *p = list.header->next;
    while (p != list.trailer)
    {
        cout << p->elem << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    DList list;
    dlistInit(list);

    int n;
    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> x;
        dlistPushBack(list, x);
    }

    cout << "Danh sach: ";
    dlistPrint(list);

    dlistPopBack(list);
    cout << "Danh sach phan tu sau khi xoa cuoi la: ";
    dlistPrint(list);

    T k;
    cout << "Nhap vao phan tu k: ";
    cin >> k;
    dlistPushFront(list, k);
    cout << "Danh sach sau khi them phan tu " << k << " vao dau la: ";
    dlistPrint(list);

    dlistPopFront(list);
    cout << "Danh sach phan tu sau khi xoa dau la: ";
    dlistPrint(list);

    dlistDestroy(list);
    return 0;
}
