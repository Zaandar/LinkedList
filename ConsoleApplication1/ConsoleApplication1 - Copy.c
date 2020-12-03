#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define constant SLOTS the value 1
#define SLOTS 1
//define constant SCRATCH the value 2
#define SCRATCH 2
//define constant BLACKJACK the value 3
#define BLACKJACK 3

//black jack constants
#define FACES 13
#define SUITS 4
#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3
#define BUST 21

//scratch offs constants
#define ONE 1
#define TWO 2
#define FIVE 5

//scratch offs structs

struct OneDollar
{
	int winNumber;
	int numbers[5];
	float prizes[5];
	char bonus[2];
};

struct TwoDollar
{
	int winNumber[2];
	int numbers[10];
	float prizes[10];
	char bonus[2];
};

struct FiveDollar
{
	int winNumber[4];
	int numbers[12];
	float prizes[12];
	char bonus[4];
};


//function prototypes

//welcome screen function
void welcomeScreen() {
	printf("######################################\n");
	printf("### Welcome to the Knights Casino! ###\n");
	printf("######################################\n\n");
};

void initializeUsed(char used[SUITS][FACES]) {

	int s;
	int f;
	for (s = 0; s < SUITS; s++) {
		for (f = 0; f < FACES; f++) {
			used[s][f] = 0;
		}
	}
};


// deals the cards
int deal(char deck[SUITS][FACES], char dealt[SUITS][FACES]) {
	const int CARDS = 52;
	static int cards = 0;
	int used = 0;
	int score = -1;
	int face;
	int suit;
	while (used == 0) {
		suit = (int)rand() % SUITS;
		face = (int)rand() % FACES;
		if (dealt[suit][face] == 0) {
			used = 1;
			dealt[suit][face] = 1;
			cards++;
		}
	}

	switch (face) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		score = face + 2;
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		score = 10;
		break;
	case 12:
		score = 11;
		break;
	}
	return score;
};
//establishes the result of the game, win, lose or push
int results(int player, int dealer) {
	const int WIN = 20;
	const int PUSH = 10;
	const int LOSE = 0;
	if (dealer > BUST) {
		printf("Dealer busted!\n You gained $10\n");
		return PUSH;
	}
	else if (player > dealer) {
		printf("You won!\n Gained $20\n");
		return WIN;
	}
	else if (player == dealer) {

		printf("It was a push!\n");
		return PUSH;

	}
	else {
		printf("You lost!\n Gained nothing.\n");
		return LOSE;
	}
};

//this function displays the menu
int displayMenu() {
	int game;
	//unless user enters valid number for menu, the menu will continue to appear
	do {
		printf("Select a game to play by entering the number next to the game!\n");
		printf("1. Slots\n");
		printf("2. Scratch Offs\n");
		printf("3. Black Jack\n");
		//scans in the users menu selection
		scanf_s("%d", &game);
	} while (game < 1 || game > 3);
	return game;
};

//This function clears the screen after the Enter key is pressed
void clearScreen() {

	printf("Please press <Enter> to continue\n\n");

	char key;
	scanf_s("%c", &key, 1);
	system("cls");
	//system("clear");
};

//creates random symbol
char randomSymbol() {
	char symbol;
	const int SYMBOLS = 6;
	const char symbols[] = { '$','%','&','#','@','!' };
	int num = (rand() % 6);

	symbol = symbols[num];

	return symbol;
};

//slots game
int playSlots(int cash) {
	const int BET = 5;
	const int MATCH_TWO = 5;
	const int MATCH_THREE = 50;
	int play = 1;
	char symOne, symTwo, symThree;
	printf("Let's play Slots!\n");
	printf("Your cash balance is $%d. The bet is $%d\n", cash, BET);
	printf("Match two symbols to win $%d.\n", BET);
	printf("Match all three symbols to win $%d\n", BET * 10);

	//checks if user has enough money to play
	if (cash < 5) {
		play = 0;
	}

	//rolls the slots
	while (play > 0) {
		cash -= BET;
		printf("Spinning...\n\n");
		symOne = randomSymbol();
		symTwo = randomSymbol();
		symThree = randomSymbol();

		//prints results
		printf("%c %c %c\n\n", symOne, symTwo, symThree);
		//if the player matches all 3 they win $50
		if (symOne == symTwo && symTwo == symThree) {
			cash += MATCH_THREE;
			printf("You won $%d!\n", MATCH_THREE);
		}// if the player matches two, they win $5
		else if (symOne == symTwo || symOne == symThree || symTwo == symThree) {
			cash += MATCH_TWO;
			printf("You won $%d!\n", MATCH_TWO);
		}
		else {
			cash += 0;
			printf("You did not win.\n");
		}//shows the player their current balance after playing
		printf("You currently have $%d\n", cash);
		//checks if the player has enough to play, and asks if they would like to play again
		if (cash > 5) {
			printf("Would you like to play again?(1 for yes, 0 for no.)\n");
			scanf_s("%d", &play);
		}
		else {
			break;
		}
	}
	printf("Thank you for playing Knights Casino!\n");
	return cash;
};


