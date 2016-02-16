#include <iostream>
#include <cmath>

void print_array (int **, int);
void **create_array (int);
void tower (int, char , char , char, int **, int);

using namespace std;

void change_array (){


}
void tower (int n, char from, char aux, char to, int **array, int a){
	
	if (n==1){
		cout << "\t\tMove disc 1 from " << from << " to " << to << endl;
		print_array(array, a);
		return;
	}
	
	else{
		tower ((n-1),from,to,aux, array, a);
	
		cout << "\t\tMove disc " << n << " from " << from << " to " << to << endl;
		print_array(array,a);	
		tower ((n-1),aux,from,to, array, a);
	

	
	}

}

void print_array (int **array, int n) {
	
	cout << "There was a move made here" << endl;
	for(int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
		
			cout << array[i][j] << " " ;
		}
	cout << endl;
	}
}



 main (){
	int n;
	cout << "\t\tEnter number of discs: ";
	cin >> n;
	int a = n;
	cout << "\n\n";
	int **array = new int *[n];
	//creates the array
	for(int i = 0; i < n; i++){
		array[i] = new int [3];
		for (int j = 0; j < 3; j++) {
			array[i][j] = 0;
		}

		for (int j = 0; j < 1; j++){
			array[i][j] = i+1;
		}
			
	}

	tower (n,'a','b','c', array,a);
}
