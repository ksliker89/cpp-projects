//Author: Kevin Sliker
//Date: march 3, 2015
//Assignment 6: creating a structure for netflix
//Sources: none

#include "netflix.h"

int main()
{
	char choice;
	do
	{
		set_netflix_info();
		print_netflix_info();
		
		//ask user if they want to repeat
		std::cout << "Do you want to enter another movie?";
		std::cin >> choice;

	}while(choice == 'y');

	return 0;
}
