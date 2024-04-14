#pragma once
#include <iostream>
#include <ctime>
#include <random>
#include <fstream>

using namespace std;

//const int for array to be 50 random numbers
//secondary array that will be used later for the duplicate numbers
const int n = 50;
int duplicateArray[n];
int duplicates = 0;


// Linked List struct, just used last name due to initial array also being related to last name 
struct PaigeListNode
{
	int value;
	struct PaigeListNode* next;
};
	PaigeListNode* head;

//---------------------------------------------------------------------------------------

// Array named as last name Paige to generate random numbers from 1 to 100
void generateRandom(int Paige[], ostream& output)
{
	printf("Content of the Initial Random Array\n");
	output << "Content of the Initial Random Array\n";

	srand(time(NULL));
	for (int r = 0; r < n; r++)
		Paige[r] = std::rand() % 100;
}

//---------------------------------------------------------------------------------------

// Method to add nodes to the linked list
void addNodes(int num)
{
	PaigeListNode* myNode;
	PaigeListNode* nodePtr;

	myNode = new PaigeListNode;
	myNode->value = num;
	myNode->next = NULL;

	if (!head)
	{
		head = myNode;
	}
	else
	{
		nodePtr = head;

		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = myNode;
	}//else

}// addNodes method

//---------------------------------------------------------------------------------------

// Source Used for Sorting Nodes: https://www.youtube.com/watch?v=zCsXoYOTFVs
// Method for sorting the nodes in the Linked List in Descending Order
void sortNodes()
{
	PaigeListNode* current = head;
	PaigeListNode* index = NULL;
	int temp;

	if (head == NULL) 
	{
		return;
	}
	else
	{
		while (current != NULL)
		{
			index = current->next;

			while (index != NULL)
			{
				if (current->value < index->value)
				{
					temp = current->value;
					current->value = index->value;
					index->value = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}//sortNodes method

//---------------------------------------------------------------------------------------

//Source Used for Removing Duplicates from the Linked List: https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
//Method to remove and store duplicates from the linked list
void remove_store_Duplicates(PaigeListNode* head)
{
	//pointer to traverse the linked list
	PaigeListNode* current = head;
	PaigeListNode* next_delete;

	if (current == NULL)
	{
		return;
	}

	while (current->next != NULL)
	{
		if (current->value == current->next->value)
		{
			//Stores the duplicates into an array
			duplicateArray[duplicates] = current->value;
			duplicates++;

			next_delete = current->next;
			current->next = next_delete->next;
			delete next_delete;
		}
		else
		{
			current = current->next;
		}

	}
}//remove_store_Duplicates method

//---------------------------------------------------------------------------------------

//Method that counts duplicates
void countDuplicates(ostream& output)
{
	int count = 1;
	printf("\n\nContent of the Duplicated Numbers in Second Array\n");
	output << "\n\nContent of the Duplicated Numbers in the Second Array\n";

	for (int i = 0; i < duplicates; i++)
	{
		//checks index of array to see if element next to it is identical, if identical add 1 to count
		if (duplicateArray[i] == duplicateArray[i + 1])
		{
			count++;
		}
		else
		{
			if (count > 0)
			{
				printf("%d was duplicated %d time(s)\n", duplicateArray[i], count);
				output << duplicateArray[i] << " was duplicated " << count << " time(s)\n";
			}
			count = 1;
		}
	}
}//countDuplicates method

//---------------------------------------------------------------------------------------

//Method to display the Linked List
void displayPaigeList(int& count, ostream& output)
{
	PaigeListNode* nodePtr;
	nodePtr = head;

	printf("\n\nContent of the Linked List with Duplicates Removed\n");
	output << "\n\nContent of the Linked List with Duplicates Removed\n";

	while (nodePtr)
	{
		printf("%d | ", nodePtr->value);
		output << nodePtr->value << " | ";
		nodePtr = nodePtr->next;
		count++;
	}//while

	printf("\n\nTotal Elements in the Linked List: %d", count); \
	output << "\n\nTotal Elements in the Linked List: " << count;
}//display list method