//****Scratch offs functions****

struct OneDollar createScratchOffOne(struct OneDollar oneSO) {

	oneSO.winNumber = 23;
	for (int i = 0; i < 4; i++) {
		oneSO.numbers[i] = i;
		oneSO.prizes[i] = (float)i;
	};
	for (int i = 0; i < 2; i++) {
		oneSO.bonus[i] = (char)i;
	}
	printf("%d", oneSO.winNumber);
	/*const int SYMS = 2;
	const int NUM = 5;
	const int BASE = 20;
	const char symbols[]={'$','%','#','@','!'};
	int sym;
	int n;

	oneSO.winNumber = rand() % 21;
	*/
	return oneSO;
};

int displayScratchOffOne() {
	return 0;
};

int createScratchOffTwo() {
	return 0;
};

int displayScratchOffTwo() {
	return 0;
};

int createScratchOffFive() {
	return 0;
};

int displayScratchOffFive() {
	return 0;
};

//Scratch offs game
int playScratchOffs(int cash) {

	printf("Let's play Scratch Offs!\n");

	//scratch off local variables
	int type;
	int count;
	//loop control
	int c;

	int nu = 23;
	int n[5] = {1, 2, 3, 4, 5};
	float p[5] = {6.01f, 7.01f, 8.01f, 9.01f, 10.01f};
	char b[2] = {'a', 'b'};
	struct OneDollar oneSO = {
		23,
		{1, 2, 3, 4, 5},
		{23.1f, 7.01f, 8.01f, 9.01f, 10.01f},
		{'a', 'b'} };
	//struct TwoDollar twoSO;
	//struct FiveDollar fiveSO;

	printf("Players can select from One Dollar, Two Dollar, and Five Dollar tickets!\n");
	printf("Prizes are based on the ticket that is played.\n");
	printf("Please enter which type of scratch off you would like to play\n");
	printf("(1 = One Dollar, 2 = Two Dollar, 5 = Five Dollar)\n");
	scanf_s("%d", &type);
	printf("How many scratch offs would you like?\n");
	scanf_s("%d", &count);

	for (c = 0; c <= count; c++)
	{
		switch (type) {
			{
		case ONE:
			oneSO = createScratchOffOne(oneSO);
			displayScratchOffOne(oneSO);
			break;
			}/*
			case TWO:
			{
			struct TwoDollar = createScratchOffTwo(struct TwoDollar);
			displayScratchOffTwo(struct TwoDollar);
			break;
			}
			case FIVE:
			{
			struct FiveDollar = createScratchOffFive(struct FiveDollar);
			displayScratchOffFive(struct FiveDollar);
			break;
			}*/
		}
	}

	return cash;
};
//BlackJack game functions


