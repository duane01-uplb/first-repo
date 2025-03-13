#include <stdio.h>
#include <stdlib.h>



int main() {
    float *grades;
    int i, size = 3, choice = 0;

    grades = (float *) malloc(sizeof(float) * size);
    //skibidi
    while (choice != 1){
    for(i=0; i<size; i++) {
        printf("Enter grade %d: ", i+1);
        scanf("%f", &grades[i]);
    }
    for(i=0; i<size; i++) {
        printf("Grade %d: %.2f\n", i+1, grades[i]);
    }
    printf("Do you want to continue? (0/1): ");
    scanf("%d", &choice);
    }

    free(grades);
    return 0;
}