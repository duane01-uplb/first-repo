#include <stdio.h>

int pointer(int *x, int *y){
    printf("Please enter a new integer for x: ");
    scanf("%d", x);
    printf("Please enter a new integer for y: ");
    scanf("%d", y);
}

int swap(int *x, int *y){
    int temp = *x;

    *x = *y;
    *y = temp;
}

int main() {
    int x,y;
    
    printf("Please enter an integer: ");
    scanf("%d", &x);
    printf("Please enter another integer: ");
    scanf("%d", &y);
    printf("The current integers are %d and %d\n\n", x,y);
    printf("Their addresses are %p and %p\n\n", &x,&y);
    pointer(&x, &y);
    printf("Now the integers are %d and %d.\n\n", x,y);
    swap(&x, &y);
    printf("Now the integers are %d and %d.\n\n", x,y);
    return 0;
}