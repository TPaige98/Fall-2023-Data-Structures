#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

struct Card 
{
	int suit;
	int rank;
};

stack<Card> cardStack;
int top = -1;

int numberOfCards = 52;
int numberOfRanks = 13;
int numberOfSuits = 4;
int handSize = 5;

Card deck[52];
Card hand[5];

string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

int score = 0; 
int computerScore = 0;

void infoAndRules()
{
	cout << "\nWELCOME TO THE CARD GAME!" << endl;
	cout << "5 cards will be dealt to your hand when you play." << endl
		 << "The objective of the game is to beat the Computer's hand." << endl
		 << "Once the cards are dealt, they will be added together for the result." << endl
		 << "GOOD LUCK!" << endl << endl;
}

void createDeck(Card deck[])
{
	int Cards = 0;

	for (int s = 0; s < numberOfSuits; s++)
	{
		for (int r = 0; r < numberOfRanks; r++)
		{
			deck[Cards].suit = s;
			deck[Cards].rank = r;
			Cards++;
		}
	}
}

void shuffleDeck(Card deck[], int deckSize)
{
	srand(time(nullptr));

	for (int i = deckSize - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

void listCards(int r, int s)
{
	cout << ranks[r] << " of " << suits[s] << endl;
}

void pushDeck(Card deck[])
{
	for (int i = 0; i < 52; i++)
	{
		cardStack.push(deck[i]);
	}
}

void popDeck()
{
	for (int i = 0; i < 5; i++)
	{
		if (!cardStack.empty())
		{
			Card poppedCard = cardStack.top();
			cardStack.pop();
			hand[i] = poppedCard;
		}
		else
		{
			cout << "The deck is empty";
		}
	}
}

void printCard(Card card)
{
	cout << ranks[card.rank] << " of " << suits[card.suit] << endl;
}

void showHand(Card hand[])
{
	printf("PLAYER HAND: \n");
	for (int i = 0; i < 5; i++)
	{
		printCard(hand[i]);
	}
}

void calculateValue(Card hand[])
{
	int handValue = 0;
	int rankValue[] = { 14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

	for (int i = 0; i < handSize; i++)
	{
		int handRank = hand[i].rank;
		handValue += rankValue[handRank];
	}

	score = handValue;
	cout << "\nPLAYER SCORE = " << score << endl;
}

void calculateAndPrintComputerHand()
{
	srand(time(nullptr));
	computerScore = (11 + rand() % 59);

	cout << "COMPUTER SCORE = " << computerScore;
}

void compareHands()
{
	if (score > computerScore)
	{
		cout << "\n\nCONGRATULATIONS! PLAYER WINS!";
	}
	else
	{
		cout << "\n\nBETTER LUCK NEXT TIME. COMPUTER WINS!";
	}
}