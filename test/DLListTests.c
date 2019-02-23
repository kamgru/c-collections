#include <stdio.h>
#include "../src/DLList.h"
#include "Tests.h"

//list creation & empty list tests
int when_list_created_it_should_not_be_null() {
    DLList* list = dl_create();
    _assert(list != NULL);
    dl_destroy(list);
    return 0;
}

int when_list_created_size_should_be_zero() {
    DLList* list = dl_create();
    _assert(list->size == 0);
    dl_destroy(list);
    return 0;
}

int when_list_empty_head_should_be_null(){
    DLList* list = dl_create();
    _assert(list->head == NULL);
    dl_destroy(list);
    return 0;
}

int when_list_empty_tail_should_be_null(){
    DLList* list = dl_create();
    _assert(list->tail == NULL);
    dl_destroy(list);
    return 0;
}

//list push front tests
int when_value_pushed_front_size_should_increment(){
    DLList* list = dl_create();
    dl_push_front(list, "test value");
    _assert(list->size == 1);
    dl_push_front(list, "another test value");
    _assert(list->size == 2);
    dl_destroy(list);
    return 0;
}

int given_empty_list_when_value_pushed_front_head_should_contain_pushed_value(){
    DLList* list = dl_create();
    char* testValue = "test value";
    dl_push_front(list, testValue);
    _assert(list->head->value == testValue);
    dl_destroy(list);
    return 0;    
}

int given_empty_list_when_value_pushed_front_tail_should_contain_pushed_value(){
    DLList* list = dl_create();
    char* testValue = "test value";
    dl_push_front(list, testValue);
    _assert(list->tail->value == testValue);
    dl_destroy(list);
    return 0;    
}

int test_push_front_theory_forward_iteration(){
    DLList* list = dl_create();
    char* testValues[5] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++){
        dl_push_front(list, testValues[i]);    
    }

    _assert(list->size == 5);

    ListNode* cursor = list->head;
    for (int i = 4; i >=0; i--){
        _assert(cursor->value == testValues[i]);
        cursor = cursor->next;
    }

    dl_destroy(list);
    return 0;
}

int test_push_front_theory_backward_iteration(){
    DLList* list = dl_create();
    char* testValues[5] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++){
        dl_push_front(list, testValues[i]);    
    }

    _assert(list->size == 5);

    ListNode* cursor = list->tail;
    for (int i = 0; i < 5; i++){
        _assert(cursor->value == testValues[i]);
        cursor = cursor->previous;
    }

    dl_destroy(list);
    return 0;
}

//list push back tests
int when_value_pushed_back_size_should_increment(){
    DLList* list = dl_create();
    dl_push_back(list, "test value");
    _assert(list->size == 1);
    dl_push_back(list, "another test value");
    _assert(list->size == 2);
    dl_destroy(list);
    return 0;
}

int given_empty_list_when_value_pushed_back_head_should_contain_pushed_value(){
    DLList* list = dl_create();
    char* testValue = "test value";
    dl_push_back(list, testValue);
    _assert(list->head->value == testValue);
    dl_destroy(list);
    return 0;    
}

int given_empty_list_when_value_pushed_back_tail_should_contain_pushed_value(){
    DLList* list = dl_create();
    char* testValue = "test value";
    dl_push_back(list, testValue);
    _assert(list->tail->value == testValue);
    dl_destroy(list);
    return 0;    
}

int test_push_back_theory_forward_iteration(){
    DLList* list = dl_create();
    char* testValues[5] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++){
        dl_push_back(list, testValues[i]);    
    }

    _assert(list->size == 5);

    ListNode* cursor = list->head;
    for (int i = 0; i < 5; i++){
        _assert(cursor->value == testValues[i]);
        cursor = cursor->next;
    }

    dl_destroy(list);
    return 0;
}

int test_push_back_theory_backward_iteration(){
    DLList* list = dl_create();
    char* testValues[5] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++){
        dl_push_back(list, testValues[i]);    
    }

    _assert(list->size == 5);

    ListNode* cursor = list->tail;
    for (int i = 4; i >= 0; i--){
        _assert(cursor->value == testValues[i]);
        cursor = cursor->previous;
    }

    dl_destroy(list);
    return 0;
}

//list node tests
int when_node_created_it_should_not_be_null(){
    ListNode* node = ln_create(0);
    _assert(node != NULL);
    return 0;
}

int when_node_created_it_should_contain_given_value(){
    char* testValue = "test value";
    ListNode* node = ln_create(testValue);
    _assert(node->value == testValue);
    return 0;
}

int when_node_created_previous_and_next_pointers_should_be_null(){
    ListNode* node = ln_create(0);
    _assert(node->previous == NULL);
    _assert(node->next == NULL);
    return 0;
}

