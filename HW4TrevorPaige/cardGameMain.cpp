#include "cardGame.h"

int main()
{
	infoAndRules();

	createDeck(deck);

		
	//-- This code is used to show the list of the cards at the start of the game before shuffling --

		cout << "LIST OF CARDS IN THE DECK:" << endl;
		for (int i = 0; i < numberOfCards; i++) {listCards(deck[i].rank, deck[i].suit);}
		cout << endl;

	shuffleDeck(deck, numberOfCards);

	cout << "\nLIST OF SHUFFLED CARDS:" << endl;

	for (int i = 0; i < numberOfCards; i++) { listCards(deck[i].rank, deck[i].suit); }
	cout << endl;

	pushDeck(deck);

	popDeck();

	showHand(hand);

	calculateValue(hand);

	calculateAndPrintComputerHand();

	compareHands();

	return 0;
}