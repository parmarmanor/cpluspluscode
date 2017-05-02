#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef map<int, vector<int>> HeightToValuesMap;

class treeNode
{
  public:
    treeNode* left;
    treeNode* right;
    int value;

    treeNode(int v)
    {
        value = v;
        left = nullptr;
        right = nullptr;
    }
    ~treeNode() {}

    void printTree(treeNode* root);
    void verticalOrderPrint(treeNode* root, int level, HeightToValuesMap& map);

};

void treeNode::verticalOrderPrint(treeNode* root, int level, HeightToValuesMap& map)
{
    if (root == nullptr)
    {
        return;
    }

    verticalOrderPrint(root->left, level - 1, map);

    map[level].push_back(root->value);

    verticalOrderPrint(root->right, level + 1, map);

}

treeNode* createNode(int value)
{
    treeNode* node = new treeNode(value);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void treeNode::printTree(treeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    printTree(root->left);
    cout << " " << root->value;
    printTree(root->right);
}

int main1()
{
    treeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->left->right = createNode(8);
    root->right->right->right = createNode(9);

    cout << " Inorder Travesal: ";
    root->printTree(root);

    HeightToValuesMap verticalOrderTravesalMap;

    root->verticalOrderPrint(root, 0, verticalOrderTravesalMap);

    cout << "\n Vertical Order traversal:\n";

    for (auto itr : verticalOrderTravesalMap)
    {
        for (auto itr2 : itr.second)
        {
            cout << " " << itr2;
        }

        cout << "\n";
    }

    cout << "\n";
    return 0;
}