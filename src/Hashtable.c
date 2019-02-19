#include "Hashtable.h"
#include <stdlib.h>

static int hash_key(Hashtable* hashtable, int key){
    return key % hashtable->bucketCount;
}

static DLList* find_chain(Hashtable* hashtable, int key){
    return hashtable->buckets[hash_key(hashtable, key)];
}

HashtableNode* htn_create(int key, void* value){
    HashtableNode* node = malloc(sizeof(HashtableNode));
    node->key = key;
    node->value = value;
    return node;
}

Hashtable* ht_create(){
    Hashtable* hashtable = malloc(sizeof(Hashtable));
    hashtable->bucketCount = HASHTABLE_BUCKET_COUNT;
    hashtable->buckets = malloc(sizeof(DLList*) * hashtable->bucketCount);

    for (int i = 0; i < hashtable->bucketCount; i++){
        hashtable->buckets[i] = dl_create();
    }

    return hashtable;
}

void ht_insert(Hashtable* hashtable, int key, void* value){
    DLList* chain = find_chain(hashtable, key);
    dl_push_back(chain, htn_create(key, value));
}

void* ht_find(Hashtable* hashtable, int key){
    DLList* chain = find_chain(hashtable, key);
    
    ListNode* cursor = chain->head;
    while(cursor){
        HashtableNode* htNode = (HashtableNode*)cursor->value;
        if (htNode->key == key){
            return htNode->value;
        }
        cursor = cursor->next;
    }

    return NULL;
}