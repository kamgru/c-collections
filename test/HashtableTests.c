#include "Tests.h"
#include "../src/Hashtable.h"
#include <stdio.h>

int when_hashtable_created_it_should_not_be_null(){
    Hashtable* ht = ht_create();
    _assert(ht != NULL);
    return 0;
}

int main(){
    _verify(when_hashtable_created_it_should_not_be_null);

    return 0;
}