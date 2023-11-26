#include <iostream>
#include <string>



int main() { 

	using namespace std;
	

	const int year = 2023;
	string name;
	int birth_year;

	cout << "What is your name? " << flush;
	cin >> name;
	

	cout << "What year were you born";
	cin >> birth_year;

	cout << " Your name is " << name 
				<< " and you are approximately "
				<< (year - birth_year) << " years old. " << endl << flush;


	return 0;
}
