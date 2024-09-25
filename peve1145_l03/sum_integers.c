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
    printf("Enter integers, one per line: \n");

    int sum = 0;

    while (1) {
        int i = 0;
        char str[100] = {};
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
            break;
        }
    }

    return sum;
}