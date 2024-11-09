#include <stdio.h>
void naturalnumbers() {
    int capacity = 100;
    for (int current = 1; current <= capacity; current += 1) {
        printf("Natural Number: %d\n", current);
    }
}