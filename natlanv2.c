#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 512


void compile(int flag);
void goTo();
void currentTime();
void date();

int main(){

	int gccFlag = 0;
	system("cls");
	printf("\n\t------    WELCOME TO NATLAN     ------");
	printf("\n\t- NATURAL LANGUAGE COMMAND INTERFACE -\n");
	printf("\n\tTo bring up commands, type \"commands\"");
	printf("\n\tHello! I am Natlan. How may I assist you? (format: Natlan, ....)\n");
	
	char sent[100];
	char natlanW[50] = "Natlan";

	while(!(strstr(sent,"quit") !=NULL)){
		printf("\n\tEnter command:\n\t-> ");
		scanf ("%[^\n]%*c", sent);
		if(strstr(sent,"compile")!=NULL){
			if(strstr(sent, "gcc")!=NULL){
				gccFlag = 1;
			}
			compile(gccFlag);
		}else if((strstr(sent,"go to")) || (strstr(sent,"open")) || (strstr(sent,"go"))!=NULL){
			goTo();
		}else if((strstr(sent, "help")) || (strstr(sent, "commands")) !=NULL){
			//helpMenu();
			printf("showing commands");
		}
		else if((strstr(sent, "time")) || (strstr(sent, "Time")) || (strstr(sent, "TIME")) !=NULL){
			currentTime();
		}
		else if((strstr(sent, "date")) || (strstr(sent, "Date")) || (strstr(sent, "DATE")) || (strstr(sent, "Day")) || (strstr(sent, "day")) || (strstr(sent, "DAY")) !=NULL){
			date();
		}		
		else if(!(strstr(sent,"quit") !=NULL)){
			printf("\n\tCommand unrecognized.\n");
		}
	}
	printf("\n\tGoodbye. Have a nice day!\n");
	
	return 0;
}

void compile(int flag){
	int i = 0;
	char fName[50], cCommand[50];
	if(flag){
		strcpy(cCommand, "gcc ");
	}else{
		strcpy(cCommand, "tcc ");
	}
	printf("\n\tEnter the name of the file: \n\t-> ");
	fgets(fName, 50, stdin);
	fflush(stdout);
	strcat(cCommand, fName);
	printf("\n\tCompiling...\n\t");
	if(system(cCommand) == '\0'){
		printf("\n\tCompiled!\n");
	}
}

void goTo(){
	char cCommand2[50];
	char fName[50];
	strcpy(cCommand2, "START ");
	printf("\n\tEnter the name of directory or web address: \n\t-> ");
	fgets(fName, 50, stdin);
	fflush(stdout);
	strcat(cCommand2, fName);
	printf("\n\tGoing to %s", fName);
	system(cCommand2);
}

void currentTime(){
	char timedate[SIZE];
  	time_t curtime;
  	struct tm *loctime;

  	curtime = time (NULL);
  	loctime = localtime (&curtime);
  	strftime (timedate, SIZE, "\n\tThe time is %I:%M %p.\n", loctime);
  	fputs (timedate, stdout);
}

void date(){
	char timedate[SIZE];
  	time_t curtime;
  	struct tm *loctime;

  	curtime = time (NULL);
  	loctime = localtime (&curtime);
  	strftime (timedate, SIZE, "\n\tToday is %A, %B %d.\n", loctime);
  	fputs (timedate, stdout);	
}

/*void googleSearch(){
	char cCommand3[50];
	char fName[50];
	printf("\n\tEnter your search: \n\t-> ");
	fgets(fName, 50, stdin);
	fflush(stdout);
	strcat
}
*/

/* void weather(){
	
}
*/

/*
void helpMenu(){
	printf("\n\t------   NATLAN COMMAND MENU    ------");
	printf("\n\t-compile: Compiles the file. Uses tcc as compiler by default unless you specify it to use gcc");

}*/