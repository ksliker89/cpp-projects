/* Author: Kevin Sliker
   Date: 1-29-15
   Usage: This program takes a roman numeral and returns an integer.
   It also takes a integer and returns a roman numeral.
*/

#include <iostream>
#include <string>

int value(char []);

int main()
{
	//variables
	std::string r_t_d;
	std::string romans;
	int temp = 0;


	//assign roman numerals to values
	const int I = 1;
	const int V = 5;
	const int X = 10;
	const int L = 50;
	const int C = 100;
	const int D = 500; 
	const int M = 1000;

	
	//get romans from the user
	std::cout << "Please enter some Romans: ";
	std::cin >> romans;
	
	for(int j = 0; j < romans.length(); j++)
	{
		r_t_d[j] = value(romans[j]);


	}

	return 0;
}


int value(char romans[])
{
	for(int i = 0; i < 2; i++)
	{
		switch(romans[i])
		{
			case 'I': return 1;
			break;
			case 'V': return 5;
			break;
			case 'X': return 10;
			break;
			case 'L': return 50;
			break;
			case 'C': return 100;
			break;
			case 'D': return 500;
			break;
			case 'M': return 1000;
			break;
		}

	}
}
