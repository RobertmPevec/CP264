/**
 * -------------------------------------
 * @file  stack_array.c
 * stack_array Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "stack_array.h"

// Functions

void stack_initialize(stack_struct *source) {
    source->capacity = STACK_INIT;
    source->top = -1;
    return;
}

bool stack_empty(const stack_struct *source) {
    return (source->top == -1);
}

bool stack_full(const stack_struct *source) {
    return (source->top == (source->capacity - 1));
}

bool stack_push(stack_struct *source, data_type *item) {
    bool pushed = false;
    if(source->top < (source->capacity - 1)) {
        source->top++;
        data_copy(item, &(source->items[source->top]));
        pushed = true;
    }
    return pushed;
}

bool stack_peek(const stack_struct *source, data_type *item) {
    bool peeked = false;
    if(source->top > -1) {
        data_copy(&(source->items[source->top]), item);
        peeked = true;
    }
    return peeked;
}

bool stack_pop(stack_struct *source, data_type *item) {
    bool popped = false;

    if(source->top > -1) {
        data_copy(&(source->items[source->top]), item);
        source->top--;
        popped = true;
    }
    return popped;
}

void stack_print(const stack_struct *source) {
    for(int i = source->top; i > -1; i--) {
        data_print(&(source->items[i]));
        printf("\n");
    }
    return;
}
