#include <iostream>
#include <locale>
#include <string>
#include <math.h>

using namespace std;

string numConvert(int a);
int nameConvert(string s);
double ratioCalc(int x, int y);

int main(){

	char choice[3] = {'y'};
	string colorName = "";
	char strBuffer[128] = {};
	char strEntry[32] = {};
	int num, denom, numIn, colorNum, i, strCount = 0;
	double ratio;
	float gpa;

	cout << "\nWelcome to the input validator!\n" << endl;

	//Repeat loop until user terminates with 'n' or any char except 'y'
	while(choice[0] == 'y'){

		cout << "Enter numerator: ";
		if(!(cin >> num)){

			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
		}

		cout << "Enter denominator: ";
		if(!(cin >> denom)){

			cin.clear();
			cin.ignore(1000, '\n');
		}

		//Calculate ratio between num / denom
		ratio = ratioCalc(num, denom);
		if(ratio == -1){

			cout << "Invalid input" << endl;
		}else{

			cout << "Ratio: " << ratio << endl;
		}


		//GPA will be float value restricted to three decimal places (x.xxx)
		cout << "\nEnter GPA: ";
		//Check for valid input type
		if(!(cin >> gpa)){

			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
		}

		//GPA input that is greater than 4.0 is invalid
		if(gpa > 4.0){

			gpa = 0;
			cout << "Invalid input" << endl;
		}else{

			gpa = roundf(gpa * 1000) / 1000;
			cout << "GPA: " << gpa << endl;
		}


		cout << "\nEnter color number: ";
		//Check for valid input type
		if(!(cin >> numIn)){

			cin.clear();
			cin.ignore(1000, '\n');

		}
		//Convert from color number -> name
		colorName = numConvert(numIn);
		if (colorName == "Invalid input"){
			cout << colorName << endl << endl;
		}else{
			cout << "Name: " << colorName << endl << endl;;
		}


		cout << "Enter color name: ";
		//Check for valid input type
		if(!(cin >> colorName)){

			cin.clear();
			cin.ignore(1000, '\n');
		}
		//Convert from color name -> number
		colorNum = nameConvert(colorName);
		if(colorNum == -1){

			cout << "Invalid input" << endl;
		}else{

			cout << "Color: " << colorNum << endl;
		}


		//must use getline to accomodate potential space character
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

		//Prompt user for additional loop
		cout << "\n\nMore data to enter? (y/n): ";
		cin >> choice;
	}

	return 0;
}

/* Different colors will correspond with different numbers, as follows:
2 == Blue
3 == Crimson
7 == Gold
12 == Lime
20 == Tan
**/
string numConvert(int a){

	int num = a;
	string color;

	switch(a){

		case 2:
			color = "Blue";
			break;

		case 3:
			color = "Crimson";
			break;

		case 7:
			color = "Gold";
			break;

		case 12:
			color = "Lime";
			break;

		case 20:
			color = "Tan";
			break;

		default:
			color = "Invalid input";
			break;
	}

	return color;
}

//Conversion between color name and number is same as previously-mentioned
int nameConvert(string s){

	string name = s;
	int num;


	//Nested if/else to match input with color number.
	if(name == "Blue" || name == "blue"){

		num = 2;
		name = "";
	}else if(name == "Crimson" || name == "crimson"){

		num = 3;
		name = "";
	}else if(name == "Gold" || name == "gold"){

		num = 7;
		name = "";
	}else if(name == "Lime" || name =="lime"){

		num = 12;
		name = "";
	}else if(name == "Tan" || name == "tan"){

		num = 20;
		name = "";
	}else{

		return -1;
		name = "";
	}

	return num;
}

//Ratio should be determined by numerator / denominator
//If numerator > denominator then the input is invalid (determined by -1)
double ratioCalc(int x, int y){

	int num_c = x, denom_c = y;
	double ratio_c;

	if(num_c < denom_c){

		ratio_c = num_c / (double)denom_c;
	}else{

		ratio_c = -1;
	}

	return ratio_c;
}
