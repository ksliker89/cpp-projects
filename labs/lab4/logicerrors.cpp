#include <iostream>
#define PROMPT "Please enter a whole number:"
#define NOT_PRIME "The number is not a prime number./n"
#define PRIME "The number is a prime number./n"
#define DONE 0 /* ends successful program */
#define FIRST_FACTOR 2 /* initial value in for loop */
using std::cout;
using std::cin;

int main()
{
	int i; /* loop counter */
	char number; /* number provided by user */
	cout << PROMPT; /* promt user */
	cin >> number; /* wait for user input */
     /* Prime numbers are defined as any number
      * greater than one that is only divisible
       * by one and itself. Dividing the number
        * by two shortens the time it takes to
	 * complete. */
	 i = number % 2;
	if(i == '1' )
	{ /* if divisible */
		cout << NOT_PRIME << number; /* not prime */
	}
	else
	{
	cout << PRIME << number;//prime numbers are not divisible by anything.
	}
	return 0; /* exit program */
}
