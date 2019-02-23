#ifndef DLLIST_H
#define DLLIST_H

typedef struct ListNode ListNode;
struct ListNode {
    void* value;
    ListNode* previous;
    ListNode* next;
};

typedef struct DLList DLList;
struct DLList {
    int size;
    ListNode* head;
    ListNode* tail;
};

DLList* dl_create();
void dl_push_front(DLList* list, void* value);
void dl_push_back(DLList* list, void* value);
ListNode* dl_find_node(DLList* list, void* value);
void dl_remove_node(DLList* list, ListNode* node);
void dl_destroy(DLList* list);
ListNode* ln_create(void* value);
ListNode* dl_pop_back(DLList* list);
ListNode* dl_pop_front(DLList* list);

#endif