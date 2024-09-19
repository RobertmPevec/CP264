/**
 * -------------------------------------
 * @file  by_ptr.c
 * Lab 2 Pointer Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-06
 *
 * -------------------------------------
 */
#include "by_ptr.h"

void fill_values_by_ptr(int *values, int size) {

    for(int i = 0; i < size; i++) {
        *(values + i) = i + 1;
    }
}

void fill_squares_by_ptr(int *values, long int *squares, int size) {
for(int i = 0; i < size; i++) {
    *(values + i) = (long int)(*(values + i)) * (*(values + i));
    // we are looping through the entire array then calculating and asigning the value to squares in range of size
    }
}

void print_by_ptr(int *values, long int *squares, int size) {
    printf("Value  Square\n");
    printf("-----  ----------\n");
    for (int i = 0; i < size; i++) {
        printf("%-5d  %-10ld\n", *(values + i), *(squares + i));
    }
}
