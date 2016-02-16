//This is a header file for netflix struct

#ifndef _NETFLIX_H_INCLUDED
#define _NETFLIX_H_INCLUDED

#include <iostream>
#include <string>


//declare the netflix struct
struct netflix
{
	std::string name;
	int stars;
	int castnum;
	std::string *cast;
	std::string rating;
};




//function prototypes
void set_netflix_info();
void print_netflix_info();


#endif
