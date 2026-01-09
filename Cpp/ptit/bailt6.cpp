#include <iostream>
#include <string>

using namespace std;

struct student
{
  string msv, name;
  double mark;
};

struct Node
{
  student *data;
  Node *pNext;
};

Node *createNode(student *data)
{
  Node *p = new Node;
  p->data = data;
  p->pNext = NULL;
  return p;
}

void createList(Node *&L) { L = NULL; }

void insertFirst(Node *&L, student *data)
{
  Node *newNode = createNode(data);
  if (L == NULL)
    L = newNode;
  else
  {
    newNode->pNext = L;
    L = newNode;
  }
}

void insertLast(Node *&L, student *data)
{
  Node *newNode = createNode(data);
  if (L == NULL)
    L = newNode;
  else
  {
    Node *p = L;
    while (p->pNext != NULL)
    {
      p = p->pNext;
    }
    p = newNode;
  }
}

Node *delFirst(Node *&L)
{
  if (L == NULL)
    return 0;
  Node *p = L;
  p = p->pNext;
  delete (L);
  return p;
}

void delLast(Node *&L)
{
  Node *p = L;
  if (L == NULL)
    return;
  while (p->pNext->pNext != NULL)
  {
    p = p->pNext;
  }
  delete (p->pNext);
  p->pNext = NULL;
}

student *insertStudent(student *data)
{
  data = new student;
  cin.ignore();
  cout << "MSV: ";
  getline(cin, data->msv);
  cout << "Name: ";
  getline(cin, data->name);
  cout << "Mark: ";
  cin >> data->mark;
  return data;
}

void inputStudents(Node *&L, student *data)
{
  int n;
  cout << "Nhap vao so sinh vien n = ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << "Nhap vao sinh vien thu " << i + 1 << endl;
    data = insertStudent(data);
    insertFirst(L, data);
  }
}

void addStudent(Node *&L, student *data)
{
  cout << "Nhap vao sinh vien moi " << endl;
  data = insertStudent(data);
  insertFirst(L, data);
}
void outputStudent(Node *L)
{
  Node *p = L;
  cout << "MSV\tName\tMark\n";
  while (p != NULL)
  {
    cout << p->data->msv << "\t" << p->data->name << "\t" << p->data->mark
         << endl;
    p = p->pNext;
  }
}

int main()
{
  Node *L;
  student *student;
  createList(L);
  inputStudents(L, student);
  outputStudent(L);
  // addStudent(L, student);
  // outputStudent(L);
  L = delFirst(L);
  // outputStudent(L);
  delLast(L);
  outputStudent(L);
}
