#include <stdio.h>
void main() {
    int a = 2;
    int b = 5;
    while(a < 6) {
        a += 2;
        printf("a: %d ", a);
    }
    do {
        printf("b: %d ", b);
        b -= 2;
    } while (b >= 2);
    printf("b: %d");
}

void printTriangle(char* str) {
    int len = strlen(str);
    for (int i = 0; i <= len - 1; i += 1) {
        printf("%.*s\n", i, str);
    }
}

int printtriangle() {
    char input[21];
    scanf("%20s", input);
    printTriangle(input);
    return 0; 
}

#define SIZE 2 

struct EMPLOYEE {
    int ID;
    int AGE;
    double Salary;
};
int main2() {
    struct Employee emp[SIZE] = {0};
    printf("1. Display Employee Information\n");
    printf("2. Add Employee\n");
    printf("0. Exit")
    
}
