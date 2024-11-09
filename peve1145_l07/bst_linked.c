/**
 * -------------------------------------
 * @file  bst_linked.c
 * Linked BST Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-03-01
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "bst_linked.h"

// Macro for comparing node heights
#define MAX(a, b) ((a) > (b) ? (a) : (b))


static void bst_free_helper(bst_node *node);
static BOOLEAN bst_full_helper(bst_node *node);
static void bst_inorder_helper(const bst_node *node, data_ptr *items, int *index);
static void bst_preorder_helper(const bst_node *node, data_ptr *items, int *index);
static void bst_postorder_helper(const bst_node *node, data_ptr *items, int *index);
static BOOLEAN bst_remove_aux(bst_node **node, const data_ptr key, data_ptr item);
static void bst_copy_helper(bst_node **target_node, const bst_node *source_node);
static int bst_leaf_count_helper(const bst_node *node);
static int bst_one_child_count_helper(const bst_node *node);
static int bst_two_child_count_helper(const bst_node *node);
static void bst_node_counts_helper(const bst_node *node, int *zero, int *one, int *two);
static int bst_balanced_helper(const bst_node *node);
static BOOLEAN bst_valid_helper(const bst_node *node, const data_ptr min, const data_ptr max);
static BOOLEAN bst_equals_helper(const bst_node *node1, const bst_node *node2);

//--------------------------------------------------------------------
// Local Static Helper Functions

/**
 * Initializes a new BST node with a copy of item.
 *
 * @param source - pointer to a BST source
 * @param item - pointer to the item to assign to the node
 * @return a pointer to a new BST node
 */
