#pragma once
#include <iostream>
#include <fstream>

//sources used on project:
//Merging = https://www.geeksforgeeks.org/cpp-program-to-merge-two-sorted-arrays/
//Sorting = Bubble Sort code from Class

using namespace std;

//Structure to store Team Data
struct TeamData
{
	string awayCity;
	string awayTeam;
	string homeCity;
	string homeTeam;
	int awayScore;
	int homeScore;
};

//Variables needed for the list and array data
const int arrayData = 10;
const int finalArrayData = 30;

TeamData list1[arrayData];
TeamData list2[arrayData];
TeamData list3[arrayData];
TeamData list4[finalArrayData];

//Function written to populate the first list
void populateList1()
{
	int index = 0;
	TeamData inputData;

	ifstream inputFile("list1.txt");

	if (inputFile.is_open())
	{
		while (inputFile >> inputData.awayCity >> inputData.awayTeam >> inputData.homeCity >> inputData.homeTeam
			>> inputData.awayScore >> inputData.homeScore)
		{
			list1[index++] = inputData;
		}
	}
	inputFile.close();
}

//Function written to populate the second list
void populateList2()
{
	int index = 0;
	TeamData inputData;

	ifstream inputFile("list2.txt");

	if (inputFile.is_open())
	{
		while (inputFile >> inputData.awayCity >> inputData.awayTeam >> inputData.homeCity >> inputData.homeTeam
			>> inputData.awayScore >> inputData.homeScore)
		{
			list2[index++] = inputData;
		}
	}
	inputFile.close();
}

//Function written to populate the third list
void populateList3()
{
	int index = 0;
	TeamData inputData;

	ifstream inputFile("list3.txt");

	if (inputFile.is_open())
	{
		while (inputFile >> inputData.awayCity >> inputData.awayTeam >> inputData.homeCity >> inputData.homeTeam
			>> inputData.awayScore >> inputData.homeScore)
		{
			list3[index++] = inputData;
		}
	}
	inputFile.close();
}

//Function written to merge the lists into the fourth array: Info found at source listed above
void mergeLists(int n1, int n2, int n3)
{
	int i = 0, j = 0, k = 0, l = 0;

	while (i < n1)
	{
		list4[l++] = list1[i++];
	}

	while (j < n2)
	{
		list4[l++] = list2[j++];
	}

	while (k < n3)
	{
		list4[l++] = list3[k++];
	}
}

//Function to swap the team data entries
void swapTeams(TeamData &team1, TeamData &team2)
{
	TeamData temp = team1;
	team1 = team2;
	team2 = temp;
}

//Function to sort the team data entries in the fourth array
void sortTeams(TeamData arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j].awayCity > arr[j + 1].awayCity)
			{
				swapTeams(arr[j], arr[j + 1]);
			}
		}
	}
}

//Function to print the arrays to the console
void printTeamArrays(TeamData arr[], int size, string teamFile)
{
	ofstream outputFile;
	outputFile.open(teamFile);

	for (int i = 0; i < size; i++)
	{
		cout << arr[i].awayCity << " " << arr[i].awayTeam << " @ " << arr[i].homeCity << " " << arr[i].homeTeam << "\nFinal Score: " << arr[i].awayScore << "-" << arr[i].homeScore << endl << endl;

		outputFile << arr[i].awayCity << " " << arr[i].awayTeam << " @ " << arr[i].homeCity << " " << arr[i].homeTeam << "\nFinal Score: " << arr[i].awayScore << "-" << arr[i].homeScore << endl << endl;
	}
}