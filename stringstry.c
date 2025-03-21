
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void removeNonAlpha(char *newName){
	for(int i=0; i<strlen(newName); i++){
		if(isalpha(newName[i])){
			printf("True");
		} else {
			printf("False");
		}
	}
}

int main() {

char newName[50] = "Hel*333332lo";
removeNonAlpha(newName);
return 0;

}



/*if (isupper(name[i])){
	name[i] = Tolower(name[i]);			
}



*/


//remove same characters (1:1)