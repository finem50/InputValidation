#include <iostream>
#include <locale>

using namespace std;

int main(){

	char choice[3] = {'y'};
	char colorName[10] = {};
	char strBuffer[32] = {};
	int num, denom, color, length;
	double ratio;
	float gpa;

	cout << "Welcome to the input validator!\n" << endl;

	//Repeat loop until user terminates
	while(choice[0] == 'y'){

		cout << "Enter numerator: ";
		cin >> num;
		cout << "\nEnter denominator: ";
		cin >> denom;
		//Ratio should be determined by numerator / denominator
		//If numerator > denominator then the input is invalid
		if (num < denom){

			ratio = num / denom;
			cout << "Ratio: " << ratio << endl;
		}else{

			ratio = 0;
			cout << "Invalid input." << endl;
		}

		cout << "\n\nEnter GPA: ";
		cin >> gpa;
		//GPA input that is greater than 4.0 is invalid
		if(gpa > 4.0){

			gpa = 0;
			cout << "Invalid input." << endl;
		}else{

			cout << gpa;
		}

		/* Different colors will correspond with different numbers, as follows:
		2 == Blue
		3 == Crimson
		7 == Gold
		12 == Lime
		20 == Tan
		**/
		cout << "\nEnter color number: ";
		cin >> color;
		cout << "\nName: ";

		switch(color){

			case 2:
				cout << "Blue" << endl;
				break;

			case 3:
				cout << "Crimson" << endl;
				break;

			case 7:
				cout << "Gold" << endl;
				break;

			case 12:
				cout << "Lime" << endl;
				break;

			case 20:
				cout << "Tan" << endl;;
				break;

			default:
				cout << "Invalid input." << endl;;
				break;
		}

		cout << "\n\nEnter color name: ";
		cin >> colorName;
		colorName[0] = tolower(colorName[0]);
		cout << "Color: ";

		/*Because each color option begins with a unique letter,
		we can use a switch case off of the char in colorName[0]
		**/
		switch(colorName[0]){

			case 'b':
				cout << "2" << endl;
				break;

			case 'c':
				cout << "3" << endl;
				break;

			case 'g':
				cout << "7" << endl;
				break;

			case 'l':
				cout << "12" << endl;
				break;

			case 't':
				cout << "20" << endl;
				break;

			default:
				cout << "Invalid input." << endl;
				break;
		}

		cout << "\n\nEnter string: ";
		cout << "\nLength: ";
		cout << "\nData: ";

		cout << "\nMore data to enter? (y/n)";

	}

	return 0;
}
