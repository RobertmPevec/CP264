/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2023-09-09
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
    int a, b, c;
    char buffer[100];
    while (1) {
        printf("Enter three comma-separated integers: ");
        fgets(buffer, 100, stdin);
        if (sscanf(buffer, "%d , %d , %d", &a, &b, &c) == 3) {
            return a + b + c;
        } else {
            printf("The integers were not properly entered.\n");
        }
    }
}