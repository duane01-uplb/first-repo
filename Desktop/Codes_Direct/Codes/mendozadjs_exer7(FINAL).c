#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//2D array
//malloc

void removeNonAlpha(char *crushname){		//removes nonalphacharacters, and pushes them to the left. '\0' goes to the first index.
	int j = 0;
	for(int i=0; crushname[i] != '\0'; i++){
		if ((crushname[i] >= 'a' && crushname[i] <= 'z') || (crushname[i] >= 'A' && crushname[i] <= 'Z') || (crushname[i] == ' ')) {
            crushname[j++] = crushname[i];
        }
		}
		crushname[j] = '\0';
}

int compareNames(char *userName, char *crushName){	//removing comparing two strings(crush and user)
	int i,j,k;
	int remainingCharCount = 0;
	char newUsername[50], newCrushName[50];	//for safety purposes not to change the original names

	removeNonAlpha(userName);			//removes nonalpha characters in username
	removeNonAlpha(crushName);			//removes nonalpha characters in crushname
	
	strcpy(newUsername, userName);		//copies username to newusername
	strcpy(newCrushName, crushName);	//copise crushname to newcrushname

	for(i=0; i<strlen(newUsername); i++){				//lowercases every letter in the string
		newUsername[i] = tolower(newUsername[i]);
	}
	for(i=0; i<strlen(newCrushName); i++){
		newCrushName[i] = tolower(newCrushName[i]);
	}

	for(i = 0; newUsername[i] != '\0'; i++) { 			//loops through newUsername's letters, again, != '\0' ensures that the whole string gets checked
		for(j = 0; newCrushName[j] != '\0'; j++) {		//loops through newCrushName's letters
			if(newCrushName[j] == newUsername[i]) {				//if the letter in newcrushname is equal to the letter pnewusername[i], initializes the next step
				for(int k = j; newCrushName[k] != '\0'; k++) {	//k is used since we already used i and j (all are indices). This check is for the newCrushName (every letter)
					newCrushName[k] = newCrushName[k+1];        
				}
				for(int k = i; newUsername[k] != '\0'; k++) {	/*k is used since we already used i and j (all are indices). 
                    This check is for the newUserName (every letter) 
                    Notice that the initialization changed because we are now 
                    comparing it to the outermost loop as it must only change username.*/
					newUsername[k] = newUsername[k+1];
				}
				i = 0;									//set i to 0 again to get the next letter
				break; 
			}
		}
	}

	remainingCharCount = strlen(newUsername) + strlen(newCrushName);

	return remainingCharCount;
	}

char computeForFlames(int remainingChars){	//computing for the FLAMES part
	char flames[] = "FLAMES";
	int removeChar;

	for(int i=0; i<5; i++){ /*we need to keep one letter so we 
		will just need to loop 5 times and return the final letter that will be left*/
		removeChar = remainingChars % strlen(flames);	/*we divide the remainingChars to 
		the length of the flames array in line 58 to get which index we will remove.*/
		if (removeChar == 0) {	
			removeChar = strlen(flames);	/*if the answer is 0, we need to
			go back to the last letter since it means that the remainingChars is divisible by 6 and
			it went through all the letters.*/
		}
		removeChar - 1; /*since we used strlen in line 65, and C is 0-based indexing, we need to minus 
		1 to get the accurate place of the letter we will be removing.*/

		for (int j = removeChar; j < strlen(flames) - 1; j++) {		/*remove the remaining
			letters to get the final letter in the array of FLAMES.*/
			flames[j] = flames[j + 1];	//adjusting the letters to ignore the supposedly removed ones
		}
		
			//ensures that the last index is set to NULL
	}


	return flames[0];	//since all "removed" letters are pushed, the first index will always be the last remaining letter.
	}

void flamesResult(int k, char *crushName, char *userName, int crushesAmt){      //printing purposes of FLAMES
	int remainingChars = 0;

	removeNonAlpha(crushName);
	printf("\nCrush #%d: %s\n", k+1, crushName);

	remainingChars = compareNames(userName, crushName);                   //variable initialization for next steps
	printf("Remaining character count: %d\n", remainingChars);

	char FLAMES_RESULT = computeForFlames(remainingChars);              //just for switch case
	switch(FLAMES_RESULT){
		case 'F':
			printf("FLAMES result: FRIENDS\n\n");
			break;
		case 'L':
			printf("FLAMES result: LOVE\n\n");
			break;
		case 'A':
			printf("FLAMES result: AFFECTION\n\n");
			break;
		case 'M':
			printf("FLAMES result: MARRIAGE\n\n");
			break;
		case 'E':
			printf("FLAMES result: ENEMY\n\n");
			break;
		case 'S':
			printf("FLAMES result: SIBLINGS\n\n");
			break;
	}
	
	
}

int main(){
	char userName[50];
	char **crushArray;
	int crushesAmt = 0, choice, remainingChars = 0;
	int i,j;
	
	printf("Enter your name: ");
	scanf("%[^\n]%*c", userName);                       //[^\n] is for the space handling
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
				if(crushArray == NULL){             //if array has not taken an input from line 138, it will print invalid
					printf("\nInvalid choice! The array is still empty.\n\n");
				} else{
				for(i=0; i < crushesAmt; i++)
					flamesResult(i,crushArray[i], userName, crushesAmt);        //i is included for counting purposes when printing
				}
				break;
			case 0:
				printf("\nGoodbye!\n\n");
				break;	
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