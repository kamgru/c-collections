#include "DLList.h"

typedef struct Hashtable Hashtable;
struct Hashtable {
    DLList** buckets;
    unsigned int bucketCount;
};

Hashtable* ht_create();
