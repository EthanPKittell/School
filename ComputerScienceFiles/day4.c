#include<stdio.h> //because I shall print and read things to my program
#include<stdbool.h> 

int main(int argc, char* argv[]){

	printf("This is my first program\n");
	printf("Name of Executable is: %s \n", argv[0]);
	
	for(int i =0; i<argc; i++ ){
	
		printf("%d : %s \n", i, argv[i]);
	}
	
	//C primitive Data types
	//A variable is a storage / (named location) where specific data is kept 
	int number = 0; // Doing this is called variable declaration (runtime -reserve some memory)
	int myNum;
	char myChar;
	float floatnum; //if you do not assign a value, then the variable is storing a garbage value.
	double doublenum = 3.24;
	char myCharacters[10] = "Name";
	_Bool myboolean = false; 
	
	//print with format specifiers
	printf("My integer is: %d\n", number);
	printf("My other integer is: %d\n", myNum);
	printf("my character is: %c\n", myChar);
	printf("My float is: %f \n", floatnum);
	printf("My double is: %lf \n", doublenum);
	printf("My string is: %s \n", myCharacters);
	printf("My Boolean is: %d \n", myboolean);
	
	//Reading values to our variables
	printf("Please enter a number:  ");
	scanf("%d",&number); // the & is called an address operator 
	printf("The read interger is: %d\n", number);
	
	//Reading a String is differnt --- NO need to specify the address:
	
	printf("What is your name:   ");
	scanf("%s", myCharacters);
	printf("Your name is: %s \n", myCharacters);
	
	
	
	
	
	
	


return 0;
}