#include <stdio.h>
#include <math.h>
#include <stdlib.h>



// Function to compute the Pearson correlation coefficient
void printMatrix(double mat[11][5]){   //mat is the parameter along with the size for easier printing of the matrix 

    printf("\n----------------------------------------------------------------------------------------------------------\n");
    printf("x\t\t|\ty\t\t|\tx^2\t\t|\ty^2\t\t|\txy\n"); 
    printf("----------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<10; i++){    // this will loop through the rows in the matrix without the sum of cross products so it is just 10
        printf("%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t\n", mat[i][0],mat[i][1],mat[i][2],mat[i][3],mat[i][4]);    //mat[i][0 ...] since we were looping through the row, we should assign i to the first index of each mat.
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
    
    printf("%.2f\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\t|\t%.2f\t\t\n",mat[10][0],mat[10][1],mat[10][2],mat[10][3],mat[10][4]);  //since we only have one row, we will only change the index of the column part
    printf("----------------------------------------------------------------------------------------------------------\n");
}

// Function to compute the Pearson correlation coefficient
double pearson_correlation(double *column1, double *column2) {  //columns 1 and 2 are needed as parameters to create another array for the matrix
    int num_rows = 11, num_cols = 5;    //initializes the  number of rows and columns needed. 11 rows including the sum of cross products and 5 columns for the matrix
    double mat[11][5];                  //creates a 2D array named mat with 11 rows and 5 columns

    for(int i=0; i<10; i++){            //will handle the first 10 rows of the matrix for easier code management and readability 
        mat[i][0] = column1[i];                 //assign the i in column to its i equivalent in the row matrix 
        mat[i][1] = column2[i];                 //assign the i in column to its i equivalent in the row matrix 
        mat[i][2] = column1[i]*column1[i];      //assign the ith-row 3rd column in the matrix to the self-product of the ith-row in column1 
        mat[i][3] = column2[i]*column2[i];      //assign the ith-row 4th column in the matrix to the self-product of the ith-row in column2
        mat[i][4] = column1[i]*column2[i];      //assign the ith-row 5th column in the matrix to the product of the ith-row in column2 and ith-row in column1
        }
 
    for(int i=0; i<5; i++){            //initialize to less than 5 since we need to do each columns for the cross product
        for(int j=0; j<10; j++){       //before looping line 35, we must ensure that we have added all elements in the column first
            mat[10][i] += mat[j][i];    /*since the first index is 10,
             we will just focus on the 10th row but will gradually 
             change the second index. Since we initialized the nested 
             for loop to 10, it will go to every jth-row and ith-column in the
             matrix first, and add them to the current ith-column in the 10th row.*/
        }
    }
    
    //formula for pearson correlation coefficient
    double numerator = 10 * mat[10][4] - (mat[10][0] * mat[10][1]);
    double denominator = sqrt((10 * mat[10][2] - mat[10][0] * mat[10][0]) * (10 * mat[10][3] - mat[10][1] * mat[10][1]));

    printMatrix(mat);   //calls printMatrix with the array mat as the parameter to print the matrix

    return numerator / denominator;        //returns the answer of the pearson correlation coefficient
}

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

    // Calculate Pearson correlation coefficient
    double correlation = pearson_correlation(column1, column2);
    printf("Pearson Correlation Coefficient: %.2f\n\n", correlation);
    if (correlation > 0.5){
        printf("The correlation is strongly positive\n");
    } else if (correlation < 0.5){
        printf("The correlation is moderately positive\n");
    } else if (correlation < 0.3){
        printf("The correlation is weakly positive\n");
    } else if (correlation == 0){
        printf("There is no correlation\n");
    } else if (correlation > -0.3){
        printf("The correlation is weakly negative\n");
    } else if (correlation > -0.5){
        printf("The correlation is moderately negative\n");
    } else if (correlation < -0.5){
        printf("The correlation is strongly negative\n");
    }

    return 0;
}