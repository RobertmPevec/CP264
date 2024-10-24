/**
 * -------------------------------------
 * @file  list_dynamic.c
 * Dynamic List Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-10-05
 *
 * -------------------------------------
 */
#include "list_dynamic.h"

// Private helper functions

/**
 * Determines if an index is valid.
 *
 * @param list - pointer to a list.
 * @param i - index to check
 * @return - true if i is a valid index, false otherwise
 */
static bool valid_index(const list_dynamic_struct *source, int i) {
    return ((i >= 0) && (i <= source->count));
}

/**
 * Performs a linear search on source->items for key.
 *
 * @param list - pointer to a list.
 * @param key - key of item to look for in list.
 * @return - index of location of key in list, -1 if key not in list.
 */
static int list_linear_search(const list_dynamic_struct *source, const data_type *key) {
    int result = -1;
    int i = 0;
    while (i < source->count && result != -1) {
        if (source->items[i] == *key) {
            result = i;
        }
        i += 1;
    }
    return result;
}

// Functions
// Initializes a list.
void list_initialize(list_dynamic_struct **source, int capacity) {
    *source = malloc(sizeof(**source));
    (*source)->capacity = capacity;
    (*source)->items = malloc(capacity * sizeof(*(*source)->items));
    (*source)->count = 0;
}

void list_destroy(list_dynamic_struct **source) {
    if ((*source)->items != NULL) {
        free((*source)->items);
        (*source)->items = NULL;
    free(*source);
    *source = NULL;
    }
}

bool list_empty(const list_dynamic_struct *source) {
    return source->count == 0;
}

// Determines if the list is full.
bool list_full(const list_dynamic_struct *source) {
    return source->count >= source->capacity;
}

// Appends a item to the end of a list.
bool list_append(list_dynamic_struct *source, data_type *item) {
    bool trueorfalse = false;
    if (!list_full(source)) {
        for (int i = source->count -1; i>=0; i--) {
            source->items[i + 1] = source->items[i];
        }
        source->items[0] = *item;
        source->count += 1;
        trueorfalse = true;
    }
    return trueorfalse;
}

int list_count(const list_dynamic_struct *source) {
    return source->count;
}
bool list_insert(list_dynamic_struct *source, data_type *item, int i) {
    bool trueorfalse = false;
    if (i <= source->count && !list_full(source)) {
        trueorfalse = true;
        for (int n = source->count - 1; n >= i; n--) {
            source->items[n + 1] = source->items[n];
        }
        source->items[i] = *item;
        source->count += 1;
    }
    return trueorfalse;
}

// Returns a copy of the front of a list.
bool list_peek(const list_dynamic_struct *source, data_type *item) {
    if (source->count > 0) {
        *item = source->items[0];
    }
    return source->count != 0;
}

// Returns a copy of the item matching key in a list.
bool list_key_find(const list_dynamic_struct *source, const data_type *key, data_type *item) {
    int i = 0;
    bool itemfound = false;
    while (i < source->count && !itemfound) {
        if (source->items[i] == (*key)) {
            *item = source->items[i];
            itemfound = true;
        }
        i += 1;
    }
    return itemfound;
}

// Removes and returns the item matching key from the list.
bool list_key_remove(list_dynamic_struct *source, const data_type *key, data_type *item) {
    int i = 0;
    bool itemfound = false;
    while (i < source->count && !itemfound) {
        if (source->items[i] == *key) {
            *item = source->items[i];
            itemfound = true;
        } else {
            i += 1;
        }
    }
    if (itemfound) {
        // Shift items left to remove the found item
        for (int n = i; n < source->count - 1; n += 1) {
            source->items[n] = source->items[n + 1];
        }
        source->count -= 1;
    }
    return itemfound;
}

int list_key_index(const list_dynamic_struct *source, const data_type *key) {
    int i = 0;
    int itemfound = -1;
    while (i < source->count && itemfound == -1) {
        if (source->items[i] == (*key)) {
            itemfound = i;
        }
        i += 1;
    }   
    return itemfound;
}

// Determines if key is in a list.
bool list_key_contains(const list_dynamic_struct *source, const data_type *key) {
    int i = 0;
    bool itemfound = false;
    while (i < source->count && !itemfound) {
        if (source->items[i] == (*key)) {
            itemfound = true;
        }
        i += 1;
    }
    return itemfound;
}

int list_key_count(const list_dynamic_struct *source, const data_type *key) {
    int i = 0;
    int key_count = 0;
    while (i < source->count) {
        if (source->items[i] == (*key)) {
            key_count += 1;
        }
        i += 1;
    }
    return key_count;
}

// Removes and returns the item at index i from a list.
bool list_index_remove(list_dynamic_struct *source, data_type *item, int i) {
    bool itemfound = false;
    if (i >= 0 && i < source->count) {
        *item = source->items[i];
        source->items[i] = 0;
        for (int n = i; n < source->count - 1; n += 1) {
            source->items[n] = source->items[n + 1];
        }
        source->count -= 1;
        itemfound = true;
    }
    return itemfound;
}
// Finds the maximum item in a list.
bool list_max(const list_dynamic_struct *source, data_type *item) {
    if (source->count != 0) {
        int i = 1;
        int max = source->items[0];
        while (i < source->count) {
            if (source->items[i] > max) {
                max = source->items[i];
            }
            i += 1;
        }
        *item = max;
    }
    return source->count != 0;
}

// Finds the minimum item in a list.
bool list_min(const list_dynamic_struct *source, data_type *item) {
    if (source->count != 0) {
        int i = 1;
        int min = source->items[0];
        while (i < source->count) {
            if (source->items[i] < min) {
                min = source->items[i];
            }
            i += 1;
        }
        *item = min;
    }
    return source->count != 0;
}

// Removes all duplicate items from a list.
void list_clean(list_dynamic_struct *source) {
    for (int i = 0; i < source->count; i += 1) {
        int temp_value = source->items[i];
        for (int n = i + 1; n < source->count; n += 1) {
            if (temp_value == source->items[n]) {
                data_type removed_item;
                list_key_remove(source, &temp_value, &removed_item);
                n -= 1;
            }
        }
    }
}

// Compares two lists for equality.
bool list_equal(const list_dynamic_struct *target, const list_dynamic_struct *source) {
    bool trueorfalse = true;
    if (target->count == source->count) {
        int index = 0;
        while (index < target->count && trueorfalse) {
            if (target->items[index] != source->items[index]) {
                trueorfalse = !trueorfalse;
            }
            index += 1;
        }
    } else {
        trueorfalse = !trueorfalse;
    }
    return trueorfalse;
}

// Prints the items in a list from front to rear.
void list_print(const list_dynamic_struct *source) {
    // Walk through stack from top to bottom using indexes.
    for(int i = 0; i < source->count; i++) {
        data_print(&(source->items[i]));
        printf("\n");
    }
    return;
}
