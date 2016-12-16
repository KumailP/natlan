#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 512

void printIntro();
void executeCommand(char sent[]);
void getSentence(char sent[]);
void compile(int flag);
void goTo();
void currentTime();
void date();
void weather(char sent[]);
void hostName();

int main(){
	int i = 0;
	char sent[100];

	printIntro();
	while(!(strstr(sent,"quit") !=NULL)){
		getSentence(sent);
		executeCommand(sent);
	}
	printf("\n\tGoodbye. Have a nice day!\n");
	
	return 0;
}

void printIntro(){
	system("cls");
	printf("\n\t------    WELCOME TO NATLAN     ------");
	printf("\n\t- NATURAL LANGUAGE COMMAND INTERFACE -\n");
	printf("\n\tTo bring up commands, type \"commands\"");
	printf("\n\tHello! I am Natlan. How may I assist you?\n");
}

void executeCommand(char sent[]){
	int gccFlag = 0;
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
	else
		if((strstr(sent, "time")) !=NULL){
			currentTime();
		}
		if((strstr(sent, "date")) || (strstr(sent, "day")) !=NULL){
			date();
		}
	else if(strstr(sent, "weather") != NULL){
		weather(sent);
	}
	else if((strstr(sent, "pc")!=NULL) && (strstr(sent, "name")!=NULL)){
		hostName();
	}		
	else{
		printf("\n\tCommand unrecognized.\n");
	}
}

void getSentence(char sent[]){
	int i = 0;
	printf("\n\tEnter command:\n\t-> ");
	scanf ("%[^\n]%*c", sent);
	while(sent[i]!='\0'){
		if(sent[i]>64 && sent[i]<91){
			sent[i]=sent[i]+32;
		}
		i++;
	}
}

void compile(int flag){
	int i = 0;
	char* fName = (char*) malloc(100*sizeof(char));
	char* cCommand=(char*) malloc(100*sizeof(char));
	char* direc=(char*) malloc(100*sizeof(char));
	char* copyCmd=(char*) malloc(100*sizeof(char));
	copyCmd="(copy ";
	char finalCommand[100]="(cd SavedFiles) && (";

	if(flag){
		strcpy(cCommand, "gcc ");
	}else{
		strcpy(cCommand, "tcc ");
	}

	printf("\n\tEnter the name of the file:\n\t-> ");
	fgets(fName, 50, stdin);
	fflush(stdout);
	while(fName[i]!='\n'){
			i++;
	}
	fName[i]='\0';
	i = 0;


	printf("\n\tEnter directory of .c file\n\t-> ");
	fgets(direc, 100, stdin);
	fflush(stdout);

	/* Checks if directory has a / at the end or not, and adds one. Concatentes it to "tcc " */
	if(strstr(direc, "same")==NULL){
		while(direc[i]!='\n'){
			i++;
		}
		if(direc[i-1]!='\\'){
		 	direc[i+1]='\0';
		 	direc[i]='\\';
		 }
		strcat(direc, fName);
	}else{
		strcpy(direc, fName);
	}


	strcat(cCommand, direc);
	printf("\n\tCompiling...\n\t");

	if(!(system("mkdir SavedFiles")=='\0')){
		printf("\twhere file will be compiled.\n\n");
	}
	system(strcat(strcat(copyCmd, direc), " SavedFiles)"));

	strcat(finalCommand, cCommand);
	strcat(finalCommand, ")");
	if(system(finalCommand) == '\0'){
		printf("\n\tCompiled and saved %s to SavedFiles folder.\n", direc);
	}
	free(fName); free(cCommand); free(direc); free(copyCmd);
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

/* current local time */
void currentTime(){
	char timedate[SIZE];
  	time_t curtime;
  	struct tm *loctime;

  	curtime = time (NULL);
  	loctime = localtime (&curtime);
  	strftime (timedate, SIZE, "\n\tThe time is %I:%M %p.\n", loctime);
  	fputs (timedate, stdout);
}

/* local date */
void date(){
	char timedate[SIZE];
  	time_t curtime;
  	struct tm *loctime;

  	curtime = time (NULL);
  	loctime = localtime (&curtime);
  	strftime (timedate, SIZE, "\n\tToday is %A, %B %d, %Y.\n", loctime);
  	fputs (timedate, stdout);	
}

/* pc name */
void hostName(){
	printf("\n\tYour computer's name is: ");
	system("(cd C:/Windows/System32) && (hostname)");
}

/* weather search */
void weather(char sentText[]){
	char city[50];
	char tempLink[100]="http://api.openweathermap.org/data/2.5/weather?q=";
	char weatherLink[100]="START ";
	printf("\n\tEnter City:\n\t-> ");
	fgets(city, 50, stdin);
	char *pos;
	if ((pos=strchr(city, '\n')) != NULL)
	    *pos = '\0';
	printf("\n\tShowing weather in %s. (source: openweathermap.org)\n", city);
	strcat(tempLink, city);
	strcat(tempLink, "^&appid=82c3c276bf465cffc7885608c6f3e432^&mode=html");

	strcat(weatherLink, tempLink);
	system(weatherLink);
}

/* add numbers */
/*void addNumbers(){
	int add[512];
	int i = 0;
	for
}*/

/*
void helpMenu(){
	printf("\n\t------   NATLAN COMMAND MENU    ------");
	printf("\n\t-compile: Compiles the file. Uses tcc as compiler by default unless you specify it to use gcc");
*/
