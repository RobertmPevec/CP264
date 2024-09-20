/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Source Code File
 * -------------------------------------
 * @Robert Pevec, 169081145, peve1145@mylaurier.ca
 *
 * @version 2024-01-06
 *
 * -------------------------------------
 */
#include "by_index.h"

void fill_values_by_index(int values[], int size) {

    for(int i = 0; i < size; i++) {
        values[i] = i + 1;
    }
}

void fill_squares_by_index(int values[], long int squares[], int size) {
    int i;
    for (i = 0; i < size; i++)   {
        squares[i] = values[i] * values[i];
    }
}

void print_by_index(int values[], long int squares[], int size) {
    printf("Value  Square\n");
    printf("-----  ----------\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%-5d  %-10ld\n", values[i], squares[i]);
    }
}
