/* Author: Kevin Sliker
   Date: 1/19/15
   Assignment 2 CS 161
   Usage: This program takes either an array of characters and ouputs
          the ascii values in base 2 number system. This program also
	  takes base 2 numbers and gives back the corresponding ascii
	  values for characters. 
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <bitset>

//function prototypes
void bin_to_ascii();
void ascii_to_bin(std::string);
void check_bin_number(std::string);
void menu();
std::string get_user_input();


int main()
{
	menu();	
	return 0;
}




//converts a binary number to ascii characters
void bin_to_ascii()
{
	//variable string
	std::string binstring;

	//get string of binary from user
	binstring = get_user_input();

	//check the binary string
	check_bin_number(binstring);

	//convert binary to int
	int asciinum = 0;
	int power = 0;
	for(int i = 0; i < binstring.length(); i++)//iterates through entire string bit by bit
	{
		if(binstring[i] == '1')
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
//converts ascii characters into binary
void ascii_to_bin()
{
	
	std::string userinput;
	userinput = get_user_input();
	//output the string back to user in binary
	std::cout << "This is your string in binary:" << std::endl;
	for(int i = 0; i < userinput.length(); i++)
	{
		std::cout << (std::bitset<8>(userinput[i])) << std::endl;
	}
	menu();
}
//gets input from the user 
std::string get_user_input()
{
	//get string of characters from the user
	std::string characters;
	std::cout << "Please enter a string of characters: ";
	std::cin >> characters;
	std::cout << std::endl;
	std::cout << "This is what you entered: " << characters << std::endl;
	return characters;
}
//checks binary number input from user for 3 cases
// 1. divisible by 8
// 2. only consists of 0 or 1
// 3. only ascii characters from 0-127 
void check_bin_number(std::string binstring)
{
	//get the binary numbers from user
	int instance = 0;
	do
	{
		//check divisiblity by 8
		int divisible = 0;
		divisible = binstring.length() % 8;
		if(divisible > 0)
		{
			std::cout << "Error, enter in bytes." << std::endl;
			bin_to_ascii();
		}
		//check to make sure the string only has binary
		instance = binstring.find_first_not_of("10", 0);
		if(instance >= 0)
		{
			std::cout << "Error, please only enter binary numbers." << std::endl;
			bin_to_ascii();
		}
		std::cout << std::endl;
	}while(!instance == -1);
	

}
//chooses from the menu options in get_user_input()
void menu()
{
	int menu = 0;
	do
	{
		std::cout << "Please choose an option from the menu" << std::endl;
		std::cout << "(1) - ascii to binary " << std::endl;
		std::cout << "(2) - binary to ascii " << std::endl;
		std::cout << "(3) - exit program " << std::endl;
		std::cin >> menu; 
	}while(!menu == 3);
	
	switch(menu)
	{
		case 1: 
			ascii_to_bin();
			break;
		case 2: 
			bin_to_ascii();
			break;
		default: 
			exit (0);
			break;
	}

}

