//Author: Kevin Sliker
//Date: march 5, 2015
//Assignment 5: This program finds
// the greatest product of a two dimensional array
// with different shapes: lines (horiz, vert, diag) and a square
//Sources: stackoverflow.com, cplusplus.com

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>


//function prototypes
int **create_array(int, int);
void init_array(int **, int, int);
void print_array(int **, int, int);
void greatest_product(int **, int, int);
int find_horizontal(int **, int, int, int &, int &);
int find_vertical(int **, int, int, int &, int &);
int find_fdiagonal(int **, int, int, int &, int &);
int find_bdiagonal(int **, int, int, int &, int &);
int find_square(int **, int, int, int &, int &);

//structure for calculating greatest product
struct product 
{
	int **array;
	int rows;
	int cols;
}g_product;//name of stucture


int main(int argc, char *argv[])
{
	//local variables
	int rows = 0, cols = 0, compare = 0, **array;

	//there is no 'test' given at the command line
	if(argc == 1)
	{
		//get user input
		std::cout << "Enter the number of rows: ";
		std::cin >> g_product.rows;
		std::cout << std::endl;
		std::cout << "Enter the number of columns: ";
		std::cin >> g_product.cols;

		//create array
		g_product.array = create_array(g_product.rows, g_product.cols);

		//initialize array
		init_array(g_product.array, g_product.rows, g_product.cols);

		//output array
		print_array(g_product.array, g_product.rows, g_product.cols);
		
		//calculate the greatest sum
		greatest_product(g_product.array, g_product.rows, g_product.cols);

		//exit program
		exit(0);
	}

	//check for -test argument from command line
	compare = strcmp(argv[1], "-test");
	if(compare == 0)
	{
		std::cin >> g_product.rows;
		std::cin >> g_product.cols;

		//create the array
		g_product.array = create_array(g_product.rows, g_product.cols);

		//populate the array
		for(int i = 0; i < g_product.rows; i++)
		{
			for(int j = 0; j < g_product.cols; j++)
			{
				std::cin >> g_product.array[i][j];
			}
		}
		
		//print the array
		print_array(g_product.array, g_product.rows, g_product.cols);

		//calculate the greatest sum
		greatest_product(g_product.array, g_product.rows, g_product.cols);
	}
	else
	{
		std::cout << " ! The only option allowed is '-test' " << std::endl;
	}
	
	return 0;
}

//Function: create_array(rows, cols)
//Return type: double pointer
//Usage: creates a 2D array
//Parameters: (int, int)
int **create_array(int rows, int cols)
{	
	//create array
	int **array = new int *[rows];
	for(int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
	
	return array;
}


//Function: init_array(array, rows, cols)
//Return type: none
//Usage: initializes a 2D array
//Parameters: (int **, int, int)
void init_array(int **array, int rows, int cols)
{

	//populate array
	srand(time(NULL));
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 50 + 1;
		}
	}
	

}


//Function: print_array(array, rows, cols)
//Return type: none 
//Usage: prints a 2D array
//Parameters: (int **, int, int) 
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


//Function: find_horizontal(array, rows, cols, hrow, hcol)
//Return type: int  
//Usage: finds the greatest product in all the rows of array
//Parameters: (int **, int, int, int &, int &) 
int find_horizontal(int **array, int rows, int cols, int &hrow, int &hcol)
{
	//greatest product
	int temp = 0, product = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0, swap = 0;

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
			temp = j;
		}
		if(swap > product)
		{
			product = swap;
			hrow = i+1;
			hcol = temp+1;
		}
	}
	return product;
}


//Function: find_vertical(array, rows, cols, vrow, vcol) 
//Return type: int
//Usage: finds the greatest product in all columns in array
//Parameters: (int **, int, int, int &, int &) 
int find_vertical(int **array, int rows, int cols, int &vrow, int &vcol)
{
	
	//greatest product
	int product = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0, swap = 0, temp = 0;

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
			temp = j;
		}
		if(swap > product)
		{
			product = swap;
			vrow = i+1;
			vcol = temp+1;
		}
	}
	return product;
}


//Function: find_fdiagonal(array, rows, cols, drow, dcol)
//Return type: int
//Usage: finds the greatest sum in a diagonal going forwards 
//Parameters: (int **, int, int, int &, int &) 
int find_fdiagonal(int **array, int rows, int cols, int &drow, int &dcol)
{
	//greatest product
	int product = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0, swap = 0, temp = 0;

	//iterate through entire array line by line
	for(int i = 0; i <= (rows - 4); i++)
	{
		for(int j = 0; j <= (cols - 4); j++)
		{
			p1 = array[i][j];
			p2 = array[i+1][j+1];
			p3 = array[i+2][j+2];
			p4 = array[i+3][j+3];
			swap = p1 * p2 * p3 * p4;
			temp = j;
		}
		if(swap > product)
		{
			product = swap;
			drow = i+1;
			dcol = temp+1;
		}
	}
	return product;
}


