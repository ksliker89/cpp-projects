//This is the implementation file for netflix.h

#include "netflix.h"

//create a new variable of struct type netflix
netflix movie;

//get all information from the user to be put into the struct
void set_netflix_info()
{
	//variable for error checking input
	int found;


	//get the title of the movie
	std::cout << "Enter the movie title: ";
	std::getline(std::cin, movie.name);


	//get the amount of stars in the movie
	std::cout << "Enter the # of stars: ";
	std::cin >> movie.stars;
	//check for integer input only
	found = movie.stars.find_first_not_of("0123456789", 0);
	if(found > 0)
	{
		std::cout << "Please enter only integers." << std::endl;
	}


	//get the amount of cast members
	std::cout << "Enter the # of cast members: ";
	std::cin >> movie.castnum;
	//check for integer input only
	found = movie.castnum.find_first_not_of("0123456789", 0);
	if(found > 0)
	{
		std::cout << "Please enter only integers." << std::endl;
	}
	std::cin.ignore();


	//create dynamic array
	movie.cast = new std::string[movie.castnum];


	//for each cast member, get their name
	for(int i = 0; i < movie.castnum; i++)
	{
		//get the name
		std::cout << "Enter cast member name " << i + 1 << ": ";
		std::getline(std::cin, movie.cast[i]);
	}


	//get the movie rating
	std::cout << "Enter the movie rating: ";
	std::cin >> movie.rating;
	std::cin.ignore();
}



//this function prints the entire struct to the console
void print_netflix_info()
{
	std::cout << "Your movie entry is: " << std::endl;
	std::cout << "Movie name: " << movie.name << std::endl;
	std::cout << "Movie stars: " << movie.stars << std::endl;
	std::cout << "Movie cast: " << movie.castnum << std::endl;
	//output each name one by one
	for(int i = 0; i < movie.castnum; i++)
	{
		std::cout << "Cast member " << i + 1 << ": " << movie.cast[i] << std::endl;
	}
	std::cout << "Movie rating: " << movie.rating << std::endl;

}
