/**
 * -------------------------------------
 * @file  queue_array.c
 * queue_array Source Code File
 * -------------------------------------
 * @author your name, your id, your email
 *
 * @version 2024-09-28
 *
 * -------------------------------------
 */
#include "queue_array.h"

// Functions

void queue_initialize(queue_struct *source) {
    source->capacity = QUEUE_INIT;
    source->front = 0;
    source->rear = -1;
    source->count = 0;
}

bool queue_empty(const queue_struct *source) {
    _Bool value = 1;
    if (source->front != NULL ) {
        value = 0;
    }
    return value;
}

bool queue_full(const queue_struct *source) {
    return source->count == source->capacity;
}

int queue_count(const queue_struct *source) {
    return source->count;
}

bool queue_insert(queue_struct *source, data_type *item) {
	if (queue_full(source)) {
		printf("Queue is full\n");
		return false;
	}
	source->rear = (source->rear + 1) % source->capacity;
	source->items[source->rear] = *item;
	source->count++;
	return true;
}

bool queue_peek(const queue_struct *source, data_type *item) {
	if (queue_empty(source)) {
		printf("Queue is empty\n");
		return false;
	}
	*item = source->items[source->front];
	return true;
}

bool queue_remove(queue_struct *source, data_type *item) {
	if (queue_empty(source)) {
		printf("Queue is empty\n");
		return false;
	}
	*item = source->items[source->front];
	source->front = (source->front + 1) % source->capacity;
	source->count--;
	return true;
}

void queue_print(const queue_struct *source) {
	if (queue_empty(source)) {
		printf("Queue is empty\n");
		return;
	}
	int i = source->front;
	while (i != source->rear) {
		data_print(&source->items[i]);
		printf("\n");
		i = (i + 1) % source->capacity;
	}
}