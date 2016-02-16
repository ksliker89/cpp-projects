/* Author: Kevin Sliker
   Date: 1/19/15
   Assignment 4 CS 161
   Usage: This program takes a prompt from the user at run-time.
   		the prompt is to convert a binary string to a
		binary number. vice versa.
*/


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <bitset>

//function prototypes
void bin_to_ascii(char []);
void ascii_to_bin(char []);
void check_bin_number(char []);
void menu();



/*Function: main
  Parameters: (int, char *) 
  Type: int
  Purpose: designed to take in arguments from the command line
*/
int main(int argoption, char *argvalue[])
{
	for(int i = 0; i < argoption; i++)
	{
		//ascii check
		int compare;
		compare = strcmp(argvalue[i+1], "-a");
		if(compare == 0)
		{
			//ascii to bin
			ascii_to_bin(argvalue[i+2]);
			break;	
		}	

		compare = strcmp(argvalue[i+3], "-b");
		//binary check
		if(compare == 0)
		{
			//binary to ascii
			bin_to_ascii(argvalue[i+4]);
			break;
		}
		else
		{
			std::cout << "You entered some bad input" << std::endl;
			std::cout << "Try again...." << std::endl;
		}
	}
	
	return 0;

}



/*Function: bin_to_ascii
  Parameters: none
  Type: void
  Usage: convert binary digits to acii characters
*/
void bin_to_ascii(char argvalue[])
{
	//check the binary string
	check_bin_number(argvalue);

	//convert binary to int
	int asciinum = 0;
	int power = 0;
	for(int i = 0; i < strlen(argvalue); i++)//iterates through entire string bit by bit
	{
		if(argvalue[i] == '1')
		{
			asciinum += pow(2, 7 - power);
		}	
		power++;
		if(power >= 8 )
		{
			//output int as ascii char
			std::cout << (char)asciinum;
			//reset power and asciinum
			power = 0;
			asciinum = 0;
		}	
	}	
}

/*Function: ascii_to_bin
  Parameters: char str[] 
  Type: void
  Usage: converts ascii characters into binary
*/
void ascii_to_bin(char string[])
{
	
	//output the string back to user in binary
	std::cout << "This is your string in binary:" << std::endl;
	for(int i = 0; i < strlen(string); i++)
	{
		std::cout << (std::bitset<8>(string[i])) << std::endl;
	}
}


/*Function: check_bin_number
  Parameters: char str[] 
  Type: void
  Usage: checks binary number input from user for 3 cases
	 1. divisible by 8
         2. only consists of 0 or 1
	 3. only ascii characters from 0-127 
*/
void check_bin_number(char checkstring[])
{
	//check divisiblity by 8
	int divisible = 0;
	divisible = strlen(checkstring) % 8;
	if(divisible > 0)
	{
		std::cout << "Error, enter in bytes." << std::endl;
		//bin_to_ascii();
	}
	//check to make sure the string only has binary
	for(int i = 0; i < strlen(checkstring); i++)
	{
		if(checkstring[i] != '0' || checkstring[i] != '1')
		{
			std::cout << "Please enter only binary numbers" << std::endl;
		}

	}
	

}
