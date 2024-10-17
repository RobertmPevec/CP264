/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-09
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
    // Allocate memory to the data structure
    name_set *set = malloc(sizeof *set);
    // Initialize the header fields.
    set->front = NULL;
    set->rear = NULL;
    return set;
}

int name_set_free(name_set **set) {
    int nodes = 0;
    name_set_node *current = NULL;
    if (set != NULL && *set != NULL) {
        current = (*set)->front;
        while (current != NULL) {
            name_set_node *next = current->next;
            free(current);
            nodes += 1;
            current = next;
        }
        free(*set);
        *set = NULL;
    return nodes;
    }
}

BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name) {
BOOLEAN yesorno = TRUE;
    if (set == NULL || first_name == NULL || last_name == NULL) {
        yesorno = FALSE;
    } 
    else if (name_set_contains(set, first_name, last_name)) {
        yesorno = FALSE;
    }
    else {
        name_set_node *new_node = (name_set_node *)malloc(sizeof(name_set_node)); //Needed to allocate memory so function behaves consistantly
        if (new_node == NULL) {
            yesorno = FALSE;  // If memory allocation fails, set result to FALSE
        } else {
            strncpy(new_node->first_name, first_name, NAME_LEN - 1);
            new_node->first_name[NAME_LEN - 1] = '\0';
            strncpy(new_node->last_name, last_name, NAME_LEN - 1);
            new_node->last_name[NAME_LEN - 1] = '\0';
            new_node->next = NULL; // Mandatory to set next to NULL
            if (set->front == NULL) {
                set->front = new_node;
                set->rear = new_node;
            } 
            else {
                set->rear->next = new_node;
                set->rear = new_node;
            }
        }
    }
    return yesorno;
}

BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name) {
   BOOLEAN name_in_set = FALSE;
    name_set_node *current = NULL;
    if (set != NULL) {
        current = (set)->front;
        while (current != NULL && name_in_set != TRUE) {
            if (strcmp(current->first_name, first_name) == 0 && strcmp(current->last_name, last_name) == 0) {
                name_in_set = TRUE;
            }
            current = current->next;
        }
    }
    return name_in_set;
}

void name_set_print(const name_set *set) {
    name_set_node *current = NULL;
    if (set != NULL) {
        current = (set)->front;
        while (current != NULL) {
            name_set_node *next = current->next;
            printf("%s, %s\n", current->last_name, current->first_name);
            current = next;
        }
    }
}