#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

//function prototypes
void create_array(int, int);
void print_array(int **array, int, int);
void pop_array(int **array, int, int);


int main(int argc, char *argv[])
{
	//variable declaration
	int num = 0, rows = 0, cols = 0, compare = 0, **array;
	//there is no 'test' given at the command line
	if(argc == 1)
	{
		std::cout << "Enter the number of rows: ";
		std::cin >> rows;
		std::cout << std::endl;
		std::cout << "Enter the number of columns: ";
		std::cin >> cols;

		//create array, populate array, output array
		create_array(rows, cols);

		//exit program
		exit(0);
	}

	//check for -test argument from command line
	compare = strcmp(argv[1], "-test");
	if(compare == 0)
	{
		std::cin >> rows;
		std::cin >> cols;
		//create the array
		int **array = new int *[rows];
		for(int i = 0; i < rows; i++)
		{
			array[i] = new int[cols];
		}

		//populate the array
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				std::cin >> array[i][j];
			}
		}
		
		//print the array
		print_array(array, rows, cols);	
	}
	else
	{
		std::cout << " ! The only option allowed is '-test' " << std::endl;
	}
	
	return 0;
}

//creates an array
void create_array(int rows, int cols)
{	
	//create array
	int **array = new int *[rows];
	for(int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
	
	//populate array
	pop_array(array, rows, cols);	


	//print the array
	print_array(array, rows, cols);	
	
	//delete memory	
	for(int i = 0; i < rows; i++)
	{
		delete [] array[i];
	}
	delete [] array;
}

//prints the array
void print_array(int **array, int rows, int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
}


//populate array
void pop_array(int **array, int rows, int cols)
{
	srand(time(NULL));
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 50 + 1;
		}
	}
}
