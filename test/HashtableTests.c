#include "Tests.h"
#include "../src/Hashtable.h"
#include <stdio.h>

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

int main(){
    _verify(when_hashtable_created_it_should_not_be_null);
    _verify(when_value_not_present_find_should_return_null);
    _verify(test_find_theory);
    return 0;
}