//Function: find_bdiagonal(array, rows, cols, dbrow, dbcol)
//Return type: int 
//Usage: finds the greatest product in a backwards diagonal  
//Parameters: (int **, int, int, int &, int &) 
int find_bdiagonal(int **array, int rows, int cols, int &dbrow, int &dbcol)
{
	//greatest product
	int product = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0, swap = 0, temp = 0;

	//iterate through entire array line by line
	for(int i = 0; i <= (rows - 4); i++)
	{
		for(int j = cols; j >= 3; j--)
		{
			p1 = array[i][j];
			p2 = array[i+1][j-1];
			p3 = array[i+2][j-2];
			p4 = array[i+3][j-3];
			swap = p1 * p2 * p3 * p4;
			temp = j;
		}
		if(swap > product)
		{
			product = swap;
			dbrow = i+1;
			dbcol = temp+1;
		}
	}
	return product;
}




//Function: find_square(array, rows, cols, srow, scol)
//Return type: int 
//Usage: finds the greatest product in the shape of a square 
//Parameters: (int **, int, int, int &, int &)
int find_square(int **array, int rows, int cols, int &srow, int &scol)
{
	//greatest product
	int product = 0, p1 = 0, p2 = 0, p3 = 0, p4 = 0, swap = 0, temp = 0;

	//iterate through entire array line by line
	for(int i = 0; i <= (rows - 2); i++)
	{
		for(int j = 0; j <= (cols - 2); j++)
		{
			p1 = array[i][j];
			p2 = array[i][j+1];
			p3 = array[i+1][j];
			p4 = array[i+1][j+1];
			swap = p1 * p2 * p3 * p4;
			temp = j;
		}
		if(swap > product)
		{
			product = swap;
			srow = i+1;
			scol = temp+1;
		}
	}
	return product;
}


//Function: greatest_product(array, rows, cols);
//Return type: none 
//Usage: outputs the greatest product in all directions (horizontal, vertical, square, diagonal) 
//Parameters: (int **, int, int)
void greatest_product(int **array, int rows, int cols)
{
	//local max variable
	int maxshape1 = 0, maxshape2 = 0, maxshape3 = 0, maxshape4 = 0, maxshape5 = 0;
	int vrow, vcol, hrow, hcol, srow, scol, drow, dcol, dbrow, dbcol;
	
	maxshape1 = find_horizontal(array, rows, cols, hrow, hcol);
	maxshape2 = find_vertical(array, rows, cols, vrow, vcol);
	maxshape3 = find_fdiagonal(array, rows, cols, drow, dcol);
	maxshape4 = find_square(array, rows, cols, srow, scol);
	maxshape5 = find_bdiagonal(array, rows, cols, dbrow, dbcol);

	//find the biggest shape and then output it
	int max = 0;
	if(maxshape1 > maxshape2 && maxshape1 > maxshape3 && maxshape1 > maxshape4 && maxshape1 > maxshape5)
	{
		std::cout << "The Max Product: " << maxshape1 << "\nThe shape: Horizontal" << "\nThe row:" << hrow << "\nThe col:" << hcol << std::endl;
	}
	if(maxshape2 > maxshape1 && maxshape2 > maxshape3 && maxshape2 > maxshape4 && maxshape2 > maxshape5)
	{
		std::cout << "The Max Product: " << maxshape2 << "\nThe shape: Vertical" << "\nThe row:" << vrow << "\nThe col:" << vcol << std::endl;
	}
	if(maxshape3 > maxshape2 && maxshape3 > maxshape1 && maxshape3 > maxshape4 && maxshape3 > maxshape5)
	{
		std::cout << "The Max Product: " << maxshape3 << "\nThe shape: Diagonal" << "\nThe row:" << drow << "\nThe col:" << dcol << std::endl;
	}
	if(maxshape4 > maxshape2 && maxshape4 > maxshape3 && maxshape4 > maxshape1 && maxshape4 > maxshape5)
	{
		std::cout << "The Max Product: " << maxshape4 << "\nThe shape: Square" << "\nThe row:" << srow << "\nThe col:" << scol << std::endl;
	}
	if(maxshape5 > maxshape2 && maxshape5 > maxshape3 && maxshape5 > maxshape1 && maxshape5 > maxshape4)
	{
		std::cout << "The Max Product: " << maxshape5 << "\nThe shape: Backwards Diagonal" << "\nThe row:" << dbrow << "\nThe col:" << dbcol << std::endl;
	}

}
