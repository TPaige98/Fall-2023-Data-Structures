#include "HW2Functions.h"

int main()
{
	int count = 0;

	ofstream fileName("HW2 Output File.txt");
	if (fileName.is_open())
	{
		int Paige[100];
		generateRandom(Paige, fileName);

		for (int i = 0; i < n; i++)
		{
			printf("%d | ", Paige[i]);
			fileName << Paige[i] << " | ";
		}

		for (int i = 0; i < n; i++)
			addNodes(Paige[i]);

		sortNodes();

		remove_store_Duplicates(head);

		displayPaigeList(count, fileName);

		countDuplicates(fileName);

		fileName.close();
	}
	else cout << "Unable to open file";

			return 0;
}