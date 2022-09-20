#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild, *rightChild;

    treeNode(int val)
    {
        this->data = val;
        this->leftChild = this->rightChild = NULL;
    }
};

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
}

void printTree(treeNode *root, int level) // A->0,l->0
{
    if (root == NULL) // When the tree is empty -> A->0,l->0 = Not enter
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL) // Case 1 -> Not here
    {
        cout << root->data << endl;
        return;
    }
    else // Case 2 -> yes here
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }
    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

int main()
{
    treeNode *a = new treeNode(-1);
    treeNode *b = new treeNode(-1);
    treeNode *c = new treeNode(-1);
    treeNode *d = new treeNode(-1);
    treeNode *e = new treeNode(-1);
    treeNode *f = new treeNode(-1);
    treeNode *g = new treeNode(-1);
    treeNode *h = new treeNode(-1);
    treeNode *i = new treeNode(-1);

    a->data = 0;
    a->leftChild = b;
    a->rightChild = c;
    b->data = 1;
    b->leftChild = d;
    b->rightChild = e;
    c->data = 2;
    c->leftChild = f;
    c->rightChild = g;
    d->data = 3;
    d->leftChild = NULL;
    d->rightChild = NULL;
    e->data = 4;
    e->leftChild = NULL;
    e->rightChild = NULL;
    f->data = 5;
    f->leftChild = h;
    f->rightChild = i;
    g->data = 6;
    g->leftChild = NULL;
    g->rightChild = NULL;
    h->data = 7;
    h->leftChild = NULL;
    h->rightChild = NULL;
    i->data = 8;
    i->leftChild = NULL;
    i->rightChild = NULL;
    // int n = 9;
    // cin >> n;
    // treeNode *allNodes[n];
    // for (int i = 0; i < n; i++)
    // {
    //     allNodes[i] = new treeNode(-1);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     int value, left, right;
    //     cin >> value >> left >> right;
    //     allNodes[i]->data = value;
    //     if (left > n - 1 || right > n - 1)
    //     {
    //         cout << "Invalid Index" << endl;
    //         break;
    //     }
    //     if (left != -1)
    //     {
    //         allNodes[i]->leftChild = allNodes[left];
    //     }

    //     if (right != -1)
    //     {
    //         allNodes[i]->rightChild = allNodes[right];
    //     }
    // }

    printTree(a, 0);
    return 0;
}