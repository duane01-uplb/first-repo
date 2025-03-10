//Duane Jordan S. Mendoza
//2024-04673
//Exercise 5 - Parameter Passing

#include<stdio.h>

int getInput(int *x, int *y);
void swapValues(int *x, int *y);
int primeChecker(int x);
void getLargest(int x, int y, int *largest1, int *largest2, int *largest3);
void printLargest(int largest1, int largest2, int largest3);

int main(){
    int x = 0, y = 0, largest1 = 0, largest2 = 0, largest3 = 0;     //initialize the variables to 0 to avoid passing wrong values
    /*this if function (line 16) checks whether the getInput function returns the value of 1 and 0.
    if it returns 1, the function is true thus, the next functions under it will go through. */
    if(getInput(&x, &y)){   //the parameters for getInput are the addresses of x and y as we will change their values from 0 as we initialized in line 14
        swapValues(&x, &y); 
        getLargest(x,y,&largest1,&largest2,&largest3);
        printLargest(largest1, largest2, largest3); 
    }                                                             
    else return 0;
}

int getInput(int *x, int *y){                                       //the parameters are pointers as we will use them to change the initial values of x and y
    int input1, input2;                                             //for checking purposes only

    printf("Enter x: ");
    scanf("%d", &input1);
    printf("Enter y: ");
    scanf("%d", &input2);
    if (input1 < 2 && input2 < 2){                                 //if both inputs are less than 2, prints invalid range as it will violate the program
        printf("Invalid Range!\n");
        return 0;
    } else {                                                       //else, it will change the value in the address of x to the inputs.
        *x = input1;
        *y = input2;
        return 1;
    }
}

void swapValues(int *x, int *y){                                   //again, we will change the values of x and y so we need to assign the parameter pointing to the address of x and y
    int temp = 0;                                                  //temporary variable (for swapping)

    if (*x > *y){                                                  //if x is less than y, then swap
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

int primeChecker(int x){                                           //to check if the current number is prime (this is for the get largest loop in line 63)
    if (x < 2)                                                     //checks if x is 1 or below, returns 0 so it will not be included in the getLargest loop in line 63
     return 0;    
    /*always starts at 2, then multiplies 2 to itself to compare it to the current x, 
    since non-prime numbers have factors starting from 2 and above. Incrementing the i
    means that we are finding the potential factor of x while still prioritizing efficiency.*/                                                  
    for (int i = 2; i * i <= x; i++){                              
        if(x % i == 0)                                            //if x is divisible by the current i, it is non-prime thus returns 0
          return 0;
    }
    return 1;
}


void getLargest(int x, int y, int *largest1, int *largest2, int *largest3){ //uses normal parameters for x and y since we will not change them here (just for reference), while largest variables are pointers as we will change them throughout the function
    for(int i=x; i<=y; i++){                                    //starting from x which is supposed to be lower than y, loops until i reaches y due to incremention.
        if(primeChecker(i)){                                    //if the primeChecker() function returns true, continues with the condition
            if (i > *largest1){                                 //if the current i is larger than the 1st largest, it will execute a swap function among all three largest numbers to avoid passing negative or trash values
                *largest3 = *largest2;
                *largest2 = *largest1;
                *largest1 = i;
            }
        }
    }
} 

void printLargest(int largest1, int largest2, int largest3){        //normal variables as we will only print and not change any value here
    if (largest2 == 0 && largest3 == 0){                            //if both largest2 and largest3 is 0, prints only one is prime number (no prime number is already handled in line 33
        printf("There is one prime number: %d\n", largest1);
    } else if (largest3 == 0){                                      //if only largest3 is 0, that means largest1 and 2 has values, thus it prints 2 prime numbers are present
        printf("There are two prime numbers: %d %d\n", largest1, largest2);
    }
    else {                                                         //if all of them are not 0, prints the three largest number after the loop in line 66
        printf("The three largest prime numbers are: %d %d %d\n", largest1, largest2, largest3);
    }
}