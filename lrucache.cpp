#include "lrucache.h"

Node* createNewNode(int val)
{
    Node* newNode = new Node();
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->value = val;
}

int main()
{
    Node* front = nullptr;
    Node* rear = nullptr;

    int pageId = 0;

    while (pageId != -1)
    {
        cout << "\n Enter PageId to Refer (-1 to exit): ";
        cin >> pageId;



    }


    cout << "\n";
    return 0;
}