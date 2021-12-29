/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
//Programmer:    	Justin Winchester
//Professor:		Dr. Zhao 
//Class:		Network Programming
//Project:		Ipv4 Conversion 
//Project Details:    This Project deals with the conversion of an IPv4 Address. This Project uses a program implemented in C/C++ that will prompt a user
//to input a IPv4 address and the program will use the nessacary functions and arithmetic in order to convert the IPv4 address into its network byte ordered
//decimal format and it's binary representation value. 
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



//LIBRARIES FOR FUNCTIONS, INPUT/OUT, & SO FORTH
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 64
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
using namespace std; //PUBLIC/STANDARD NAMESPACE
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


//Decimal 2 Binary Function 
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void DecimalToBinary(int n) {   												//Declare Void Function
   int binaryNumber[100], num=n;								//int array(buffer for binary digits) and ineter declaration
   int i = 0;									
   while (n > 0) {					//while loop to continually divide number "n" and same remainder this calculates it's binary value!
      binaryNumber[i] = n % 2;
      n = n / 2;
      i++;
   }
   cout<<"Binary value of "<<num<<" = ";	
   for (int j = i - 1; j >= 0; j--)              //For loop and "cout" statements used to print the binary representation of "n" by stored values in buffer
   cout << binaryNumber[j];
   cout<<endl;
}


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

//EXECUTE FUNCTION!!!
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void execute(char * argv){
    	int i;					//Declare variable, character array for ip strings entered, temporary array for numbers to be stored after conversion
						//Also declartion of internet address structure "struct" to hold IP address for network converstion
  	char argv1[SIZE];
   
     	int temparr[SIZE];
        
        struct in_addr addr;
        cout<< "Hello: Please Enter An IPv4 Address in Dotted decimal Notation: ";							//User Prompt!
	
	fgets(argv1,SIZE,stdin);									//Take User Input in this case IPv4 Quad Dotted Decimal Address!
	
	inet_aton(argv1, &addr);								//Call Funtion to convert Ipv4 address stored in "argv", and store 
												//its address in "addr" from Ascii String to Network Byte Ordered Decimal Format
         
	if (inet_aton(argv1, &addr) == 0) {
       fprintf(stderr, "Alright, Lets Try That Ipv4 Address One More Time!\n");  				//In  case function fails returning from "do While loop"
	fgets(argv1,SIZE,stdin);								//Re-take info from user and re-convert
        inet_aton(argv1, &addr);
       }  

   printf("IPv4 String!    %s\n", inet_ntoa(addr));					//Print in Ip Quad Dotted Format and Print in Network Byte Order Format using "Inet_aton & Inet_ntoa"!!!
        printf("Decimal(Network Byte Ordered)Value!   %d\n", addr.s_addr);
	int l =0;

    char * t = strtok(argv1, ".");					//Parse data in argv buffer by using the period or "dot" for delimminator (for quad dotted IPv4 internet address format)

        while(t != NULL)
    {   //cout << t << "\n";                                            //Did "cout" "T" in order to see value but value no longer needed to be print still keep for error checking purposes!
            i = atoi(t);						//Call Ascii to Integer to convert the data form string format entered by user to actual integer value that can be converted 
        //cout<<i<<"\n";						//Same with :T see above comment 
	DecimalToBinary(i);						//Call earlier created function and implement it to convert the decimal number to a binary number!


        


        t = strtok(NULL, "."); 						//Continue Parsing string
       temparr[l+1]=i;							//Store integer values 




//END OF EXECUTE FUNCTION
}

for( l = 0; l < 10; l++){

 argv1[l]=0 ;								//Clear buffer/array data

}




}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




//MAIN DRIVER FUNCTION FOR PROGRAM EXECUTION
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int main()
{
    int i; 
    char argv[SIZE];						//Character Array Declaration
    char answer[2];						//Answer Buff
 
	
do{								//Do While loop until User decides they don't want to convert any more IPv4 Address :)
	
	
	execute(argv);  
								//Call Execute	



for(int k = 0; k < SIZE; k++){
 argv[k] = 0;
}
cout<<"\nDo it again(y/n)? ";					//Get Answer for EXECUTION or termination
	cin >> answer;
	
	}while(tolower(answer[0]) == 'y');			//If user enters y for yes program will execute again if no will QUIT


return 0;
}

  

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
