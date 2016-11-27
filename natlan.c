#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void compile();

int main(){
	printf("\n\t------    WELCOME TO NATLAN     ------");
	printf("\n\t- NATURAL LANGUAGE COMMAND INTERFACE -\n");
	printf("\n\tTo bring up commands, type \"commands\"");
	printf("\n\tHello! I am Natlan. How may I assist you? (format: Natlan, ....)\n\t-> ");
	
	char sent[100];
	char word[50] = "compile";
	char natlanW[50] = "Natlan";
	scanf ("%[^\n]%*c", sent);
\
	if(strstr(sent,natlanW)!=NULL){
		if(strstr(sent,word)!=NULL)
			compile();
	}	
	
	return 0;
}

void compile(){
	int i = 0;
	printf("\n\tCompiling. Please wait");
	for(i=0; i<3; i++){
		printf(".");
		sleep(500);
	}
	printf("\n\t");
	if(system("tcc test.c") == NULL){
		printf("\n\tCompiled!\n");
	}
}