#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

//structure for calculating greatest product
struct product 
{
	int **array;
	int rows;
	int cols;
}g_product;//name of stucture


//function prototypes
void create_array(int, int);
void init_array();
void print_array();
void greatest_product(int **, int, int);
int find_horizontal(int **, int, int);
int find_vertical(int **, int, int);
int find_diagonal(int **, int, int);
int find_square(int **, int, int);


int main(int argc, char *argv[])
{
	//variable declaration
	int num = 0, rows = 0, cols = 0, compare = 0, **array;
	//there is no 'test' given at the command line
	if(argc == 1)
	{
		std::cout << "Enter the number of rows: ";
		std::cin >> g_product.rows;
		std::cout << std::endl;
		std::cout << "Enter the number of columns: ";
		std::cin >> g_product.cols;

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
	        int array[rows][cols];

		//populate the array
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				std::cin >> array[i][j];
			}
		}
		
		//print the array
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				std::cout << array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << " ! The only option allowed is '-test' " << std::endl;
	}
	
	return 0;
}

//creates an array dynamically
void create_array(int rows, int cols)
{	
	//create array
	int **array = new int *[rows];
	for(int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
	
	//populate array
	srand(time(NULL));
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 50 + 1;
		}
	}
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for(int i = 0; i < rows; i++)
	{
		delete [] array[i];
	}
	delete [] array;
}


//functions for finding greatest product
int find_horizontal(int **array, int rows, int cols)
{
	//greatest product
	int product = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0, swap = 0;

	//iterate through entire array line by line
	for(int i = 0; i <= (rows - 4); i++)
	{
		for(int j = 0; j <= (cols - 4); j++)
		{
			p1 = array[i][j];
			p2 = array[i][j+1];
			p3 = array[i][j+2];
			p4 = array[i][j+3];
			swap = p1 * p2 * p3 * p4;
		}
		if(swap > product)
		{
			product = swap;
		}
	}
	return product;
}
int find_vertical(int **array, int rows, cols)
{
	
	//greatest product
	int product = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0, swap = 0;

	//iterate through entire array line by line
	for(int i = 0; i <= (rows - 4); i++)
	{
		for(int j = 0; j <= (cols - 4); j++)
		{
			p1 = array[i][j];
			p2 = array[i+1][j];
			p3 = array[i+2][j];
			p4 = array[i+3][j];
			swap = p1 * p2 * p3 * p4;
		}
		if(swap > product)
		{
			product = swap;
		}
	}
	return product;

}
int find_diagonal();
int find_square();
