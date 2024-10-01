/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {
    int index = 0;
    printf("Enter %d values for an array of int.\n", size);
    while (index < size) {
        printf("Value for index %d: ", index);
        int numbers;
        int result = scanf("%d", &numbers);
        if (result == 1) {
            array[index] = numbers;
            index += 1;
        } else {
            printf("Not a valid integer. Please try again.\n");
            while (getchar() != '\n');
        }
    }
}