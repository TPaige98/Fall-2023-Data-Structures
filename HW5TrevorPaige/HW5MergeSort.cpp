#include "Merge.h"

int main()
{
	int listSize1 = 10;
	int listSize2 = 10;
	int listSize3 = 10;

	string teamFile = "C:\\Users\\XzXCo\\OneDrive\\NSU College\\Computer Science Work\\Data Structures\\HW5TrevorPaige\\Paige.txt";

    populateList1();
	populateList2();
	populateList3();

	mergeLists(listSize1, listSize2, listSize3);

	sortTeams(list4, finalArrayData);

	printTeamArrays(list4, finalArrayData, teamFile);

	return 0;
}