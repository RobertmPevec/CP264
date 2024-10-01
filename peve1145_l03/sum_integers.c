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
#include <ctype.h>

int sum_integers(void) {
    printf("Enter integers, one per line:\n");
    int sum = 0;
    _Bool trueorfalse = 1;
    while (trueorfalse) {
        int i = 0;
        char str[100] = { };
        char ch = getchar();
        while (ch != '\n') {
            str[i] = ch;
            i++;
            ch = getchar();
        }
        char rChar = str[0];
        if (isdigit(rChar)) {
            sum += (rChar - 48);
        } else {
            trueorfalse = 0;
        }
    }
    return sum;
}