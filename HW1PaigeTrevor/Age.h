#pragma once

#include <iostream>
using namespace std;

struct Date
{
	string name;
	int UserYear;
	int UserMonth;
	int UserDay;

	int CurrentYear;
	int CurrentMonth;
	int CurrentDay;

	int YearAge;
	int MonthAge;
};

//displays the data input when running 
void displayData(Date d)
{
	cout << d.name << "'s Birthdate: " << d.UserMonth << "-" << d.UserDay << "-" << d.UserYear << endl;
	cout << "Current Date: " << d.CurrentMonth << "-" << d.CurrentDay << "-" << d.CurrentYear << endl;
}

//calculates the data that has been input
void calculateAge(Date d)
{
	d.YearAge = d.CurrentYear - d.UserYear;
	d.MonthAge = d.CurrentMonth - d.UserMonth;

	//if statement that subtracts one from the user's year age in case they haven't reached actual birthdate in that year
	if (d.UserMonth > d.CurrentMonth)
	{
		d.YearAge = d.YearAge - 1;
		d.MonthAge = d.MonthAge + 12;
	}
	//if statement that keeps months from being negative
	if (d.UserDay > d.CurrentDay && d.UserMonth != d.CurrentMonth)
	{
		d.MonthAge = d.MonthAge - 1;
	}
	//if statement that checks if you are even born
	if (d.UserYear > d.CurrentYear)
	{
		cout << "You Haven't Been Born Yet\n";
	}
	else
	{
		cout << d.name << "'s Current Age: " << d.YearAge << " years, and " << d.MonthAge << " months old!" << endl;
	}
}
