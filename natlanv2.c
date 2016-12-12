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

	int gccFlag = 0, i = 0;
	system("cls");
	printf("\n\t------    WELCOME TO NATLAN     ------");
	printf("\n\t- NATURAL LANGUAGE COMMAND INTERFACE -\n");
	printf("\n\t(Type help or commands to bring up list of commands)");
	printf("\n\tHello! I am Natlan. How may I assist you?\n");
	
	char sent[100];
	char natlanW[50] = "Natlan";

	while(!(strstr(sent,"quit") !=NULL)){
		printf("\n\tEnter command:\n\t-> ");
		scanf ("%[^\n]%*c", sent);
		while(sent[i]!='\0'){
			if(sent[i]>64 && sent[i]<91){
				sent[i]=sent[i]+32;
			}
			i++;
		}
		if(strstr(sent,"compile")!=NULL){
			if(strstr(sent, "gcc")!=NULL){
				gccFlag = 1;
			}
			compile(gccFlag);
		}else if((strstr(sent,"go to")) || (strstr(sent,"open")) || (strstr(sent,"go"))!=NULL){
			goTo();
		}else if((strstr(sent, "help")) || (strstr(sent, "commands")) !=NULL){
			//helpMenu();
		}
		else 
			if((strstr(sent, "time")) !=NULL){
				currentTime();
			}
			if((strstr(sent, "date")) || (strstr(sent, "day")) !=NULL){
				date();
			}		
		else if(!(strstr(sent,"quit")||strstr(sent,"time") !=NULL)){
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
  	strftime (timedate, SIZE, "\n\tToday is %A, %B %d, 2016.\n", loctime);
  	fputs (timedate, stdout);	
}
/*
void googleSearch(){
	char cCommand3[50];
	char fName[50];
	strcpy(cCommand2, "START http://www.google.com/");
	printf("\n\tEnter the name of directory or web address: \n\t-> ");
	fgets(fName, 50, stdin);
	fflush(stdout);
	strcat(cCommand2, fName);
	printf("\n\tGoing to %s", fName);
	system(cCommand2);
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