#include <stdio.h>
// yo prof wtf is this kinda waste of my bare time homie
void main() {
    int x = 2;
    int y = 3;
    if (x < 10) {
        printf("A");
        if (y > 10) {
            printf("B\n");
        } else {
            printf("C\n");
        }
        printf("D");
    } else if (y > 10) {
        printf("E\n");
    } else {
        printf("F\n");
        printf("G\n");
        printf("H\n");
    }
}