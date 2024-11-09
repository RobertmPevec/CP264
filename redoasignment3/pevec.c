#include <stdio.h>

int main()
{
    int sum = 0;
    _Bool trueorfalse = 0;
    while (trueorfalse)
    {
        int temp;
        printf("Write an integer");
        temp = scanf("\n");
        if (temp == 0)
        {
            trueorfalse = 1;
        }
        else
        {
            sum += temp;
        }
    }
    return sum;
}