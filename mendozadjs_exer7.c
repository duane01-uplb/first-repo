#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//2D array
//malloc




int main(){
	char userName[50];
	char **crushArray;
	int crushesAmt, choice;
	int i,j;
	
	printf("Enter your name: ");
	scanf("%s", userName);
	printf("Enter the number of your crushes: ");
	scanf("%d", &crushesAmt);

	do{	

		printf("-----------------------------\n\n");
		printf("[1] Input Names\n");
		printf("[2] Compute FLAMES result\n");
		printf("[0] Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		printf("\n-----------------------------\n");

		switch(choice){
			case 1:
				char newName[50];

				crushArray = (char **)malloc(sizeof(char*)*crushesAmt);
				for(int i=0; i<crushesAmt; i++){
					crushArray[i] = (char *)malloc(sizeof(char)*50);
				}

				for(int i = 0; i<crushesAmt; i++){
					printf("Enter name of crush #%d:", i+1);
					scanf("%s", newName);
					for(int j=0; j<strlen(newName); j++){
						if(isalpha(newName[j])){
								crushArray[i][j] = tolower(newName[j]);
							}
					//for(int j=0; j<strlen(newName); j++){
					//		crushArray[i][j] = tolower(newName[j]);
					//		}
					//	}
					}
				}

				for(i = 0; i<crushesAmt; i++){
					printf("%s\n", &crushArray[i][j]);
				}

				for(int i=0; i<crushesAmt; i++){
					free(crushArray[i]);
				}
				free(crushArray);

		}

	 }
	while(choice != 0);

	return 0;
}