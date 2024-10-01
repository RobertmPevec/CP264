/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include "functions.h"
#include <string.h>

void strings_with_substring(strings_array *data, char *substr) {
    int i = 0;
    while (i < data->lines) {
        if (strstr(data->strings[i], substr) != NULL) {
            printf("%s\n", data->strings[i]);
        }
        i += 1;
    }
}