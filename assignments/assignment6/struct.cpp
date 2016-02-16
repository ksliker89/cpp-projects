//Author: Kevin Sliker
//Date: march 3, 2015
//Assignment 6: creating a structure for netflix
//Sources: none

#include <iostream>
#include <string>

//structure for netflix info
struct netflix 
{
	std::string name;
	int castnum;
	std::string *cast;
	std::string rating;

}movie;




int main()
{
	char choice;
	do
	{
		//get the title of movie
		std::cout << "Enter the name of your movie: ";
		std::getline(std::cin, movie.name);

		//get the cast members in the movie
		std::cout << "Enter the amount of cast members: ";
		std::cin >> movie.castnum;
		//make sure input is only integers
		while(!std::cin)
		{
			std::cout << "You can only enter integers here." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin >> movie.castnum;
		}
		std::cin.ignore();

		//create dynamic array
		movie.cast = new std::string[movie.castnum];


		//for each number of cast members, get their names
		for(int i = 0; i < movie.castnum; i++)
		{
			//get the name of cast members
			std::cout << "Enter cast member " << i+1 << ": ";
			std::getline(std::cin, movie.cast[i]);
		}

		//get the movie rating
		std::cout << "Enter the movie rating: ";
		std::cin >> movie.rating;
		std::cin.ignore();

		//output the entire movie entry to the user
		std::cout << "Your movie entry is: " << std::endl;
		std::cout << "Movie name: " << movie.name << std::endl;
		std::cout << "Movie cast: " << movie.castnum << std::endl;
		for(int i = 0; i < movie.castnum; i++)
		{
			std::cout << "Cast member " << i+1 << ": " << movie.cast[i] << std::endl;
		}
		std::cout << "Movie rating: " << movie.rating << std::endl;

		//ask user if they want to continue entering movies
		std::cout << "Do you want to enter a movie?";
		std::cin >> choice;
		std::cin.ignore();

	}while(choice == 'y');

	return 0;
}
