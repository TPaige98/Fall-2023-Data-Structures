#include <iostream>
#include <string>
#include "Age.h"

using namespace std;

int main()
{
	Date d;

	//User Name
	cout << "Enter Full Name: ";
	getline(cin, d.name);

	//User Birth Year
	cout << "Enter Birth Year (1-XXXX): ";

	//while loop to catch invalid input
	while (!(cin >> d.UserYear) || d.UserYear < 1)
	{
		cout << "Please Enter a Valid Year (1-XXXX): ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	//User Birth Month
	cout << "Enter Birth Month (1-12): ";

	//while loop to catch invalid input
	while (!(cin >> d.UserMonth) || d.UserMonth < 1 || d.UserMonth > 12)
	{
		cout << "Please Enter a Valid Month (1-12): ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	//User Birth Day
	cout << "Enter Birth Day (1-31): ";

	//while loop to catch invalid input
	while (!(cin >> d.UserDay) || d.UserDay < 1 || d.UserDay > 31)
	{
		cout << "Please Enter a Valid Day (1-31): ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	
	cout << endl;

	//Current Year
	cout << "Enter Current Year (1-XXXX): ";

	//while loop to catch invalid input
	while (!(cin >> d.CurrentYear) || d.CurrentYear < 1)
	{
		cout << "Please Enter a Valid Year (1-XXXX): ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	//Current Month
	cout << "Enter Current Month (1-12): ";

	//while loop to catch invalid input
	while (!(cin >> d.CurrentMonth) || d.CurrentMonth < 1 || d.CurrentMonth > 12)
	{
		cout << "Please Enter a Valid Year (1-12): ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	//Current Day
	cout << "Enter Current Day (1-31): ";

	//while loop to catch invalid input
	while (!(cin >> d.CurrentDay) || d.CurrentDay < 1 || d.CurrentDay > 31)
	{
		cout << "Please Enter a Valid Year (1-31): ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << endl;

	displayData(d);

	calculateAge(d);

	return 0;
}

