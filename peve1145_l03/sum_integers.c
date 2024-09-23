/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {
    printf("Enter integers, one per line:\n");
    int number = 0;
    _Bool input = 1;
    while (input) {
        int enter;
        int result = scanf("%d", &enter);
        if (result == 1) {
            number += enter;
            while (getchar() != '\n');
        } else {
            input = 0;
            while (getchar() != '\n');
        }
    }
    return number;
}
