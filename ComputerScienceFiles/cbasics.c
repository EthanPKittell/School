#include<stdio.h> // an include preprocessor directive 
#define _CRT_SECURE_NO_WARNINGS // macro initialization preprocessor directive
#define MAX 10

//IF YOU ARE USING MS VS use scanf_s instead of scanf for this purpose
int main (void){ //main is a function that takes in nothing and returns an integer
    printf("Please enter your age:  ");
    
    int number; //variable declaration
    scanf("%d", &number); //read some input from the terminal (standard input)

    char fName[15] = "JONATHAN"; //anything enclosed with twon quotattion marks is a string
    char lName[20];

    printf("Enter Last Name:   ");
    scanf("%s", lName);
    
    printf("You are %d years old and your name is %s %s\n", number, fName, lName); // output to the terminal (standard output)

    return 0;


}