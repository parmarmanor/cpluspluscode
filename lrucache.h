#include "headers.h"

struct Node
{
    int value;
    Node* next;
    Node* prev;
};

class LRUCache
{
  public:
    LRUCache(int cacheSize);
    ~LRUCache();

  private:
    map<int, Node*>     mPageIdtoNodeMap;
    int                 mTotalCacheSize;
    int                 mCurrentCacheSize;
};