//list find node tests
int given_empty_list_find_node_should_return_null(){
    DLList* list = dl_create();
    ListNode* node = dl_find_node(list, 0);
    _assert(node == NULL);
    dl_destroy(list);
    return 0;
}

int when_node_not_in_list_find_node_should_return_null(){
    DLList* list = dl_create();
    dl_push_back(list, "some value");
    ListNode* node = dl_find_node(list, "another value");
    _assert(node == NULL);
    dl_destroy(list);
    return 0;
}

int test_find_node_theory(){
    DLList* list = dl_create();
    char* testValues[] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++){
        dl_push_back(list, testValues[i]);
    }

    for (int i = 0; i < 5; i++){
        ListNode* node = dl_find_node(list, testValues[i]);
        _assert(node->value == testValues[i]);
    }
    dl_destroy(list);
    return 0;
}

//list remove node tests
int test_remove_node_theory(){
    DLList* list = dl_create();
    char* testValues[] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++){
        dl_push_back(list, testValues[i]);
    }

    for (int i = 0; i < 5; i++){
        ListNode* nodeToRemove = dl_find_node(list, testValues[i]);
        dl_remove_node(list, nodeToRemove);
        ListNode* node = dl_find_node(list, testValues[i]);
        _assert(node == NULL);
    }
    dl_destroy(list);
    return 0;
}

int when_node_removed_size_should_decrement(){
    DLList* list = dl_create();
    dl_push_back(list, 0);
    dl_remove_node(list, list->head);
    _assert(list->size == 0);
    dl_destroy(list);
    return 0;
}

int when_node_null_it_should_not_decrement_size(){
    DLList* list = dl_create();
    dl_remove_node(list, NULL);
    _assert(list->size == 0);
    dl_destroy(list);
    return 0;
}

//list pop back tests
int when_list_empty_pop_back_should_return_null(){
    DLList* list = dl_create();
    ListNode* node = dl_pop_back(list);
    _assert(node == NULL);
    dl_destroy(list);
    return 0;
}

int test_pop_back_theory(){
    DLList* list = dl_create();
    char* testValues[5] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++){
        dl_push_back(list, testValues[i]);
    }

    for (int i = 4; i >= 0; i--){
        ListNode* node = dl_pop_back(list);
        _assert(node->value == testValues[i]);
    }
    dl_destroy(list);
    return 0;
}

//list pop front tests
int when_list_empty_pop_front_should_return_null(){
    DLList* list = dl_create();
    ListNode* node = dl_pop_front(list);
    _assert(node == NULL);
    dl_destroy(list);
    return 0;
}

int test_pop_front_theory(){
    DLList* list = dl_create();
    char* testValues[5] = {"a", "b", "c", "d", "e"};
    for (int i = 0; i < 5; i++){
        dl_push_back(list, testValues[i]);
    }

    for (int i = 0; i < 5; i++){
        ListNode* node = dl_pop_front(list);
        _assert(node->value == testValues[i]);
    }

    dl_destroy(list);
    return 0;
}

int main(){
    _verify(when_list_created_it_should_not_be_null);
    _verify(when_list_empty_head_should_be_null);
    _verify(when_list_created_size_should_be_zero);
    _verify(when_value_pushed_front_size_should_increment);
    _verify(when_list_empty_tail_should_be_null);
    _verify(given_empty_list_when_value_pushed_front_head_should_contain_pushed_value);
    _verify(given_empty_list_when_value_pushed_front_tail_should_contain_pushed_value);
    _verify(test_push_front_theory_forward_iteration);
    _verify(test_push_front_theory_backward_iteration);
    _verify(when_value_pushed_back_size_should_increment);
    _verify(given_empty_list_when_value_pushed_back_head_should_contain_pushed_value);
    _verify(given_empty_list_when_value_pushed_back_tail_should_contain_pushed_value);
    _verify(test_push_back_theory_forward_iteration);
    _verify(test_push_back_theory_backward_iteration);

    _verify(when_node_created_it_should_contain_given_value);
    _verify(when_node_created_it_should_not_be_null);
    _verify(when_node_created_previous_and_next_pointers_should_be_null);

    _verify(given_empty_list_find_node_should_return_null);
    _verify(when_node_not_in_list_find_node_should_return_null);
    _verify(test_find_node_theory);

    _verify(when_node_removed_size_should_decrement);
    _verify(test_remove_node_theory);
    _verify(when_node_null_it_should_not_decrement_size);

    _verify(when_list_empty_pop_back_should_return_null);
    _verify(test_pop_back_theory);

    _verify(when_list_empty_pop_front_should_return_null);
    _verify(test_pop_front_theory);
    return 0;
}