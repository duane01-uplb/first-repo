#include <stdio.h>
#include <math.h>
#include <stdlib.h>



// Function to compute the Pearson correlation coefficient
void printMatrix(double *column1, double *column2){
    int num_rows = 11, num_cols = 5;
    double mat[11][5];

    for(int i=0; i<10; i++){
        mat[i][0] = column1[i];
        mat[i][1] = column2[i];
        }

    for(int i=0; i<5; i++){
        for(int j=0; j<10; j++){
            mat[10][i] += mat[j][i];
        }
    }

    printf("\n----------------------------------------------------------------------------------------------------------\n");
    printf("x\t\t|\ty\t\t|\tx^2\t\t|\ty^2\t\t|\txy\n"); 
    printf("----------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<10; i++){
        printf("%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t\n", mat[i][0],mat[i][1],mat[i][0]*mat[i][0],mat[i][1]*mat[i][1],mat[i][0]*mat[i][1]); 
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
    
    printf("%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t\n",mat[10][0],mat[10][1],mat[10][2],mat[10][3],mat[10][4]);
    printf("----------------------------------------------------------------------------------------------------------\n");
}

// Function to compute the Pearson correlation coefficient
/*double pearson_correlation(double *column1, double *column2) {
    	//code here
  
    

    printMatrix(__________);


    return numerator / denominator;
} */

int main() {
    // Define the arrays for the first and second columns
    double column1[] = {3.63, 3.02, 3.82, 3.42, 3.59, 2.87, 3.03, 3.46, 3.36, 3.3};
    double column2[] = {53.1, 49.7, 48.4, 54.2, 54.9, 43.7, 47.2, 45.2, 54.4, 50.4};
    
    
    // Determine the number of rows (assumed both columns have the same length)
    int num_rows = 10;

    // Print the array with 2 columns
    printf("Weight(Kg) Length(cm))\n");
    for(int i = 0; i<num_rows; i++){
        printf("%.2f\t\t%.1f\n", column1[i], column2[i]);
    }

    printMatrix(column1, column2);

    return 0;

    


    // Calculate Pearson correlation coefficient
    double correlation = pearson_correlation(column1, column2);
    printf("Pearson Correlation Coefficient: %.2f\n\n", correlation);

    //print interpretation here

    return 0;
}