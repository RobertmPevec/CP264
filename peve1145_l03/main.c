/**
 * -------------------------------------
 * @file  main.c
 * Lab 3 Testing Source Code File
 * -------------------------------------
 * @author name, id, email
 * @version 2024-01-25
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SMALL 18
#define STRING_BIG 256

// Function declarations
int sum_integers(void);
int sum_three_integers(void);
void int_array_read(int *array, int size);
static char* int_array_string(char *buffer, size_t size, int *source, int count);

// Function implementations
int sum_integers(void) {
    printf("Enter integers, one per line (non-integer to exit):\n");
    int sum = 0;
    _Bool input = 1;

    while (input) {
        int enter;
        int result = scanf("%d", &enter);

        if (result != 1) {
            input = 0;  // Exit the loop on invalid input
            while (getchar() != '\n');  // Clear the input buffer
        } else {
            sum += enter;  // Add the valid integer to the sum
        }
    }

    return sum;
}

int sum_three_integers(void) {
    int a, b, c;
    printf("Enter three integers:\n");
    scanf("%d %d %d", &a, &b, &c);
    return a + b + c;
}

void int_array_read(int *array, int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

static char* int_array_string(char *buffer, size_t size, int *source, int count) {
    // Temporary string buffer for array items
    char item[STRING_SMALL];
    strncpy(buffer, "{", STRING_SMALL);

    for(int i = 0; i < (count - 1); i++) {
        sprintf(item, "%d, ", source[i]);
        strncat(buffer, item, STRING_SMALL);
    }
    if(count > 0) {
        sprintf(item, "%d", source[count - 1]);
        strncat(buffer, item, STRING_SMALL);
    }
    strncat(buffer, "}", STRING_SMALL);
    return buffer;
}

// Test functions
static void test_sum_integers(void) {
    printf("Test: sum_integers\n\n");
    int sum = sum_integers();
    printf("Sum: %d\n\n", sum);
}

static void test_sum_three_integers(void) {
    printf("Test: sum_three_integers\n\n");
    int sum = sum_three_integers();
    printf("Sum: %d\n\n", sum);
}

static void test_int_array_read(void) {
    printf("Test: int_array_read\n\n");
    char buffer[STRING_BIG];
    int size = 4;
    int array[size];
    int_array_read(array, size);
    printf("%s\n", int_array_string(buffer, sizeof(buffer), array, size));
}

/**
 * Test the Lab 3 input functions.
 *
 * @param argc - count of elements in args
 * @param args - array of strings passed on command line
 * @return EXIT_SUCCESS
 */
int main(int argc, char *args[]) {
    setbuf(stdout, NULL);

    test_sum_integers();
    test_sum_three_integers();
    test_int_array_read();

    return EXIT_SUCCESS;
}