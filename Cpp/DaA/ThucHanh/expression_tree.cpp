#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char val;
    Node *left;
    Node *right;
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node *createNode(char v)
{
    Node *node = new Node;
    node->val = v;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node *buildTree(string &postfix)
{
    Node *stack[100];
    int top = -1;

    for (char c : postfix)
    {
        Node *node = createNode(c);
        if (isOperator(c))
        {
            node->right = stack[top--];
            node->left = stack[top--];
        }
        stack[++top] = node;
    }

    return stack[top];
}

int evaluate(Node *root)
{
    if (!isOperator(root->val))
        return root->val - '0';

    int l = evaluate(root->left);
    int r = evaluate(root->right);

    if (root->val == '+')
        return l + r;
    if (root->val == '-')
        return l - r;
    if (root->val == '*')
        return l * r;
    if (root->val == '/')
        return l / r;

    return 0; // đề phòng
}

void inorder(Node *root)
{
    if (!root)
        return;
    if (isOperator(root->val))
        cout << "(";
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
    if (isOperator(root->val))
        cout << ")";
}

int main()
{
    string postfix;
    cout << "Nhap bieu thuc hau to (vd: 34+2*): ";
    cin >> postfix;

    Node *root = buildTree(postfix);

    cout << "Infix: ";
    inorder(root);
    cout << endl;

    cout << "Gia tri: " << evaluate(root) << endl;

    return 0;
}