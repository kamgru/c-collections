#include "Tests.h"
#include "../src/Hashtable.h"
#include <stdio.h>
#include <stdbool.h>

int when_hashtable_created_it_should_not_be_null(){
    Hashtable* ht = ht_create();
    _assert(ht != NULL);
    return 0;
}

int when_value_not_present_find_should_return_null(){
    Hashtable* ht = ht_create();
    void* value = ht_find(ht, 123);
    _assert(value == NULL);
    return 0;
}

int when_value_inserted_it_should_return_true(){
    Hashtable* ht = ht_create();
    bool result = ht_insert(ht, 1, "test value");
    _assert(result);
    return 0;
}

int when_key_already_exists_it_should_not_add(){
    Hashtable* ht = ht_create();
    ht_insert(ht, 1, "test value");
    bool result = ht_insert(ht, 1, "another value");
    _assert(!result);
    return 0;
}

int test_find_theory(){
    Hashtable* ht = ht_create();
    
    char* testValues[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i = 0; i < 10; i++){
        ht_insert(ht, i, testValues[i]);
    }

    for (int i = 0; i < 10; i++){
        char* result = (char*)ht_find(ht, i);
        _assert(result == testValues[i]);
    }

    return 0;
}

int test_remove_theory(){
    Hashtable* ht = ht_create();
    
    char* testValues[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    for (int i = 0; i < 10; i++){
        ht_insert(ht, i, testValues[i]);
    }

    for (int i = 0; i < 10; i++){
        ht_remove(ht, i);
        void* result = ht_find(ht, i);
        _assert(result == NULL);
    }
    return 0;
}

int main(){
    _verify(when_hashtable_created_it_should_not_be_null);
    _verify(when_value_not_present_find_should_return_null);
    _verify(test_find_theory);
    _verify(when_value_inserted_it_should_return_true);
    _verify(when_key_already_exists_it_should_not_add);
    _verify(test_remove_theory);
    
    return 0;
}