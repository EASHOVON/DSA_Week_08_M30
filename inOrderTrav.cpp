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
void preOrderTrav(treeNode *root, string &chk) // A->0,l->0
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->data);
    inOrderTrav(root->leftChild, chk);
    inOrderTrav(root->rightChild, chk);
}
void postOrderTrav(treeNode *root, string &chk) // A->0,l->0
{
    if (root == NULL)
    {
        return;
    }
    inOrderTrav(root->leftChild, chk);
    inOrderTrav(root->rightChild, chk);
    chk += to_string(root->data);
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
    string preOrdertext = "";
    string inOrdertext = "";
    string postOrdertext = "";

    preOrderTrav(allNodes[0], preOrdertext);
    inOrderTrav(allNodes[0], inOrdertext);
    postOrderTrav(allNodes[0], postOrdertext);
    cout << "Pre-Order: " << preOrdertext << endl;
    cout << "In-Order: " << inOrdertext << endl;
    cout << "Post-Order: " << postOrdertext << endl; //
    return 0;
}