/* Author: Kevin Sliker
   Date: 1/19/15
   Assignment 2 CS 161
   Usage: This program takes either an array of characters and ouputs
          the ascii values in base 2 number system. This program also
	  takes base 2 numbers and gives back the corresponding ascii
	  values for characters. 
*/


#include <iostream>
#include <string>
#include <cmath>
#include <bitset>


int main()
{
	//get string of characters from the user
	std::string characters;
	std::cout << "Please enter a string of characters: ";
	std::getline(std::cin, characters);
	std::cout << std::endl;
	std::cout << characters << std::endl;

	//output the string back to user in binary
	std::cout << "This is your string in binary:" << std::endl;
	for(int i = 0; i < characters.length(); i++)
	{
		std::cout << (std::bitset<8>(characters[i])) << std::endl;
	}
	



	//get the binary numbers from user
	std::cout << std::endl;
	std::cout << "Please enter a string of binary characters: " << std::endl;
	int instance = 0;
	std::string binstring;
	do
	{
		std::cout << "enter them: ";
		std::getline(std::cin, binstring);

		//check to make sure the string only has binary
		instance = binstring.find_first_not_of("10", 0);
		if(instance >= 0)
		{
			std::cout << "Error, please only enter binary numbers." << std::endl;
		}
		std::cout << std::endl;
	}while(!instance == -1);
	
	
	int count = 0;
	int reverse = 0;
	std::string numstr;
	//this outputs the string of binary into ascii characters
	for(int i = 0; i < binstring.length() / 8; i++)
	{
		int num = 0;
		for(int j = 0; j < 8; j++)
		{
			if(binstring[binstring.length() - count] == '1')//this puts the iterator at the end of the string
			{
				num += pow(2, j -1); //this calculates the base 2 into decimal
			}
			count ++; //this count is the exponent for the base 2 conversion (index at which we found a 1 in string) 
		}
		numstr = numstr + (char)num;
		reverse += i;
	}

	for(int z = 0; z < reverse; z++)
	{
		std::cout << numstr[reverse - z] << std::endl;
	}

	return 0;
}
