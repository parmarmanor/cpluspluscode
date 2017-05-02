#include "headers.h"

struct Node
{
    int     value;
    Node*   next;
    Node*   prev;
};

struct lruqueue
{
    int     mTotalCacheSize;
    int     mCurrentCacheSize;
    Node*   mQueueFront;
    Node*   mQueueRear;
};

class LRUCache
{
  public:
    LRUCache(int cacheSize);
    ~LRUCache();

    Node*   findInCache(int pageId);
    Node*   addInCache(int pageId);
    void    removeRearFromCache();
    void    moveToFrontofQueue(Node* node);
    bool    isCacheFull();

    void    printCache();

  private:
    map<int, Node*>     mPageIdtoNodeMap;

    lruqueue*           mLruQueue;

};