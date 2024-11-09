/**
 * -------------------------------------
 * @file  pq_array.c
 * pq_array Source Code File
 * -------------------------------------
 * @author your name, your id, your email
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "pq_array.h"

// Functions

// your code here (include all stubs!)
void pq_initialize(pq_struct *source) {
    source->capacity = PQ_INIT;
    source->count = 0;
    source->first = 0;
}

    bool pq_empty(const pq_struct *source) {
        return source->count == 0;
    }

    bool pq_full(const pq_struct *source) {
        return source->count == source->capacity;
    }

    int pq_count(const pq_struct *source) {
        return source->count;
    }

    bool pq_insert(pq_struct *source, data_type *item) {
        bool success = false;
        if (source->count != source->capacity) {
            source->items[source->count] = *item;
            source->count += 1;
            success = true;
        }
        return success;
    }

    bool pq_peek(const pq_struct *source, data_type *item) {
        bool success = false;
        if (source->count != 0) {
            *item = source->items[source->first];
            success = true;
        }
        return success;
    }

        bool pq_remove(pq_struct *source, data_type *item) {
            bool success = false;
            if (source->count != 0) {
                *item = source->items[source->first];
                source->count -= 1;
                for (int i = source->first; i < source->count; i += 1) { // already subtracted 1 so no need to do again in for loop
                    source->items[i] = source->items[i + 1];
                }
                success = true;
            }
            return success;
        }
        void pq_print(const pq_struct *source) {
            
        }