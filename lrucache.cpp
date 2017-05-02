#include "lrucache.h"

Node* createNewNode(int val)
{
    Node* newNode = new Node();
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->value = val;

    return newNode;
}

int main()
{
    Node* front = nullptr;
    Node* rear = nullptr;

    int cacheSize;
    cout << "\n Enter Size of Cache: ";
    cin >> cacheSize;

    LRUCache* cache = new LRUCache(cacheSize);
    Node* foundnode = nullptr;
    int pageId = 0;

    while (1)
    {
        cout << "\n Enter PageId to Refer (-1 to exit): ";
        cin >> pageId;

        if (pageId == -1)
        {
            break;
        }

        foundnode = cache->findInCache(pageId);

        cache->printCache();
    }


    cout << "\n";
    return 0;
}

LRUCache::LRUCache(int size)
{
    mLruQueue = new lruqueue();
    mLruQueue->mTotalCacheSize = size;
    mLruQueue->mCurrentCacheSize = 0;
    mLruQueue->mQueueFront = mLruQueue->mQueueRear = nullptr;
}

bool LRUCache::isCacheFull()
{
    return (mLruQueue->mCurrentCacheSize == mLruQueue->mTotalCacheSize);
}

Node* LRUCache::findInCache(int pageId)
{
    Node* foundNode = nullptr;

    auto fitr = mPageIdtoNodeMap.find(pageId);

    // already in cache, return the Node and Move the Node to begining.
    if (fitr != mPageIdtoNodeMap.end())
    {
        cout << "\n[Debug] [" << __FUNCTION__ << "] Found in Cache";
        foundNode = fitr->second;
    }

    if (foundNode == nullptr)
    {
        cout << "\n[Debug] [" << __FUNCTION__ << "] Not Found in Cache";
        // pageId is not yet Referenced, add to the cache.
        // create new node for this pageId.
        // if cache queue is not full, add this pageid at front
        // else remove the rear node from queue and add this node at front.

        // cache is not Full,
        if (!isCacheFull())
        {
            cout << "\n[Debug] [" << __FUNCTION__ << "] Cache is not full";
            // Add new Node to front and increment the cache count.
            foundNode = addInCache(pageId);
        }
        else    // Cache is full,
        {
            cout << "\n[Debug] [" << __FUNCTION__ << "] Cache is full!!!";
            // Remove the rear Node from queue.
            removeRearFromCache();

            // Add new Node to front and increment the cache count.
            foundNode = addInCache(pageId);
        }
    }
    else
    {
        cout << "\n[Debug] [" << __FUNCTION__ << "] found in cache, moving it to front";
        // page found in cache, move it as recently viewed page.
        moveToFrontofQueue(foundNode);
    }

    return foundNode;
}

Node* LRUCache::addInCache(int pageId)
{
    cout << "\n[Debug] [" << __FUNCTION__ << "] adding in Cache";

    Node* newNode = createNewNode(pageId);
    newNode->next = mLruQueue->mQueueFront;

    // Empty Queue
    if (mLruQueue->mQueueRear == nullptr)
    {
        cout << "\n[Debug] [" << __FUNCTION__ << "] Empty Queue.";
        mLruQueue->mQueueFront = mLruQueue->mQueueRear = newNode;
    }
    else
    {
        cout << "\n[Debug] [" << __FUNCTION__ << "] adding at front";
        mLruQueue->mQueueFront->prev = newNode;
        mLruQueue->mQueueFront = newNode;
    }

    // increment current cache queue size.
    mLruQueue->mCurrentCacheSize++;

    cout << "\n[Debug] [" << __FUNCTION__ << "] till now no. elements " << mLruQueue->mCurrentCacheSize;

    // add to map.
    mPageIdtoNodeMap[pageId] = newNode;

    return newNode;
}

void LRUCache::moveToFrontofQueue(Node* foundNode)
{
    // if not already at front
    if (mLruQueue->mQueueFront != foundNode)
    {
        cout << "\n[Debug] [" << __FUNCTION__ << "] moving to front";
        foundNode->prev->next = foundNode->next;

        if (foundNode->next != nullptr)
        {
            foundNode->next->prev = foundNode->prev;
        }
        else
        {
            // found node is the rear node of queue.
            mLruQueue->mQueueRear = foundNode->prev;
        }

        foundNode->prev = nullptr;
        foundNode->next = mLruQueue->mQueueFront;
        mLruQueue->mQueueFront->prev = foundNode;
        mLruQueue->mQueueFront = foundNode;

    }
}

void LRUCache::removeRearFromCache()
{
    Node* temp = mLruQueue->mQueueRear;

    if (mLruQueue->mQueueRear != nullptr)
    {
        cout << "\n[Debug] [" << __FUNCTION__ << "] removing from cache value: " << mLruQueue->mQueueRear->value;
        mPageIdtoNodeMap.erase(mLruQueue->mQueueRear->value);

        mLruQueue->mQueueRear->prev->next = nullptr;
        mLruQueue->mQueueRear = mLruQueue->mQueueRear->prev;
        delete temp;
        mLruQueue->mCurrentCacheSize--;
    }
    else
    {
        cout << "\n[Debug] [" << __FUNCTION__ << "] Empty Queue";
        // only one element in queue.
        mLruQueue->mQueueRear = mLruQueue->mQueueFront = nullptr;
        mLruQueue->mCurrentCacheSize = 0;
    }
}

void LRUCache::printCache()
{
    cout << "\n\n\t\t ~~~ Cache ~~~\n\t\t  ";
    Node* tempFront = mLruQueue->mQueueFront;

    while (tempFront != nullptr)
    {
        cout << tempFront->value << ", ";
        tempFront = tempFront->next;
    }

    cout << "\n\t\t ~~~~~~";
}