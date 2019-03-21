/**
Written by: Max Fine
Resubmission: 3/22/2019

Validate input that is entered by a user for several functions,
and make sure that the input pertains to the prompt/function
as well as validating proper input.
**/

#include <iostream>
#include <locale>
#include <string>
#include <math.h>

using namespace std;

//Convert number to color name
string numConvert(int a);
//Convert color name to number
int nameConvert(string s);
//Calculate the decimal value of a numberator over denominator
double ratioCalc(int x, int y);
//Erase contents
void flush();

int main(){

	char choice[3] = {'y'};
	string colorName = "";
	//char strBuffer[32];
	string strBuffer = "";
	int num = 0, denom = 0, numIn, colorNum, i, strCount = 0;
	double ratio;
	float gpa;

	cout << "\nWelcome to the input validator!\n" << endl;

	//Repeat loop until user terminates with 'n' or any char except 'y'
	while(choice[0] == 'y'){

		cout << "Enter numerator: ";
		if(!(cin >> num)){

			flush();
			cout << "Invalid input" << endl;
		}

		cout << "Enter denominator: ";
		if(!(cin >> denom)){

			flush();
			cout << "Invalid input" << endl;
		}

		//Validate that num and denom are valid
		if(num && denom){
			//Calculate ratio between num / denom
			ratio = ratioCalc(num, denom);
			if(ratio == -1){

				cout << "Invalid input" << endl;
			}else{

				cout << "Ratio: " << ratio << endl;
			}
		}

		//GPA will be float value restricted to three decimal places (x.xxx)
		cout << "\nEnter GPA: ";
		//Check for valid input type
		if(!(cin >> gpa)){

			flush();
			cout << "Invalid input" << endl;
		}else{

			//GPA input that is greater than 4.0 is invalid
			if(gpa > 4.0 || gpa < 0){

				gpa = 0;
				cout << "Invalid input" << endl;
			}else{

				gpa = roundf(gpa * 1000) / 1000;
				cout << "GPA: " << gpa << endl;
			}
		}


		cout << "\nEnter color number: ";
		//Check for valid input type
		if(!(cin >> numIn)){

			flush();

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

			flush();
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
		//Clear input buffer
		flush();
		getline(cin, strBuffer);
		if(strBuffer.size() > 32){

			cout << "Invalid input" << endl << endl;
		}else{

			cout << "Length: " << strBuffer.size() << endl;
			cout << "Data: " << strBuffer << endl << endl;
		}

		//Prompt user for additional loop
		//For some reason, user must press enter once more after the final
		//string input line.
		cout << "More data to enter? (y/n): ";
		cin >> choice;
	}

	cout << "\nGoodbye" << endl;

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
	ratio_c = num_c / (double)denom_c;

	if(ratio_c <= -1 || ratio_c >= 1){

		ratio_c = -1;
	}

	return ratio_c;
}

//Function to flush out the cin buffer
void flush(){

	cin.clear();
	cin.ignore(1000, '\n');
}
