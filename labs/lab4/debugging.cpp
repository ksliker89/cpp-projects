/* Author: Kevin Sliker
   Date: 1-29-15
   Usage: This is my lab4 debugging assignment
*/

#include <iostream>
#include <cmath> //need this for pow() function

int main()// Here the main function needed parameters.*******************
{
	 //Variables needed to calculate buoyancy
	const int WATER_WEIGHT = 0;//these two consts needed to be defined************
	const double PI = 3.14;
  	float radius = 0, bforce = 0, volume = 0; //These variables should be initialized************
	int weight = 0; //needed to create a variable for weight ***************
   	//Prompt user for weight and radius of sphere
    	std::cout << "Please enter the weight (lbs): "; //missing semicolon***********
	std::cin >> weight;
	std::cout << "Please enter the radius: ";//cout << not >>**************
        std::cin >> radius;//cin >> not >>**********

        //Calculate the volume and buoyancy force
	volume = 4/3 * PI * pow((int)radius, 3);//pow not power. radius needs to be an int. cant divinde floats, r needs to be radius ***********
	bforce = volume * WATER_WEIGHT;//mispelling in volume and bforce and WEIGHT**********
	//Determine if the sphere will sink or float
	if(bforce >= weight)//illegal use of >= operators************
	{
		std::cout << "The sphere will float!\n";//cout << not >>**************
	}//missing braces**************
	else//else does not have a semicolon after it***********
	{//missing braces************
		std::cout << "The sphere will sink!\n";
	}
	return 0; //Here the return type needed a value.

}
