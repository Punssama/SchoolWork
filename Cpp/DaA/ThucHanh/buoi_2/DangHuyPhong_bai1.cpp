#include <iostream>

using namespace std;

typedef int T;

struct Node
{
  T data;
  Node *next;
};

struct list
{
  Node *head;
};

void listInit(list &list) { list.head = NULL; }

void popFront(list &list)
{
  Node *old = list.head;
  list.head = list.head->next;
  delete old;
}

bool ifListNull(list list) { return list.head == NULL; }

void deleteList(list &list)
{
  while (!ifListNull(list))
  {
    popFront(list);
  }
}

void popBack(list &list)
{
  if (ifListNull(list))
  {
    return;
  }
  else
  {
    Node *p = list.head;
    while (p->next->next != NULL)
    {
      p = p->next;
    }
    p->next = NULL;
  }
}

void showList(list &list)
{
  Node *p = list.head;
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

void listPushFront(list &list, T e)
{
  Node *v = new Node;
  v->data = e;
  v->next = list.head;
  list.head = v;
}

void listPushBack(list &list, T e)
{
  Node *v = new Node;
  v->data = e;
  v->next = NULL;
  if (list.head == NULL)
  {
    list.head = v;
  }
  else
  {
    Node *p = list.head;
    while (p->next != NULL)
    {
      p = p->next;
    }
    p->next = v;
  }
}
int main()
{
  T n;
  T pt;
  list list;
  listInit(list);
  cout << "Nhap vao so phan tu n: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << "Nhap vao phan tu thu " << i + 1 << ": ";
    cin >> pt;
    listPushBack(list, pt);
  }

  cout << "Danh sach phan tu la: ";
  showList(list);
  // xoa cuoi
  popBack(list);
  cout << "Danh sach phan tu sau khi xoa cuoi la: ";
  showList(list);
  // them phan tu vao dau danh sach
  T k;
  cout << "nhap vao phan tu k: ";
  cin >> k;
  listPushFront(list, k);
  cout << "Danh sach sau khi them phan tu " << k << "vao dau la: ";
  showList(list);
  // xoa dau
  popFront(list);
  cout << "Danh sach phan tu sau khi xoa dau la: ";
  showList(list);
}
