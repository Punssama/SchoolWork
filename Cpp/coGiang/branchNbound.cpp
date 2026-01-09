#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int value;
    int level;
    int bound;
    int nodeIndex;
};

node genNode(int value, int level, int bound, int nodeIndex)
{
    node newNode;
    newNode.value = value;
    newNode.level = level;
    newNode.bound = bound;
    newNode.nodeIndex = nodeIndex;
}
