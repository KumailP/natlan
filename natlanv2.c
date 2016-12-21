#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 512

void printIntro();
void helpMenu();
void executeCommand(char sent[]);
void getSentence(char sent[]);
void compile(int flag);
void doMath(char sent[]);
void calculateResult(double* result, char* operation);
void goTo();
void currentTime();
void date();
void weather(char sent[]);
void hostName();
void displayIP();
void convertCurrency();
void printRates();
void printSeparate();


int main(){
	int i = 0;
	char sent[100];

	printIntro();
	while(!(strstr(sent,"quit") !=NULL)){
		printSeparate();
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
	printf("\n\tHello! I am NatLan. How may I assist you?\n");
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
		helpMenu();
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
	else if((strstr(sent, "ip")!=NULL)){
		displayIP();
	}
	else if((strstr(sent, "math")!=NULL) || (strstr(sent, "add")!=NULL) || (strstr(sent, "subtract")!=NULL) || (strstr(sent, "divide")!=NULL) || (strstr(sent, "multiply")!=NULL)){
		doMath(sent);
	}else if((strstr(sent, "currency")!=NULL) && (strstr(sent, "convert")!=NULL)){
		convertCurrency();
	}
	// else{
	// 	printf("\n\tCommand unrecognized.\n");
	// }
}


void helpMenu(){
	printf("\n\t------   NATLAN COMMAND MENU    ------");
	printf("\n\t- Quit: Quits NatLan.");
	printf("\n\t- Compile using gcc/tcc: Compiles the file. Uses tcc as compiler by default unless you specify it to use gcc");
	printf("\n\t- Go to: Asks for the address of a webpage or local drive, and opens it in the browser or Explorer");
	printf("\n\t- Weather: Prompts for a city, then opens a webpage to show the weather in that city.");
	printf("\n\t- PC name: Displays the name of the machine.");
	printf("\n\t- Date/Day: Displays the current date, month and year.");
	printf("\n\t- Time: Displays the current time.");
	printf("\n\t- IP: Displays your machine's internet protocol information.");
	printf("\n\t- Math: Prompts for operation and operands and gives appropriate result.");
	printf("\n\t- Add/Subtract/Multiply/Divide - Prompts for operands and gives appropriate result directly from main window.");
	printf("\n");
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

void doMath(char sent[]){
	char operation;
	double result;
	int flag = 1;
	do{
		operation = 0, result = 0;
		if(strstr(sent, "math")!=NULL || flag==0){
			do{
				printf("\n\tWhich operation would you like to do?\n\tPossible Inputs: (+, -, /, *) or 'b' to go back.\n\t-> ");
				scanf("%c", &operation);
				fflush(stdin);
			}while(operation!='+' && operation!='-' && operation!='*' && operation!='/' && operation!='b');
		}else if(strstr(sent, "add")!=NULL && flag){
			operation = '+';
			flag = 0;
		}else if((strstr(sent, "subtract")) || (strstr(sent, "minus"))!=NULL && flag){
			operation = '-';
			flag = 0;
		}else if((strstr(sent, "divide")!=NULL) && flag){
			operation = '/';
			flag = 0;
		}else if(strstr(sent, "multiply")!=NULL && flag){
			operation = '*';
			flag = 0;
		}

		if(operation!='b'){
			calculateResult(&result, &operation);

			printf("\n\t-> %g.\n", result);	
			fflush(stdin);
		}
	}while(operation!='b' && flag);
}

void calculateResult(double* result, char* operation){
	double firstNum = 0, secNum = 0;
	printf("\n\tEnter first number: ");
	scanf("%lf", &firstNum);
	
	printf("\n\tEnter second number: ");
	scanf("%lf", &secNum);

	switch(*operation){
		case '+':
			*result = firstNum + secNum;
			break;
		case '-':
			*result = firstNum - secNum;
			break;
		case '*':
			*result = firstNum * secNum;
			break;
		case '/':
			*result = firstNum / secNum;
			break;
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
	system("C:\\Windows\\System32\\hostname");
}

/* displays the internet protocol */
void displayIP(){
	printf("\n\tYour computer's Internet Protocol information:\n\t");
	system("C:\\Windows\\System32\\ipconfig");
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
	sleep(1000);
	strcat(tempLink, city);
	strcat(tempLink, "^&appid=82c3c276bf465cffc7885608c6f3e432^&mode=html");

	strcat(weatherLink, tempLink);
	system(weatherLink);
}

/* convert currency */

void convertCurrency(){
	float rate = 0, sCurrency = 0, bCurrency = 0;
	char conv = 0, conv2 = 0;
	char test[60];
	FILE* rates = fopen("rates.dat", "r");
	printSeparate();
	printRates();
	printf("\n\tEnter Sr. No. of conversion: \n\t-> ");
	scanf("%c", &conv);
	do{

		fscanf(rates, "%c %f\n", &conv2, &rate);
		fflush(stdin);
	}while(conv2!=';' && conv2!=conv);

	if(conv2==';'){
		printf("\n\tData not found for given conversion.\n");
	}else{
		printf("\n\tEnter base currency: ");
		scanf("%f", &bCurrency);

		sCurrency = bCurrency*rate;

		printf("\n\tUsing rate %g, the converted currency is: %g.\n", rate, sCurrency);
	}
	fclose(rates);
	fflush(stdin);
}

void printRates(){
	printf("\n\t[A] PKR to USD | [B] USD to PKR");
	printf("\n\t[C] PKR to EUR | [D] EUR to PKR");
	printf("\n\t[E] USD to EUR | [F] EUR to USD");
	printf("\n\t[G] PKR to AED | [H] AED to PKR\n\t");
}

void printSeparate(){
	printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t");
}