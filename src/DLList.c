#include "DLList.h"
#include <stdlib.h>

ListNode* ln_create(void* value){
    ListNode* node = malloc(sizeof(ListNode));
    node->value = value;
    node->previous = NULL;
    node->next = NULL;
    return node;
}

DLList* dl_create(){
    DLList* list = malloc(sizeof(DLList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void dl_push_front(DLList* list, void* value){
    ListNode* node = ln_create(value);

    if (list->head == NULL){
        list->head = node;
        list->tail = node;
    }
    else{
        node->next = list->head;
        list->head->previous = node;

        if (list->tail->previous == NULL){
            list->tail->previous = node;
        }

        list->head = node;
    }

    list->size++;
}

void dl_push_back(DLList* list, void* value){
    if (list->size == 0){
        dl_push_front(list, value);
        return;
    }

    ListNode* node = ln_create(value);
    list->tail->next = node;
    node->previous = list->tail;
    list->tail = node;
    list->size++;
}

ListNode* dl_find_node(DLList* list, void* value){
    if (list->size == 0){
        return NULL;
    }

    ListNode* cursor = list->head;
    while(cursor){
        if (cursor->value == value){
            return cursor;
        }
        cursor = cursor->next;
    }

    return NULL;
}

void dl_remove_node(DLList* list, ListNode* node){
    if (node == NULL){
        return;
    }

    if (list->size == 0){
        return;
    }

    if (node == list->head){
        list->head = node->next;
    }

    if (node == list->tail){
        list->tail = node->previous;
    }

    if (node->previous != NULL){
        node->previous->next = node->next;
    }

    if (node->next != NULL){
        node->next->previous = node->previous;
    }

    free(node);
    list->size--;
}

void dl_destroy(DLList* list){
    ListNode* cursor = list->head;
    while(cursor){
        ListNode* next = cursor->next;
        free(cursor);
        cursor = next;
    }

    free(list);
}

ListNode* dl_pop_back(DLList* list){
    if (list->size == 0){
        return NULL;
    }

    ListNode* node = list->tail;
    
    if (list->size == 1){
        list->tail = NULL;
        list->head = NULL;
    }
    else {
        list->tail = list->tail->previous;
        list->tail->next = NULL;
    }

    list->size--;
    return node;
}

ListNode* dl_pop_front(DLList* list){
    if (list->size == 0){
        return NULL;
    }

    ListNode* node = list->head;
    if (list->size == 1){
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->head = list->head->next;
        list->head->previous = NULL;
    }

    list->size--;
    return node;
}