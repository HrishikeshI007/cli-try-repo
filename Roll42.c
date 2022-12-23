/*  Name : Hrishikesh Iyer
    Division : 1
    Roll number : 101042
    Assignment 1(a,b,c)
*/
//I have used the most suitable data types in this program to minimise memory usage

#include <stdio.h>
//Code for Assignment 1(a)
        //// void function type as printf is executed and output is displayed wrt stack diagram. Thus return value(int func()) is not needed
void LeapYear(){
    short unsigned int year; //short as it represents sufficiently many years(2^16) and unsigned as year is always positive value
    printf("Enter the year in YYYY format\n");   //L13 and L14 take input of year from user and store value in var year
    scanf("%d",&year);
/* Logic used -->
    1. an year divisible exactly by 4 and not by 100 is leap year(first bracket in if statement)
    2. an year NOT divisble by 4 ; divisible by 100 and divisible by 400 is NOT a leap year
*/
    if((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0){ // i learnt that condition indside if() can be written in highly compact form --> if ((cond part1)cond part2)
        printf("%d is a leap year with 366 days\n",year);
    }else{
        printf("%d is not a leap year\n",year);
    }
}
                                /*----------------*/
//Code for 1(b)
/* Reasons for choosing float variable as user input rather than int --
        1. enbales user to input fractional numbers
        2. same meory size for int and float = 4 bytes
        3. (wrt IEEE 754)maximum range for a float is around 3.4x10^38 whereas int only allows range up to 2.1×10^9
*/
//function to add 
        // void function type as printf is executed and output is displayed wrt stack diagram. Thus return value(int func()) is not needed
void add(float a,float b){   //2 parameters a and b need to be inputted
    float c=a+b;          // addition result of a and b is stored in c 
    printf("%f+%f=%f\n",a,b,c);  //this prints result along with input data
}

//function to subtract
void sub(float a,float b){
    float c=a-b;
    printf("%f-%f=%f\n",a,b,c);
}

//function to multiply
void mult(float a,float b){
    float c=a*b;
    printf("%fx%f=%.3f\n",a,b,c);//.3f rounds off result within 3 places post-decimal
}
//function to divide 
void div(float a,float b){
    float c=a/b;
    printf("%f/%f=%.3f\n",a,b,c);//.3f rounds off result within 3 places post-decimal
}
//function to find remainder
    /*below, a and b are int data type as modulo works only on int
    however , user input is stored n float and converted to int in main()*/
void mod(int a,int b){ 
    int c=a%b;
    printf("%d mod %d=%d",a,b,c);
} 
                                /*----------------*/
//code for 1(c)-- to generate multiplication table
        //void is function type as printf is executed wrt stack structure and displays output. We do not need a return value(int func()) mandatorily
        //UI means function is for user-input condition 
void MultTableUI(){ 
    unsigned int c;//unsigned int as c always has positive integral value(next line).It provides sufficient range wrt user input 
    float num;//to allow user to input fractional numbers
    unsigned int multiple;//unsigned int since multiples are always whole numbers(0+natural numbers)
    printf("Note: Fractional numbers are accepted\n");
    printf("Please enter number whose multiplication table is needed\n");
    scanf("%f",&num);

    printf("Please enter number of multiples needed\n");
    scanf("%d",&multiple);

    printf("The multiplication table of %f till %d multiples is -- \n",num,multiple);
    for(c=1;c<=multiple;c++){  //this prints the result in a tabular format
        printf("\n%3f x%3d = %3f",num,c,num*c);//%3d and %f helps in spacing the numbers for aesthetics
    }
}
        //PS means function is for pre-set condition
void MultTablePS(){ 
    unsigned int c,p,q=1,r=1,num,multiple;
    printf("Please select number whose multiplication table is needed\n");
    for(p=1;p<=10;p++){  
    printf("\n%d. %d",p,q++);
    }
    printf("\n");
    scanf("%d",&num);

    printf("Please select number of multiples needed\n");
    for(p=1;p<=10;p++){
    printf("\n%d. %d multiples",p,r++);
    }
    printf("\n");
    scanf("%d",&multiple);

    printf("The multiplication table of %d till %d multiples is -- \n",num,multiple);
    for(c=1;c<=multiple;c++){
        printf("\n%3d x%3d = %3d",num,c,num*c);//%3d helps in spacing the numbers for aesthetics
    }
    }

                                /*----------------*/
//Code for main menu
        //void is function type as printf is executed wrt stack structure and displays output. We do not need a return value
void MainMenu(){
    printf("This program contains all 3 parts of Assignment 1 - a,b,c\n");
    printf("\n");
    printf("Main menu : (please choose an option,type the number and press enter key)\n");
    printf("1. Program for leap year verification\n");
    printf("2. Program to implement basic arithmetic operations\n");
    printf("3. Program to generate multiplication table\n");
}                                
                                /*----------------*/
//Code for sub-menu 
        //void is function type as printf is executed wrt stack structure and displays output. We do not need a return value
void SubMenu(){
    printf("Please type a number from menu below and press enter key\n");
    printf("1.Addition of the 2 numbers\n");
    printf("2.Subtraction of the 2 numbers\n");
    printf("3.Multiplication of the 2 numbers\n");
    printf("4.Division of the 2 numbers(to display quotient)\n");
    printf("5.Modulus of the 2 numbers\n");
}
                                /*----------------*/
void main(){
    unsigned char opt1,opt2,opt3; //variables to store user's choice from main menu and sub-menu
    float x,y; //int var to store numbers given by user
    int l,m;//to support modulo operation

    MainMenu();
    scanf("%hhu",&opt1); //takes user input as chice of above menu
    
    switch(opt1){ //helps to run the chosen program
        case 1:
            printf("You have selected Assignment 1(a):Program for leap year verification\n");
            LeapYear();//calls the function
            break;

        case 2:
            printf("You have selected Assignment 1(b):Basic arithmetic operations\n");
            //below asks user to provide 2 integers and stores them @ x and y 
            printf("Kindly Note:\n");
            printf("\t 1.Fractional inputs are also accepted\n");
            printf("\t 2.For modulo , only integral part of fractional number will be considered\n");
            printf("Please enter the first number\n"); 
            scanf("%f",&x);
            printf("Please enter the second number\n");
            scanf("%f",&y);

            SubMenu();//The menu for arithmetic operations 
            printf("\n");
            scanf("%hhu",&opt2);  

            switch(opt2){ //helps to run the code for specific operation
                    case 1:
                    add(x,y);   // x and y are parameters given by the user
                    break;

                    case 2:
                    sub(x,y);
                    break;

                    case 3:
                    mult(x,y);
                    break;

                    case 4:
                    div(x,y);
                    break;

                    case 5:
                    l=x;//to get integral part of float x
                    m=y;//to get integral part of float x
                    mod(l,m);
                    break;
                }
            break;

        case 3:
            printf("Sub menu for multiplication tables\n");
            printf("1.User-defined number input\n");
            printf("2.Pre-set options \n");
            scanf("%hhu",&opt3);

            switch(opt3){
                case 1:
                MultTableUI();
                break;

                case 2:
                MultTablePS();
                break;
            }

            
        break;
    }
}
                                /*--------------------*/
