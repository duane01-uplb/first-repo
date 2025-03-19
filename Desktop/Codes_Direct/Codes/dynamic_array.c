#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
    int **matrix;
    int rows, columns;
    char *dynamic_str;

    printf("Size of the matrix: ");
    scanf("%d", &rows);
    printf("Number of columns: "); 
    scanf("%d", &columns);

    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i=0; i<rows; i++){
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("Enter the element at position %d, %d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}