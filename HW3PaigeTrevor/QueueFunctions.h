#pragma once
#include <iostream>
#include <queue>
#include <fstream>
#include <iomanip>

using namespace std;

//structure for the Employee Data
struct EmployeeData 
{
	int ID;
	string fName;
	string lName;
	string name;
	string job;

	int hours;
	double payrate;
	double grosspay;
	double marginaltax;
	double netpay;

	double federaltaxHeld;
	double statetaxHeld;
	double socialtaxHeld;
	double medictaxHeld;
};

//queues and constant variables
queue<EmployeeData> dataQueue;
queue<EmployeeData> payQueue;
queue<EmployeeData> summaryQueue;

const double statetax = 0.0475;
const double socialtax = 0.0620;
const double medictax = 0.0145;

//function to input data from EmployeeData file into a queue
void inputQueue(string fileName)
{
	ifstream inputFile;
	inputFile.open(fileName);

	EmployeeData list;
	while (inputFile >> list.ID >> list.fName >> list.lName >> list.job >> list.hours >> list.payrate >> list.marginaltax)
	{
		dataQueue.push(list);

		//Just used to keep track of data
		//cout << list.ID << " " << list.fName << " " << list.lName << " | " << list.job << " | Hours: "
			//<< list.hours << " | Rate: " << list.payrate << endl;
	}

	inputFile.close();
}

//function to take data from inputQueue and place it in another queue(payStubQueue) to calculate paystubs.
//this function also prints out the paystub data to the console.
void payStubQueue()
{
	cout << "PAYSTUB INFORMATION: " << endl;

	while (!dataQueue.empty())
	{
		EmployeeData list = dataQueue.front();
		dataQueue.pop();

		list.grosspay = list.hours * list.payrate;
		list.federaltaxHeld = list.grosspay * list.marginaltax;
		list.statetaxHeld = list.grosspay * statetax;
		list.socialtaxHeld = list.grosspay * socialtax;
		list.medictaxHeld = list.grosspay * medictax;
		list.netpay = list.grosspay - list.federaltaxHeld - list.statetaxHeld - list.socialtaxHeld - list.medictaxHeld;
		
		payQueue.push(list);

		cout << list.ID << " " << list.fName << " " << list.lName << endl << "GROSS: "
			<< fixed << setprecision(2) << list.grosspay << " | FED: " << list.federaltaxHeld << " | STATE: "
			<< list.statetaxHeld << " | SOC: " << list.socialtaxHeld << " | MED: "
			<< list.medictaxHeld << "\nNET PAY: " << list.netpay << "\n" << endl;
	}
}

//function to take the data from the payStubQueue and dequeue it all into a text file.
//This function also queues the data into a summaryQueue for further calculations down the line.
void deqeuePayStubToFile(string stubFile)
{
	ofstream outputFile;
	outputFile.open(stubFile);

	outputFile << "PAYSTUB INFORMATION: " << endl;

	while (!payQueue.empty())
	{
		EmployeeData list = payQueue.front();
		summaryQueue.push(list);
		payQueue.pop();

		outputFile << list.ID << " " << list.fName << " " << list.lName << endl << "GROSS: " << fixed
			<< setprecision(2) << list.grosspay << " | FED: " << list.federaltaxHeld << " | STATE: "
			<< list.statetaxHeld << " | SOC: " << list.socialtaxHeld << " | MED: " << list.medictaxHeld
			<< "\nNET PAY: " << list.netpay << "\n" << endl;
	}

	outputFile.close();
}

//function showing the summary report of all the values necessary and printing them to the console and a file.
void summaryReport(string summaryFile)
{
	ofstream outputFile;
	outputFile.open(summaryFile);

	double totalGross = 0.0;
	double totalFed =  0.0;
	double totalState = 0.0;
	double totalSoc = 0.0;
	double totalMed = 0.0;
	double totalNet = 0.0;

	while (!summaryQueue.empty())
	{
		EmployeeData list = summaryQueue.front();
		summaryQueue.pop();

		totalGross += list.grosspay;
		totalFed += list.federaltaxHeld;
		totalState += list.statetaxHeld;
		totalSoc += list.socialtaxHeld;
		totalMed += list.medictaxHeld;
		totalNet += list.netpay;
	}

	outputFile << "SUMMARY OF PAYSTUB DATA: " << endl << "A. Total Gross Pay: " << fixed << setprecision(2) << totalGross << endl
		<< "B. Total Federal Taxes: " << totalFed << endl << "C. Total State Taxes: " << totalState
		<< endl << "D. Total Social Security Taxes: " << totalSoc << endl << "E. Total Medicare Taxes: "
		<< totalMed << endl << "F. Total Net Pay: " << totalNet << endl;

	cout << "SUMMARY OF PAYSTUB DATA: " << endl << "A. Total Gross Pay: " << fixed << setprecision(2) << totalGross << endl
		<< "B. Total Federal Taxes: " << totalFed << endl << "C. Total State Taxes: " << totalState
		<< endl << "D. Total Social Security Taxes: " << totalSoc << endl << "E. Total Medicare Taxes: "
		<< totalMed << endl << "F. Total Net Pay: " << totalNet << endl;

	outputFile.close();
}


//Sources used for queues
//https://www.geeksforgeeks.org/queue-cpp-stl/#
//https://cplusplus.com/reference/queue/queue/
//https://youtu.be/jaK4pn1jXTo?si=OykMDQryVnFrkNsA

//Source used for setprecision
//https://stackoverflow.com/questions/16280069/show-two-digits-after-decimal-point-in-c

