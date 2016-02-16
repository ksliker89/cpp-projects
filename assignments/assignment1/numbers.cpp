/* Program: numbers.cpp
   Author: Kevin Sliker
   Date: 1-16-2015
   Description: This is assignment 1 of cs161.
   The assignment finds the max and min values of 
   signed and unsigned integral data types.
*/

#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>

int main()
{
	//Variables for Macros
	int maxint = INT_MAX;
	int minint = INT_MIN;
	unsigned int usint = UINT_MAX;
	short maxshort = SHRT_MAX;
	short minshort = SHRT_MIN;
	unsigned short usshort = USHRT_MAX;
	long maxlong = LONG_MAX;
	long minlong = LONG_MIN;
	unsigned long uslong = ULONG_MAX;
	


	//variables for pow() and sizeof()
	//note: sizeof() returns bites. (*8) gives bits. 
	//note: (-1) prevents overflow of data type.
	int intmaxpow = sizeof(int) * 8 - 1;
	int intminpow = sizeof(int) * 8 - 1;
	unsigned int usintmax =  sizeof(int) * 8;
	short shortmaxpow = sizeof(short) * 8 - 1;
	short shortminpow = sizeof(short) * 8 - 1;
	unsigned short usshortpow = sizeof(short) * 8;
	long longmaxpow = sizeof(long) * 8 - 1;
	long longminpow = sizeof(long) * 8 - 1;
	unsigned long uslongmax = sizeof(long) * 8;




	//Output macros 
	std::cout << "********max and min using macro************" << std::endl;
	std::cout << "The max Int: " << maxint << std::endl;
	std::cout << "The min Int: " << minint << std::endl;
	std::cout << "The max Int Unsigned: " << usint << std::endl;

	std::cout << "The max Short: " << maxshort << std::endl;
	std::cout << "The min Short: " << minshort << std::endl;
	std::cout << "The max Short Unsigned: " << usshort << std::endl;

	std::cout << "The max Long: " << maxlong << std::endl;
	std::cout << "The min Long: " << minlong << std::endl;
	std::cout << "The max Long Unsigned: :" << uslong << std::endl << std::endl << std::endl;




	//Output the max and min using pow() and sizeof()
	//note: the (-1) from pow allows for zero
	std::cout << "********max and min using pow() and sizeof()**********" << std::endl;
	std::cout << "The max Int: " << (unsigned int)(pow(2, intmaxpow))-1 << std::endl;
	std::cout << "The min Int: " << (int)(pow(2, intminpow)) << std::endl;
	std::cout << "The max Int Unsigned: " << (unsigned int)(pow(2, usintmax))-1 << std::endl;

	std::cout << "The max Short: " << (unsigned short)(pow(2, shortmaxpow))-1 << std::endl;
	std::cout << "The min Short: " << (short)(pow(2, shortminpow)) << std::endl;
	std::cout << "The max Short Unsigned: " << (unsigned short)(pow(2, usshortpow) -1) << std::endl;

	std::cout << "The max Long: " << (unsigned long)(pow(2, longmaxpow))-1 << std::endl;
	std::cout << "The min Long: " << (long)(pow(2, longminpow)) << std::endl;
	std::cout << "The max Long Unsigned: " << (unsigned long)(pow(2, uslongmax))-1 << std::endl << std::endl << std::endl;



	//Output the min and max when adding 1 to see what happens
	std::cout << "********what happens when you add 1 to the min and max**********" << std::endl;
	std::cout << "The max Int: " << (unsigned int)(pow(2, intmaxpow)) << std::endl;
	std::cout << "The min Int: " << (int)(pow(2, intminpow))+1 << std::endl;
	std::cout << "The max Int Unsigned: " << (unsigned int)(pow(2, usintmax)) << std::endl;

	std::cout << "The max Short: " << (unsigned short)(pow(2, shortmaxpow)) << std::endl;
	std::cout << "The min Short: " << (short)(pow(2, shortminpow))+1 << std::endl;
	std::cout << "The max Short Unsigned: " << (unsigned short)(pow(2, usshortpow)) << std::endl;

	std::cout << "The max Long: " << (unsigned long)(pow(2, longmaxpow)) << std::endl;
	std::cout << "The min Long: " << (long)(pow(2, longminpow))+1 << std::endl;
	std::cout << "The max Long Unsigned: " << (unsigned long)(pow(2, uslongmax)) << std::endl << std::endl << std::endl;

	


	//Take a char from user and output the ascii value in decimal, binary, and hexidecimal
	std::cout << "Please enter a char: ";
	char var;
	std::cin >> var;
	std::cout << "This is what you entered: " << var << std::endl;


	//variables for decimal, binary, and hex
	std::cout << "That variable values" << std::endl;
	std::cout << "Decimal: " << (int)var << std::endl;
	std::cout << "Binary: " << std::bitset<8> (var) << std::endl;
	std::cout << "Hex: " << std::hex << (int)var << std::endl;
	
	
 	return 0;
}
