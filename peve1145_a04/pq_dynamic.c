/**
 * -------------------------------------
 * @file  pq_dynamic.c
 * Dynamic Priority Queue Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include "pq_dynamic.h"

// Functions

// Initializes a priority queue.
void pq_initialize(pq_dynamic_struct **source, int capacity) {
    *source = malloc(sizeof(**source));
    (*source)->capacity = capacity;
    (*source)->items = malloc(capacity * sizeof(*(*source)->items));
    (*source)->count = 0;
    (*source)->first = -1;
}

// Destroys a priority queue.
void pq_destroy(pq_dynamic_struct **source) {
    if ((*source)->items != NULL) {
        free((*source)->items);
        (*source)->items = NULL;
    }
    free(*source);
    *source = NULL;
}

// Determines if a priority queue is empty.
bool pq_empty(const pq_dynamic_struct *source) {
    return source->count == 0;
}

bool pq_full(const pq_dynamic_struct *source) {
    return source->count >= source->capacity;
}

// Returns the number of items in the queue.
int pq_count(const pq_dynamic_struct *source) {
    return source->count;
}

// Inserts an item into a priority queue.
bool pq_insert(pq_dynamic_struct *source, data_type *item) {
    bool trueorfalse = false;
    if (source->count != source->capacity) {
        source->items[source->count] = *item;
        trueorfalse = true;
        source->count += 1;
    } 
    return trueorfalse;
}

// Returns a copy of the first of a priority queue.
bool pq_peek(const pq_dynamic_struct *source, data_type *item) {
    bool trueorfalse = false;
    if (source->count > 0) {
        *item = source->items[source->first];
        trueorfalse = true;
    }
    return trueorfalse;
}

// Returns and removes the item on the first of a priority queue.
bool pq_remove(pq_dynamic_struct *source, data_type *item) {
    bool trueorfalse = false;
    if (source->count != 0) {
        *item = source->items[0];
        for (int i = 0; i < source->count - 1; i++) {
            source->items[i] = source->items[i + 1];
        }
        source->count -= 1;
        trueorfalse = true;
        if (source->count == 0) {
            source->first = -1;
        }
    }
    return trueorfalse;
}

// Prints the items in a priority queue from first to rear.
void pq_print(const pq_dynamic_struct *source) {
    // Walk through stack from top to bottom using indexes.
    for(int i = 0; i < source->count; i++) {
        data_print(&(source->items[i]));
        printf("\n");
    }
    return;
}