//creates the deck of cards to be played with
void initializeDeck(char deck[SUITS][FACES]) {
	const char faces[] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };

	int s, f;

	for (s = 0; s < SUITS; s++) {
		for (f = 0; f < FACES; f++) {

			deck[s][f] = faces[f];
		}

	}
};
//displays the deck of cards
void printDeck(char deck[SUITS][FACES]) {

	int s, f;

	for (s = 0; s < 4; s++) {

		for (f = 0; f < 13; f++) {
			switch (s) {
			case CLUBS: {
				printf("%c of Clubs\n", deck[s][f]);
				break;
			}
			case DIAMONDS: {
				printf("%c of Diamonds\n", deck[s][f]);
				break;
			}
			case HEARTS: {
				printf("%c of Hearts\n", deck[s][f]);
				break;
			}
			case SPADES: {
				printf("%c of Spades.\n", deck[s][f]);
				break;
			}
			}
		}
	}
};
//function for the blackjack game
int playBlackJack(int cash) {
	printf("Let's play BlackJack!\n\n");
	//local constants for blackjack
	const int BET = 10;
	const int MIN_HIT = 16;
	const int HIT = 1;
	const int STAND = 0;
	//local variables for blackjack
	int play = 1;
	int choice = 0;
	int bust = 0;
	int player = 0;
	int dealer = 0;

	char deck[SUITS][FACES];
	char dealt[SUITS][FACES];
	//prints the rules of the game
	printf("Your cash balance is $%d\n", cash);
	printf("The bet is $10\n");
	printf("Dealer must HIT if their score is 16, or less\n");
	printf("Dealer must STAND if their score is 17 or higher\n");
	printf("If the player wins the hand, they receive $20\n");
	printf("If the dealer wins the hand. the $10 bet is lost\n");
	printf("If it is a PUSH, the player keeps their $10 bet\n\n");


	clearScreen();
	//checks if the player has enough money
	if (cash < 10) {

		printf("Player does not have enough money to play!\n\n");
		return cash;
	}

	initializeUsed(dealt);

	initializeDeck(deck);

	printDeck(deck);

	printf("Shuffling the cards...\n");
	clearScreen();

	printf("Dealing...\n");
	//plays the game while the player has more than $10
	while (play == 1) {
		printf("Player's cash: $%d\n\n", cash);
		if (cash < BET) {
			printf("Player does not have enough money to play!\n\n");
			play = 0;
			continue;
		}
		//deducts bet from players cash

		cash -= BET;
		player = 0;
		dealer = 0;
		bust = 0;
		//reassigns player score
		player += deal(deck, dealt);
		player += deal(deck, dealt);
		printf("Players score: %d\n", player);
		//reassigns dealer score
		dealer += deal(deck, dealt);
		dealer += deal(deck, dealt);

		printf("Please select to either STAND or HIT.\n");
		printf("STAND = %d, HIT = %d\n", STAND, HIT);
		//allows the player to either hit or stand
		scanf_s("%d", &choice);
		// if the player chooses to HIT, game will give them another card.
		while ((choice == HIT) && (player < BUST))
		{
			player += deal(deck, dealt);
			printf("Players score: %d\n", player);

			//establishes if the player has exceeded 21 points
			if (player > BUST) {
				bust = 1;
				printf("Player busted!! Dealer wins the hand!\n\n");
				scanf_s("%d", &play);
				break;
			}
			else {
				printf("Please select to either STAND or HIT.\n");
				printf("STAND = %d, HIT = %d\n", STAND, HIT);
				scanf_s("%d", &choice);
			}
		}
		//checks if the player busts and asks if they would like to play again
		if (bust == 1) {
			printf("Play another hand? (0 = No, 1 = Yes)\n");
			scanf_s("%d", &play);
			clearScreen();
			continue;

		}
		//decides how the dealer will play
		else {

			if (dealer <= MIN_HIT) {
				choice = HIT;
			}
			else {
				choice = STAND;
			}

			while (choice == HIT) {
				dealer += deal(deck, dealt);
				if (dealer > MIN_HIT) {
					choice = STAND;
				}
			}
		}
		printf("Dealer's Score: %d\n", dealer);

		cash += results(player, dealer);

		printf("Play another hand? (0 = No, 1 = Yes)\n");
		scanf_s("%d", &play);
		clearScreen();
	}
	printf("Thank you for playing Blackjack at Knights Casino!\n");
	printf("You cashed out at $%d!", cash);
	return cash;
};




//main function
int main() {

	srand((int)time(NULL));
	// starting cash
	int cash = 1000;
	// game selection
	int game;

	//prints the welcome screen
	welcomeScreen();
	//clears the screen
	clearScreen();

	game = displayMenu();


	clearScreen();

	//this switch processes the game selection
	switch (game) {

	case SLOTS:

		cash = playSlots(cash);
		break;
	case SCRATCH:

		cash = playScratchOffs(cash);
		break;

	case BLACKJACK:
		cash = playBlackJack(cash);
		break;
	}

	return 0;
}
