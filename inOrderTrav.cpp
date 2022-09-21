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

void inOrderTrav(treeNode *root, string &chk) // A->0,l->0
{
    if (root == NULL)
    {
        return;
    }
    inOrderTrav(root->leftChild, chk);
    chk += to_string(root->data);
    inOrderTrav(root->rightChild, chk);
}

int main()
{
    int n;
    cin >> n;
    treeNode *allNodes[n];
    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;
        if (left > n - 1 || right > n - 1)
        {
            cout << "Invalid Index" << endl;
            break;
        }
        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }

        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }
    string blank = "";

    inOrderTrav(allNodes[0], blank);
    cout << blank << endl;
    return 0;
}