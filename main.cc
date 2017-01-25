#include "allincludes.h"
#include <iostream>
#include <cstdlib>

using namespace std;

string playrace;
int floorCount = 1;
int tempHP;
int tempGold;
Floor *thisgame;
Character *player;
bool stillplaying = true;
bool hitStairs = false;


// characterRace() will prompt the player to choose a race. It will print a short blurb introducing the
// player to the possible player races (and the corresponding input to select them). 
void characterRace() {
    string raceType;
    cout << "To begin your journey, you must first choose the race you wish to champion." << endl 
	 << "Do you wish to be a Human (h), balanced in strength and stoutness?" << endl
	 << "Or do you wish to be an Elf (e), light and agile, untouched by poisons and vile draughts?" << endl
	 << "Do you thirst for wealth and treasures beyond imagining, like the Dwarves (d) of Old?" << endl 
	 << "Or do you fight for glory, a chief of chiefs, strongest of the Orcs (o)?" << endl
	 << "Choose wisely." << endl;
    cin >> raceType;
    if (cin.eof()) { playrace = "q"; }
    if (raceType == "h") { playrace = "Human"; }
    else if (raceType == "e") { playrace = "Elf"; }
    else if (raceType == "d") { playrace = "Dwarf"; }
    else if (raceType == "o") { playrace = "Orc"; }
    else if (raceType == "q") { playrace = "q"; }
    if (playrace != "q") {
        cout << "You've chosen " << playrace << ". Delve deep and tread lightly, brave adventurer..." << endl; 
    }
}
    

// printStuff() will display the board, and information pertaining to the player (ie race, current gold,
// current floor, etc.) as well as information about the latest committed actions (ie combat, use of a 
// potion, walking close to points of interest, etc).
void printStuff() {
    thisgame->printFloor();
    thisgame->printInfo();
}

/*
// checkValid(checked) will use a string (that is a command) to check if the input is a valid direction.
// True will be returned if string checked is a valid direction, and false otherwise.
bool checkValid(string checked) {
    if ((checked == "no") || (checked == "so") || (checked == "we") || (checked == "ea") ||
        (checked == "nw") || (checked == "ne") || (checked == "sw") || (checked == "se")) {
	    return true;
    } else return false;
}	

*/

// This function handles the logic of playing through a floor (read level) in the game. There are five 
// floors in the dungeon. 
void playGame(int argc, char *argv[]) {
    string direction;
    string action;
    string playstatus;

    while (floorCount <= 5) {		//iteration for logic on each floor begins

	thisgame = Floor::getInstance();
	if (argc == 2) {
	    thisgame->createBoard(25, 79, floorCount, playrace, argv[1]);
	} else {
	    thisgame->createBoard(25, 79, floorCount, playrace);
	}

	player = thisgame->getPlayer();
	
	if (floorCount > 1) {
	    player->setmyHP(tempHP);
	    player->setmyGold(tempGold);
	}
	
	printStuff();
	
	while (!hitStairs) {		// Iteration for rounds begins
	    if (player->getHP() != 0) {
		cout << "If you want to walk, choose a valid direction; don't just stand around!" << endl;
		cout << "If you wish to attack or use a potion, precede the direction with a or u." << endl;

		cin >> action;
		if (cin.eof()) action = "q";
		if ((action == "r") || (action == "q")) break;
		if ((action == "a") || (action == "u")) {
		    cin >> direction;
		    hitStairs = thisgame->playerTurn(direction, action);
		} else {
		    hitStairs = thisgame->playerTurn(action);
		}
		
		if (hitStairs) break;		// In case we hit the stairs
		printStuff();
		if (player->getHP() == 0) break;
		
		thisgame->enemyAction();	// Otherwise enemy stuff
		printStuff();
		
		player = thisgame->getPlayer();	    // update our player pointer in case of wrapping
	    }
	    
	    // Deal with the case that a player has died during the previous turn
	    // Ie an enemy killed player during enemy phase.
	    else {
		cout << "You've been slain! Game over! Maybe next time you'll be smarter!" << endl;
		cout << "Would you like to try again? (y/n)" << endl;
		cin >> playstatus;
		if (playstatus == "y") {
		    cout << "Restarting game. You sure are brave! Or maybe you just don't know when to give up..." 
			 << endl;
		    action = "r";
		} else {
		    cout << "Quitting the game. I knew you wouldn't stand a chance as soon as I laid eyes on you!"
			 << endl;
		    action = "q";
		}
		break;
	    }
	}
	
	hitStairs = false;

	if ((action == "r") || (action == "q")) break;
	
	else {
	    tempHP = player->getHP();
	    tempGold = player->getGold();
	    floorCount += 1;
	}
    }

    // Deal with restarting a game!
    if (action == "r") {
	stillplaying = true;
	floorCount = 1;
	thisgame->calmMerchants();
	thisgame->clearPotions();
    }

    // End the game!
    else if (action == "q") {
	stillplaying = false;
    }

    // Deal with if a Player wins the game!
    else {
	cout << "You've won! You actually made it! Don't you feel good?" << endl;
	int score = player->getGold();
	if (playrace == "Human") {
	    score += score/2;
	}
	cout << "Your score is " << score << ". Savour your victory, brave adventurer!" << endl;
	cout << "Would you like to play again? (y/n)" << endl;
	cin >> playstatus;
	if (playstatus == "y") {
	    cout << "Restarting the game!" << endl;
	    stillplaying = true;
	    floorCount = 1;
	    thisgame->calmMerchants();
	    thisgame->clearPotions();
	} 
	else {
	    cout << "Quitting the game! Hope you had a good time!" << endl;
	    stillplaying = false;
	}
    }
}
	 


int main(int argc, char *argv[]) {
    cout << "  CCCCC  HH  HH     AA     MMM MMM BBBBB  EEEEEE RRRRR  " << endl;
    cout << " CCC CCC HH  HH    AA A    MMM MMM BB  BB EE     RR  RR " << endl;
    cout << "CCC      HHHHHH   AAAAAA   MM M MM BBBBB  EEEE   RRRRR  " << endl;
    cout << " CCC CCC HH  HH  AA     A  MM   MM BB  BB EE     RR  RR " << endl;
    cout << "  CCCCC  HH  HH AA       A MM   MM BBBBB  EEEEEE RR  RR " << endl;
    cout << "         CCCCC  RRRRR      AA     WW   WW LL     EEEEEE RRRRR  " << endl;
    cout << "        CCC CCC RR  RR    AA A    WW   WW LL     EE     RR  RR " << endl;
    cout << "       CCC      RRRRR    AAAAAA   WW W WW LL     EEEE   RRRRR  " << endl;
    cout << "        CCC CCC RR  RR  AA     A  WWW WWW LLLLLL EE     RR  RR " << endl;
    cout << "         CCCCC  RR  RR AA       A WWW WWW LLLLLL EEEEEE RR  RR " << endl;
    cout << "                   33333     00000     00000     00000     "    << endl;
    cout << "                  333 333   000 000   000 000   000 000    "    << endl;
    cout << "                     33333 000   000 000   000 000   000   "    << endl;
    cout << "                  333 333   000 000   000 000   000 000    "    << endl;
    cout << "                   33333     00000     00000     00000     "    << endl;

    srand(time(0));
    while (stillplaying) {
        characterRace();
	if (playrace == "q") break;
	playGame(argc, argv);
    }
}
