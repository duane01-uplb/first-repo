#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//2D array
//malloc

void removeNonAlpha(char *crushname){
	int j = 0;
	for(int i=0; crushname[i] != '\0'; i++){
		if ((crushname[i] >= 'a' && crushname[i] <= 'z') || (crushname[i] >= 'A' && crushname[i] <= 'Z')) {
            crushname[j++] = crushname[i];
        }
		}
		crushname[j] = '\0';
	}



int compareNames(char *userName, char *crushName){	
	int i,j,k;
	int remainingCharCount = 0, final_len = 0;
	char newUsername[50], newCrushName[50];

	removeNonAlpha(userName);
	removeNonAlpha(crushName);
	
	strcpy(newUsername, userName);
	strcpy(newCrushName, crushName);

	for(i=0; i<strlen(newUsername); i++){
		newUsername[i] = tolower(newUsername[i]);
	}
	for(i=0; i<strlen(newCrushName); i++){
		newCrushName[i] = tolower(newCrushName[i]);
	}

	for(i=0; newUsername[i] != '\0'; i++){ 
		for(j=0; newCrushName[j] != '\0'; j++){
			if(newUsername[i] == newCrushName[j]){
				for(k = i ; newUsername[k] != '\0'; k++){
					newUsername[k] = newUsername[k+1];
				}
				i--;
				for(k=j; newCrushName[k] != '\0'; k++){
					newCrushName[k] = newCrushName[k+1];
				}
				j--;
				break;
			}
		}
	}

	remainingCharCount = strlen(newUsername) + strlen(newCrushName);
			/*if(newCrushName[j] == newUsername[i]){
				newCrushName[j] = '-';
				newUsername[j] = '-';
				break;
			}
		}
	}

	for(i=0; i<strlen(newCrushName); i++){
		if(newCrushName[i] != '-'){
			remainingCharCount++;
		}
	}
	for(i=0; i<strlen(newUsername); i++){
		if(newUsername[i] != '-'){
			remainingCharCount++;
		}
	}*/

	return remainingCharCount;
	}

void flamesResult(int k, char *crushName, char *userName, int crushesAmt){
	int remainingChars = 0;
	removeNonAlpha(crushName);
	printf("\nCrush #%d: %s\n", k+1, crushName);
	//remainingChars = compareNames(userName, crushName);
	printf("Remaining character count: %d\n", remainingChars);
	printf("FLAMES result: \n\n");
}

int main(){
	char userName[50];
	char **crushArray;
	int crushesAmt = 0, choice, remainingChars = 0;
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
		printf("\n-----------------------------\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				char newName[50];

				crushArray = (char **)malloc(sizeof(char*)*crushesAmt);
				for(int i=0; i<crushesAmt; i++){
					crushArray[i] = (char *)malloc(sizeof(char)*50);
				}

				for(int i = 0; i<crushesAmt; i++){
					printf("Enter name of crush #%d: ", i+1);
					scanf(" %[^\n]%*c", newName);	
					strcpy(crushArray[i], newName);
					}
				break;
			case 2:
				if(crushArray == NULL){
					printf("\nInvalid choice! The array is still empty.\n\n");
				} else{
				for(i=0; i < crushesAmt; i++)
					flamesResult(i,crushArray[i], userName, crushesAmt);
				}
				break;
			case 0:
				printf("\nGoodbye!\n\n");
				break;	
			case 3:

			default:
				printf("\nInvalid choice!\n\n");
		}
	}while(choice != 0);
	for(int i=0; i<crushesAmt; i++){
		free(crushArray[i]);
	}
	free(crushArray);
		return 0;
} 