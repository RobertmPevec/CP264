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

// Initializes and returns an empty name_set.
name_set* name_set_initialize() {
	name_set *set = malloc(sizeof *set);
	set->front = NULL;
	set->rear = NULL;
	return set;
}

// Frees all of the nodes in the set, including the header node.
// Returns a count of the number of nodes freed, including the header node.
int name_set_free(name_set **set) {
	if (*set == NULL)
		return 0;

	int count = 0;
	name_set_node *current = (*set)->front;
	while (current != NULL) {
		name_set_node *temp = current;
		current = current->next;
		free(temp);
		count++;
	}

	free(*set);  // Free the header node itself
	*set = NULL; // Set the pointer to NULL to indicate it's been freed
	return count + 1;  // Including the header node
}

// Appends a name to a name_set, but only if the name is not already present in the set.
BOOLEAN name_set_append(name_set *set, const char *first_name,
		const char *last_name) {
	if (name_set_contains(set, first_name, last_name)) {
		return FALSE;  // Name already exists, do not add again
	}

	name_set_node *new_node = (name_set_node*) malloc(sizeof(name_set_node));
	if (new_node == NULL) {
		return FALSE;  // Memory allocation failed
	}

	// Copy the names and ensure null termination
	strncpy(new_node->first_name, first_name, NAME_LEN - 1);
	new_node->first_name[NAME_LEN - 1] = '\0'; // Ensure null termination
	strncpy(new_node->last_name, last_name, NAME_LEN - 1);
	new_node->last_name[NAME_LEN - 1] = '\0'; // Ensure null termination
	new_node->next = NULL;

	if (set->rear != NULL) {
		set->rear->next = new_node;
	} else {
		set->front = new_node;
	}
	set->rear = new_node;
	return TRUE;
}

// Determines if a name is already in a name_set.
BOOLEAN name_set_contains(const name_set *set, const char *first_name,
		const char *last_name) {
	name_set_node *current = set->front;
	while (current != NULL) {
		if (strcmp(current->first_name, first_name) == 0
				&& strcmp(current->last_name, last_name) == 0) {
			return TRUE;  // Name found
		}
		current = current->next;
	}
	return FALSE;  // Name not found
}

// Prints the contents of the linked set of names, one name per line.
void name_set_print(const name_set *set) {
	if (set != NULL) {
		name_set_node *temp = set->front;
		while (temp != NULL) {
			printf("%s, %s\n", temp->last_name, temp->first_name);
			temp = temp->next;
		}
	}
}
