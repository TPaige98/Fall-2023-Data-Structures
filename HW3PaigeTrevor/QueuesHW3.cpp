#include "QueueFunctions.h"

int main()
{
	ifstream inputFile;
	string fileName = "C:\\Users\\XzXCo\\OneDrive\\NSU College\\Computer Science Work\\Data Structures\\HW3PaigeTrevor\\EmployeeData.txt";
	string stubFile = "C:\\Users\\XzXCo\\OneDrive\\NSU College\\Computer Science Work\\Data Structures\\HW3PaigeTrevor\\Paige.txt";
	string summaryFile = "C:\\Users\\XzXCo\\OneDrive\\NSU College\\Computer Science Work\\Data Structures\\HW3PaigeTrevor\\Summary.txt";

	inputQueue(fileName);

	payStubQueue();

	deqeuePayStubToFile(stubFile);

	summaryReport(summaryFile);

	printf("\n");

	return 0;
}