#include <iostream>
#include <locale>
#include <string>



using namespace std;


int main(){

	char choice[3] = {'y'};
	string colorName = "";
	char strBuffer[128] = {};
	char strEntry[32] = {};
	int num, denom, colorNum, length, i, strCount = 0;
	double ratio;
	float gpa;

	cout << "\nWelcome to the input validator!\n" << endl;

	//Repeat loop until user terminates
	while(choice[0] == 'y'){

		cout << "Enter numerator: ";
		if(!(cin >> num)){

			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input." << endl;
		}

		cout << "Enter denominator: ";
		if(!(cin >> denom)){

			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input." << endl;
		}

			//Ratio should be determined by numerator / denominator
			//If numerator > denominator then the input is invalid
			if(num < denom){

				ratio = num / (double)denom;
				cout << "Ratio: " << ratio << endl;
			}else{

				ratio = 0;
				cout << "Invalid input." << endl;
			}

		cout << "\nEnter GPA: ";
		cin >> gpa;
		//GPA input that is greater than 4.0 is invalid
		if(gpa > 4.0){

			gpa = 0;
			cout << "Invalid input." << endl;
		}else{

			cout << "GPA: " << gpa << endl;
		}

		/* Different colors will correspond with different numbers, as follows:
		2 == Blue
		3 == Crimson
		7 == Gold
		12 == Lime
		20 == Tan
		**/
		cout << "\nEnter color number: ";
		cin >> colorNum;
		cout << "Name: ";

		switch(colorNum){

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

		cout << "\nEnter color name: ";
		cin >> colorName;
		cout << "Color: ";
 		/*
		Nested if/else to match input with color number. It's not ideal but
		it works.
 		**/
		if(colorName == "Blue" || colorName == "blue"){

			cout << "2" << endl;
			colorName = "";
		}else if(colorName == "Crimson" || colorName == "crimson"){

			cout << "3" << endl;
			colorName = "";
		}else if(colorName == "Gold" || colorName == "gold"){

			cout << "7" << endl;
			colorName = "";
		}else if(colorName == "Lime" || colorName =="lime"){

			cout << "12" << endl;
			colorName = "";
		}else if(colorName == "Tan" || colorName == "tan"){

			cout << "20" << endl;
			colorName = "";
		}else{

			cout << "Invalid input." << endl;
			colorName = "";
		}

		cout << "\nEnter string: ";
		cin >> strEntry;
		strncpy(strEntry, strBuffer, sizeof(strEntry));

		for(i = 0; i < sizeof(strEntry); i++){

			strCount += 1;
		}
		cout << "Length: " << strCount << endl;
		cout << "Data: ";
		for(i = 0; i < sizeof(strEntry); i++){

			cout << strEntry[i];
		}


		cout << "\n\nMore data to enter? (y/n): ";
		cin >> choice;

	}

	return 0;
}