static bst_node* bst_node_initialize(const data_ptr item) {
    // Base case: add a new node containing a copy of item.
    bst_node *node = malloc(sizeof *node);
    node->item = malloc(sizeof *node->item);
    data_copy(node->item, item);
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Helper function to determine the height of node - handles empty node.
 * @param node - The node to process.
 * @return The height of the current node.
 */
static int bst_node_height(const bst_node *node) {
    int height = 0;

    if(node != NULL) {
        height = node->height;
    }
    return height;
}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 * @param node The node to process.
 */
static void bst_update_height(bst_node *node) {
    int left_height = bst_node_height(node->left);
    int right_height = bst_node_height(node->right);
    node->height = MAX(left_height, right_height) + 1;
    return;
}

/**
 * Inserts item into a BST. Insertion must preserve the BST definition.
 * item may appear only once in source.
 *
 * @param source - pointer to a BST
 * @param node - pointer to a node
 * @param item - the item to insert
 * @return - TRUE if item inserted, FALSE otherwise
 */
static BOOLEAN bst_insert_aux(bst_linked *source, bst_node **node, const data_ptr item) {
    BOOLEAN inserted = FALSE;

    if(*node == NULL) {
        // Base case: add a new node containing the item.
        *node = bst_node_initialize(item);
        source->count += 1;
        inserted = TRUE;
    } else {
        // Compare the node data_ptr against the new item.
        int comp = data_compare(item, (*node)->item);

        if(comp < 0) {
            // General case: check the left subsource.
            inserted = bst_insert_aux(source, &(*node)->left, item);
        } else if(comp > 0) {
            // General case: check the right subsource.
            inserted = bst_insert_aux(source, &(*node)->right, item);
        }
    }
    if(inserted) {
        // Update the node height if any of its children have been changed.
        bst_update_height(*node);
    }
    return inserted;
}

//--------------------------------------------------------------------
// Functions

// Initializes a BST.
bst_linked* bst_initialize() {
    bst_linked *source = malloc(sizeof *source);
    source->root = NULL;
    source->count = 0;
    return source;
}

// frees a BST.
void bst_free(bst_linked **source) {
    if (*source != NULL) {
        bst_free_helper((*source)->root);  // Corrected to use bst_free_helper
        (*source)->root = NULL;            // Set root to NULL after freeing nodes
        free(*source);                     // Free the BST structure
        *source = NULL;                    // Set the source pointer to NULL
    }
}

void bst_free_helper(bst_node *node) {
    if (node != NULL) {
        bst_free_helper(node->left);
        bst_free_helper(node->right);
        free(node->item);
        free(node);
    }
}

// Determines if a BST is empty.
BOOLEAN bst_empty(const bst_linked *source) {
    return source->root == NULL;
}

// Determines if a BST is full.
BOOLEAN bst_full(const bst_linked *source) {
    if (source->root == NULL) {
        return TRUE;
    }
    return bst_full_helper(source->root);
}

BOOLEAN bst_full_helper(bst_node *node) {
    if (node == NULL) {
        return TRUE;
    }
    if (node->left == NULL && node->right == NULL) {
        return TRUE;
    }
    if (node->left != NULL && node->right != NULL) {
        return bst_full_helper(node->left) && bst_full_helper(node->right);
    }
    return FALSE;
}

int bst_count(const bst_linked *source) {
    return source->count;
}

// Copies the contents of a BST to an array in inorder.
void bst_inorder(const bst_linked *source, data_ptr *items) {
    int index = 0;
    bst_inorder_helper(source->root, items, &index); // use address of index
}

void bst_inorder_helper(const bst_node *node, data_ptr *items, int *index) {
    if (node != NULL) {
        bst_inorder_helper(node->left, items, index);
        items[*index] = node->item;
        (*index) += 1;
        bst_inorder_helper(node->right, items, index);
    }
}

void bst_preorder(const bst_linked *source, data_ptr *items) {
    int index = 0;
    bst_preorder_helper(source->root, items, &index);
}
void bst_preorder_helper(const bst_node *node, data_ptr *items, int *index) {
    if (node != NULL) {
        items[*index] = node->item;
        (*index) += 1;
        bst_preorder_helper(node->left, items, index);
        bst_preorder_helper(node->right, items, index);
    }
}

// Copies the contents of a BST to an array in postorder.
void bst_postorder(const bst_linked *source, data_ptr *items) {
    int index = 0;
    bst_postorder_helper(source->root, items, &index);
}

void bst_postorder_helper(const bst_node *node, data_ptr *items, int *index) {
    if (node != NULL) {
        bst_postorder_helper(node->left, items, index);
        bst_postorder_helper(node->right, items, index);
        items[*index] = node->item;
        (*index)++;
    }
}

// Inserts a copy of an item into a BST.
BOOLEAN bst_insert(bst_linked *source, const data_ptr item) {
    return bst_insert_aux(source, &(source->root), item);
}

// Retrieves a copy of a value matching key in a BST.
BOOLEAN bst_retrieve(bst_linked *source, const data_ptr key, data_ptr item) {
bst_node *current = source->root;
    
    while (current != NULL) {
        int comparison = data_compare(key, current->item);
        
        if (comparison == 0) {  // key matches
            data_copy(item, current->item);
            return TRUE;
        } else if (comparison < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return FALSE;  // key not found
}

// Removes a value matching key in a BST.
BOOLEAN bst_remove(bst_linked *source, const data_ptr key, data_ptr item) {
    return bst_remove_aux(&(source->root), key, item);
}

// Helper function for bst_remove
BOOLEAN bst_remove_aux(bst_node **node, const data_ptr key, data_ptr item) {
    if (*node == NULL) {
        return FALSE;
    }

    int comparison = data_compare(key, (*node)->item);
    if (comparison < 0) {
        return bst_remove_aux(&(*node)->left, key, item);
    } else if (comparison > 0) {
        return bst_remove_aux(&(*node)->right, key, item);
    } else {  // Node to be removed found
        data_copy(item, (*node)->item);
        if ((*node)->left == NULL && (*node)->right == NULL) {  // No children
            free(*node);
            *node = NULL;
        } else if ((*node)->left == NULL) {  // Only right child
            bst_node *temp = *node;
            *node = (*node)->right;
            free(temp);
        } else if ((*node)->right == NULL) {  // Only left child
            bst_node *temp = *node;
            *node = (*node)->left;
            free(temp);
        } else {  // Two children
            bst_node *successor = (*node)->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            data_copy((*node)->item, successor->item);
            bst_remove_aux(&(*node)->right, successor->item, item);
        }
        return TRUE;
    }
}

// Copies source to target.
void bst_copy(bst_linked **target, const bst_linked *source) {

   *target = bst_initialize();
    bst_copy_helper(&(*target)->root, source->root);
}

// Helper function for bst_copy
void bst_copy_helper(bst_node **target_node, const bst_node *source_node) {
    if (source_node != NULL) {
        *target_node = bst_node_initialize(source_node->item);
        bst_copy_helper(&(*target_node)->left, source_node->left);
        bst_copy_helper(&(*target_node)->right, source_node->right);
    }
}

// Finds the maximum item in a BST.
BOOLEAN bst_max(const bst_linked *source, data_ptr item) {
    if (source->root == NULL) {
        return FALSE;
    }
    bst_node *current = source->root;
    while (current->right != NULL) {
        current = current->right;
    }
    data_copy(item, current->item);
    return TRUE;
}

// Finds the minimum item in a BST.
BOOLEAN bst_min(const bst_linked *source, data_ptr item) {

    if (source->root == NULL) {
        return FALSE;
    }
    bst_node *current = source->root;
    while (current->left != NULL) {
        current = current->left;
    }
    data_copy(item, current->item);
    return TRUE;
}


int bst_leaf_count(const bst_linked *source) {
    return bst_leaf_count_helper(source->root);
}

int bst_leaf_count_helper(const bst_node *node) {
    if (node == NULL) {
        return 0;
    } else if (node->left == NULL && node->right == NULL) {
        return 1;
    } else {
        return bst_leaf_count_helper(node->left) + bst_leaf_count_helper(node->right);
    }
}

// Finds the number of nodes with one child in a tree.
int bst_one_child_count(const bst_linked *source) {
    return bst_one_child_count_helper(source->root);
}

int bst_one_child_count_helper(const bst_node *node) {
    if (node == NULL) {
        return 0;
    } else if ((node->left == NULL) != (node->right == NULL)) {  // XOR: only one child
        return 1 + bst_one_child_count_helper(node->left) + bst_one_child_count_helper(node->right);
    } else {
        return bst_one_child_count_helper(node->left) + bst_one_child_count_helper(node->right);
    }
}

// Finds the number of nodes with two children in a tree.
int bst_two_child_count(const bst_linked *source) {
    return bst_two_child_count_helper(source->root);
}

int bst_two_child_count_helper(const bst_node *node) {
    if (node == NULL) {
        return 0;
    } else if (node->left != NULL && node->right != NULL) {
        return 1 + bst_two_child_count_helper(node->left) + bst_two_child_count_helper(node->right);
    } else {
        return bst_two_child_count_helper(node->left) + bst_two_child_count_helper(node->right);
    }
}

// Determines the number of nodes with zero, one, and two children.
// (May not call bst_leaf_count, bst_one_child_count, or bst_two_child_count.)
void bst_node_counts(const bst_linked *source, int *zero, int *one, int *two) {
    *zero = *one = *two = 0;
    bst_node_counts_helper(source->root, zero, one, two);
}

void bst_node_counts_helper(const bst_node *node, int *zero, int *one, int *two) {
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            (*zero)++;
        } else if ((node->left == NULL) != (node->right == NULL)) {
            (*one)++;
        } else {
            (*two)++;
        }
        bst_node_counts_helper(node->left, zero, one, two);
        bst_node_counts_helper(node->right, zero, one, two);
    }
}


// Determines whether or not a tree is a balanced tree.
BOOLEAN bst_balanced(const bst_linked *source) {
    return bst_balanced_helper(source->root) != -1;
}

int bst_balanced_helper(const bst_node *node) {
    if (node == NULL) return 0;

    int left_height = bst_balanced_helper(node->left);
    if (left_height == -1) return -1;

    int right_height = bst_balanced_helper(node->right);
    if (right_height == -1) return -1;

    if (abs(left_height - right_height) > 1) return -1;

    return 1 + MAX(left_height, right_height);
}


// Determines whether or not a tree is a valid BST.
BOOLEAN bst_valid(const bst_linked *source) {
    return bst_valid_helper(source->root, NULL, NULL);
}

BOOLEAN bst_valid_helper(const bst_node *node, const data_ptr min, const data_ptr max) {
    if (node == NULL) {
        return TRUE;
    }
    if ((min && data_compare(node->item, min) <= 0) || 
        (max && data_compare(node->item, max) >= 0)) {
        return FALSE;
    }
    return bst_valid_helper(node->left, min, node->item) &&
           bst_valid_helper(node->right, node->item, max);
}

// Determines if two trees contain same data in same configuration.
BOOLEAN bst_equals(const bst_linked *target, const bst_linked *source) {
    return bst_equals_helper(target->root, source->root);
}

BOOLEAN bst_equals_helper(const bst_node *node1, const bst_node *node2) {
    if (node1 == NULL && node2 == NULL) {
        return TRUE;
    } else if (node1 == NULL || node2 == NULL) {
        return FALSE;
    } else if (data_compare(node1->item, node2->item) != 0) {
        return FALSE;
    } else {
        return bst_equals_helper(node1->left, node2->left) &&
               bst_equals_helper(node1->right, node2->right);
    }
}

/**
 * Private helper function to print contents of BS in preorder.
 *
 * @param to_string - function to print data_ptr
 * @param node - pointer to bst_node
 */
static void bst_print_aux(bst_node *node) {
    char string[DATA_STRING_SIZE];

    if(node != NULL) {
        printf("%s\n", data_string(string, DATA_STRING_SIZE, node->item));
        bst_print_aux(node->left);
        bst_print_aux(node->right);
    }
    return;
}

// Prints the items in a BST in preorder.
void bst_print(const bst_linked *source) {
    printf("  count: %d, height: %d, items:\n", source->count, source->root->height);
    bst_print_aux(source->root);
    printf("\n");
    return;
}
