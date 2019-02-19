#include "DLList.h"
#include <stdbool.h>

#define HASHTABLE_BUCKET_COUNT 32;

typedef struct Hashtable Hashtable;
struct Hashtable {
    DLList** buckets;
    unsigned int bucketCount;
};

typedef struct HashtableNode HashtableNode;
struct HashtableNode {
    int key;
    void* value;
};

Hashtable* ht_create();
bool ht_insert(Hashtable* hashtable, int key, void* value);
void* ht_find(Hashtable* hashtable, int key);