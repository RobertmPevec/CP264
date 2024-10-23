/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2024-02-22
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked* queue_initialize() {
    queue_linked *queue = malloc(sizeof(*queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
    return queue;
}

void queue_free(queue_linked **source) {
    while ((*source)->front != NULL) {
        queue_node *bypass = (*source)->front;
        data_free(&bypass->item);
        (*source)->front = (*source)->front->next;
        free(bypass);
    }
    free(*source);
    *source = NULL;
}

BOOLEAN queue_empty(const queue_linked *source) {
    return (source->front == NULL);
}

int queue_count(const queue_linked *source) {
    int count = 0;
    queue_node *current = source->front;
    while(current != NULL) {
        count += 1;
        current = current->next;
    }
    return count;
}

void queue_insert(queue_linked *source, data_ptr item) {
        queue_node *new_node = malloc(sizeof(queue_node));
        new_node->item = malloc(sizeof(*item)); // we need to allocate memory for both the node itself and the data the node stores
        new_node->next = NULL;
        data_copy(new_node->item, item); // copy the item into new node
        if (source->rear == NULL) {
            source->front = new_node;
        } else {
            source->rear->next = new_node;
        }
        source->rear = new_node;
        source->count += 1;
}

BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {
    if (source->front != NULL) {
        data_copy(item, source->front->item);
    }
    return source->front != NULL;
}

BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {
	if (source->front == NULL) {
		BOOLEAN yesorno = FALSE;
    } else {
    BOOLEAN yesorno = TRUE;
	queue_node *temp = source->front;
	*item = temp->item;
	source->front = source->front->next;
	if (source->front == NULL) {
		source->rear = NULL; // in case when there is only 1 item in queue
	}
	free(temp);
	source->count -= 1;
	return yesorno;
    }
}

void queue_print(const queue_linked *source) {
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;

    while(current != NULL) {
        printf("%s\n", data_string(string, sizeof string, current->item));
        current = current->next;
    }
    return;
}
