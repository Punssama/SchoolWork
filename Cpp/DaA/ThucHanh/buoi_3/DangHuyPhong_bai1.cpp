#include <iostream>
using namespace std;

/*Cac khai bao */
typedef int T;
struct BinaryNode {
  T elem;
  BinaryNode *left;
  BinaryNode *right;
};

struct BinarySearchTree {
  BinaryNode *root;
};

/*Khai báo các hàm nguyên mẫu */
void bstDestroy(BinarySearchTree &t);
void bstMakeEmpty(BinarySearchTree &t);
bool bstIsEmpty(BinarySearchTree &t);
void bstMakeEmpty(BinaryNode *&t);
BinaryNode *bstFindMin(BinaryNode *t);
T bstFindMin(BinarySearchTree &t);
BinaryNode *bstFindMax(BinaryNode *t);
T bstFindMax(BinarySearchTree &tree);
bool bstContains(BinaryNode *t, T x);
void bstInsert(BinarySearchTree &t, T x);
void bstRemove(BinarySearchTree &t, T x);
BinaryNode *bstRemove(BinaryNode *t, T x);

/*Định nghĩa các hàm*/

void bstDestroy(BinarySearchTree &t) {
  bstMakeEmpty(t.root);
  t.root = nullptr;
}

void bstMakeEmpty(BinarySearchTree &t) { bstMakeEmpty(t.root); }

void bstMakeEmpty(BinaryNode *&t) {
  if (t != nullptr) {
    bstMakeEmpty(t->left);
    bstMakeEmpty(t->right);
    delete t;
    t = nullptr;
  }
}

bool bstIsEmpty(BinarySearchTree &t) { return t.root == nullptr; }

BinaryNode *bstFindMin(BinaryNode *t) {
  if (t == nullptr)
    return nullptr;
  while (t->left != nullptr)
    t = t->left;
  return t;
}

T bstFindMin(BinarySearchTree &t) {
  BinaryNode *minNode = bstFindMin(t.root);
  return minNode->elem;
}

BinaryNode *bstFindMax(BinaryNode *t) {
  if (t == nullptr)
    return nullptr;
  while (t->right != nullptr)
    t = t->right;
  return t;
}

T bstFindMax(BinarySearchTree &tree) {
  BinaryNode *maxNode = bstFindMax(tree.root);
  return maxNode->elem;
}

bool bstContains(BinaryNode *t, T x) {
  if (t == nullptr)
    return false;
  if (x < t->elem)
    return bstContains(t->left, x);
  else if (x > t->elem)
    return bstContains(t->right, x);
  else
    return true;
}

void bstInsert(BinarySearchTree &t, T x) {
  BinaryNode **current = &(t.root);
  while (*current != nullptr) {
    if (x < (*current)->elem)
      current = &((*current)->left);
    else if (x > (*current)->elem)
      current = &((*current)->right);
  }
  *current = new BinaryNode{x, nullptr, nullptr};
}

BinaryNode *bstRemove(BinaryNode *t, T x) {
  if (t == nullptr)
    return nullptr;
  if (x < t->elem)
    t->left = bstRemove(t->left, x);
  else if (x > t->elem)
    t->right = bstRemove(t->right, x);
  else {
    if (t->left != nullptr && t->right != nullptr) {
      BinaryNode *minNode = bstFindMin(t->right);
      t->elem = minNode->elem;
      t->right = bstRemove(t->right, minNode->elem);
    } else {
      BinaryNode *oldNode = t;
      t = (t->left != nullptr) ? t->left : t->right;
      delete oldNode;
    }
  }
  return t;
}

void bstRemove(BinarySearchTree &t, T x) { t.root = bstRemove(t.root, x); }

/*Hàm duyệt giữa để in cây*/
void inorder(BinaryNode *t) {
  if (t != nullptr) {
    inorder(t->left);
    cout << t->elem << " ";
    inorder(t->right);
  }
}

int main() {
  BinarySearchTree tree;
  tree.root = nullptr;

  int n, x;
  cout << "Nhap so luong phan tu: ";
  cin >> n;
  cout << "Nhap cac phan tu: ";
  for (int i = 0; i < n; ++i) {
    cin >> x;
    bstInsert(tree, x);
  }

  cout << "Cay BST sau khi chen: ";
  inorder(tree.root);
  cout << endl;

  cout << "Gia tri nho nhat: " << bstFindMin(tree) << endl;
  cout << "Gia tri lon nhat: " << bstFindMax(tree) << endl;

  cout << "Nhap gia tri can xoa: ";
  cin >> x;
  bstRemove(tree, x);

  cout << "Cay sau khi xoa: ";
  inorder(tree.root);
  cout << endl;

  bstMakeEmpty(tree);
  return 0;
}
