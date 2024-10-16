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
	if (pq_full(source)) {
		return false;
	source->items[(source->first + source->count) % source->capacity] = *item;
	source->count++;
	return true;
    }
}

bool pq_peek(const pq_struct *source, data_type *item) {
	if (pq_empty(source)) {
		return false;
	}
	*item = source->items[source->first];
	return true;
}

bool pq_remove(pq_struct *source, data_type *item) {
	if (pq_empty(source)) {
		return false;
	}
	*item = source->items[source->first];
	source->first = (source->first + 1) % source->capacity;
	source->count--;
	return true;
}

void pq_print(const pq_struct *source) {
	for (int i = 0; i < source->count; i++) {
		int index = (source->first + i) % source->capacity;
		printf("Item %d: %d\n", i, source->items[index]);
	}
}