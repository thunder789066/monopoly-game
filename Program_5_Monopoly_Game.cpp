#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include "Monopoly_Classes.h"
using namespace std;

int player1_position = 0, player2_position = 0;
vector<Properties> title_deeds;
vector<Player> players;
vector<string> board = {"Go"                    /* 0 */,          "Mediterranean Ave"        /* 1 */,
						"Free Parking"          /* 2 */,          "Baltic Ave"               /* 3 */,
						"Income Tax"            /* 4 */,          "Reading Railroad"         /* 5 */,
						"Oriental Ave"          /* 6 */,          "Free Parking"             /* 7 */,
						"Vermont Ave"           /* 8 */,          "Connecticut Ave"          /* 9 */,
						"Just Visiting Bar"     /* 10 */,         "St. Charles Place"        /* 11 */,
						"Electric Company"      /* 12 */,         "States Ave"               /* 13 */,
						"Virginia Ave"          /* 14 */,         "Pennsylvania Railroad"    /* 15 */,
						"St. James Place"       /* 16 */,         "Free Parking"             /* 17 */,
						"Tennessee Ave"         /* 18 */,         "New York Ave"             /* 19 */,
						"Free Parking"          /* 20 */,         "Kentucky Ave"             /* 21 */,
						"Free Parking"          /* 22 */,         "Indiana Ave"              /* 23 */,
						"Illinois Ave"          /* 24 */,         "B & O Railroad"           /* 25 */,
						"Atlantic Ave"          /* 26 */,         "Ventnor Ave"              /* 27 */,
						"Water Works"           /* 28 */,         "Marvin Gardens"           /* 29 */,
						"Go to Bar"             /* 30 */,         "Pacific Ave"              /* 31 */,
						"North Carolina Ave"    /* 32 */,         "Free Parking"             /* 33 */,
						"Pennsylvania Ave"      /* 34 */,         "Short Line"               /* 35 */,
						"Free Parking"          /* 36 */,         "Park Place"               /* 37 */,
						"Luxary Tax"            /* 38 */,         "Boardwalk"                /* 39 */
};

void get_properties() {
	Properties property1("Mediterranean Ave", 60, 2, 10, 30, 90, 160, 250, 30, 33); title_deeds.push_back(property1);
	Properties property2("Baltic Ave", 60, 4, 20, 60, 1800, 320, 450, 30, 33); title_deeds.push_back(property2);
	Properties property3("Oriental Ave", 100, 6, 30, 90, 270, 400, 550, 50, 55); title_deeds.push_back(property3);
	Properties property4("Vermont Ave", 100, 6, 30, 90, 270, 400, 550, 50, 55); title_deeds.push_back(property4);
	Properties property5("Connecticut Ave", 120, 8, 40, 100, 300, 450, 600, 60, 66); title_deeds.push_back(property5);
	Properties property6("St. Charles Place", 140, 10, 50, 150, 450, 625, 750, 70, 77); title_deeds.push_back(property6);
	Properties property7("States Ave", 140, 10, 50, 150, 450, 625, 750, 70, 77); title_deeds.push_back(property7);
	Properties property8("Virginia Ave", 160, 12, 60, 180, 500, 700, 900, 80, 88); title_deeds.push_back(property8);
	Properties property9("St. James Place", 180, 14, 70, 200, 550, 750, 950, 90, 99); title_deeds.push_back(property9);
	Properties property10("Tennessee Ave", 180, 14, 70, 200, 550, 750, 950, 90, 99); title_deeds.push_back(property10);
	Properties property11("New York Ave", 200, 16, 80, 220, 600, 800, 1000, 100, 110); title_deeds.push_back(property11);
	Properties property12("Kentucky Ave", 220, 18, 90, 250, 700, 875, 1050, 110, 121); title_deeds.push_back(property12);
	Properties property13("Indiana Ave", 220, 18, 90, 250, 700, 875, 1050, 110, 121); title_deeds.push_back(property13);
	Properties property14("Illinois Ave", 240, 20, 100, 300, 750, 925, 1100, 120, 132); title_deeds.push_back(property14);
	Properties property15("Atlantic Ave", 260, 22, 110, 330, 800, 975, 1150, 130, 143); title_deeds.push_back(property15);
	Properties property16("Ventnor Ave", 260, 22, 110, 330, 800, 975, 1150, 130, 143); title_deeds.push_back(property16);
	Properties property17("Marvin Gardens", 280, 24, 120, 360, 850, 1025, 1200, 140, 154); title_deeds.push_back(property17);
	Properties property18("Pacific Ave", 300, 26, 130, 390, 900, 1100, 1275, 150, 165); title_deeds.push_back(property18);
	Properties property19("North Carolina Ave", 300, 26, 130, 390, 900, 1100, 1275, 150, 165); title_deeds.push_back(property19);
	Properties property20("Pennsylvania Ave", 320, 28, 150, 450, 1000, 1200, 1400, 160, 176); title_deeds.push_back(property20);
	Properties property21("Park Place", 350, 35, 175, 500, 1100, 1300, 1500, 175, 193); title_deeds.push_back(property21);
	Properties property22("Boardwalk", 400, 50, 200, 600, 1400, 1700, 2000, 200, 220); title_deeds.push_back(property22);
	Properties property23("Reading Railroad", 200, 25, 0, 0, 0, 0, 0, 100, 110); title_deeds.push_back(property23);
	Properties property24("Pennsylvania Railroad", 200, 25, 0, 0, 0, 0, 0, 100, 110); title_deeds.push_back(property24);
	Properties property25("B & O Railroad", 200, 25, 0, 0, 0, 0, 0, 100, 110); title_deeds.push_back(property25);
	Properties property26("Short Line", 200, 25, 0, 0, 0, 0, 0, 100, 110); title_deeds.push_back(property26);
	Properties property27("Electric Company", 150, 4, 0, 0, 0, 0, 0, 75, 83); title_deeds.push_back(property27);
	Properties property28("Water Works", 150, 4, 0, 0, 0, 0, 0, 75, 83); title_deeds.push_back(property28);
}

void get_player_info() {
	string name;
	for (int i = 0; i < 2; ++i) {
		cout << "Player " << i + 1 << ": What is your name? ";
		cin >> name;
		Player player(name); players.push_back(player);
	}
}

int main() { // ========================== MAIN ======================================================
    cout << "Welcome to 1935 Monopoly!\n" << endl;

	get_properties();
	get_player_info();

	//gameplay();

	cout << " THIS IS FOR TESTING" << endl;
	for (int i = 0; i < title_deeds.size(); ++i) {
		cout << title_deeds.at(i).get_name() << setw(20) << "Price: $" << title_deeds.at(i).get_price() << setw(25) << "Current Rent: $" << title_deeds.at(i).get_rent() << endl;
	}

	return 0;
}

int menu() {
	int choice;
	bool check = true;

	while (check) {
		try {
			cout << " (1) Roll Dice" << endl;	// if num_of_rolls == 1, player CANNOT roll again
			cout << " (2) Build House/Hotel" << endl;
			cout << " (3) Mortgage Property" << endl;
			cout << " (4) Check Properties" << endl;
			cout << " (5) End Turn" << endl;
			cout << "What would you like to do? ";
			cin >> choice;

			if (cin.fail()) {
				cin.clear(); // user input cleared
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nThat option is not available.\n" << endl;
				continue;
			}

			if (choice <= 0 || choice >= 6) {
				cin.clear(); // user input cleared
				throw runtime_error("\nYou must choose option 1, 2, 3, 4, or 5.\n");
			}
			else if (choice == 5) {
				return choice;
			}
			else {
				return choice;
			}
		}
		catch (runtime_error & excpt) {
			cout << excpt.what() << endl;
		}
	}
}

void gameplay() {
	bool game_end = false;
	do {
		player1_turn();
		player2_turn();
	} while (game_end);
}

void player1_turn() {
	bool onTurn = true;
	int num_of_rolls = 0, roll;

	cout << endl << "Player Turn: " << players.at(0).get_name() << endl;
	cout << "Current Balance: $" << players.at(0).get_money() << endl;

		while (onTurn) {
			int choice = menu();
			if (choice == 5) {
				onTurn = false;
			}
			else if (choice == 1) {	// roll dice
				if (num_of_rolls == 1) {
					cout << "You already rolled. Choose another option." << endl;
				}
				else if (num_of_rolls == 0) {
					roll = players.at(0).roll_dice();
					player1_position += roll;
					player1_position = set_position(player1_position);
					num_of_rolls = 1;
				}
			}
			else if (choice == 2) {	// builds house 1 at a time, fist check if player has ALL of 1 color group
				string property;
				display_deeds(0);

				cout << "Which property do you want to build a house on? *Say EXACT Name" << endl;
				cout << "Property:  ";
				cin >> property;

				if (players.at(0).color_group_check(property) == true) {
					for (int i = 0; i < title_deeds.size(); ++i) {
						// NOT DONE
					}
				}
			}
			else if (choice == 3) {	// mortgage property
				string property;
				if (players.at(0).has_deed(property)) {
					// NOT DONE
				}
			}
			else if (choice == 4) {	// outputs players current properties
				display_deeds(0);	// player 1
			}
		}
}
void player2_turn() {
	// same exact code as player1_turn()
	bool onTurn = true;
	int num_of_rolls = 0;

	cout << endl << "Player Turn: " << players.at(1).get_name() << endl;

	while (onTurn) {
		int choice = menu();
		if (choice == 5) {
			onTurn = false;
		}
		else if (choice == 1) {	// roll dice, set num_of_rolls = 1 afterwards

		}
		else if (choice == 2) {	// builds house 1 at a time, fist check if player has ALL of 1 color group

		}
		else if (choice == 3) {	// mortgage property

		}
		else if (choice == 4) {	// outputs players current properties

		}
	}
}

int set_position(int position) {
	if (position > 39) {
		return (position - 39) - 1;
	}
	else {
		return position;
	}
}

void display_deeds(int player) {
	for (int i = 0; i < players.at(player).get_deeds().size(); ++i) {
		cout << " - " << players.at(player).get_deeds().at(i) << endl;
	}
}

void check_position(int player, int player_position) {
	// set players' position += roll
	// iterate over board vector, match players' postion to property on board & do following:
	// -> check mortgage status of property & ownership
	//	  - if ownership == free, display price
	//      - if player BUYS property, decrement players' money, append property name to players' claimed_deeds vector
	//      - else if player AUCTIONS property, call auction();
	//	  - else if ownership != free && mortgage status == false, display owner & rent, decrement players' money & increment the OTHER player's money
	//		- make a check if the OTHER player has ALL of 1 color group, make color_group_check() method
	//	  - else if ownership != free && mortgage == true, output -> "'property_name' is mortgaged, you owe nothing"
	// -> if players' money <= 0 // 0 or less
	//    - call a force_mortgage() method
}

void auction(string property) {
	int player1_bid = 1, player2_bid = 1;
	bool bidding = true;
	while (bidding) {
		char choice = ' ';
		cout << "\nPlayer " << players.at(0).get_name() << ", would you like to bid? Y or N  ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			try {
				cout << "\nPlayer " << players.at(0).get_name() << ", what is your bid? ";
				cin >> player1_bid;

				if (cin.fail()) {
					cin.clear(); // user input cleared
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw runtime_error("\nThat option is not available.\n");
					continue;
				}
			}
			catch (runtime_error & excpt) {
				cout << excpt.what() << endl;
			}
		}
		else {
			player1_bid = 0;
			bidding = false;
		}

		choice = ' ';
		cout << "\nPlayer " << players.at(1).get_name() << ", would you like to bid? Y or N  ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			try {
				cout << "\nPlayer " << players.at(1).get_name() << ", what is your bid? ";
				cin >> player2_bid;

				if (cin.fail()) {
					cin.clear(); // user input cleared
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw runtime_error("\nThat option is not available.\n");
					continue;
				}
			}
			catch (runtime_error & excpt) {
				cout << excpt.what() << endl;
			}
		}
		else {
			player2_bid = 0;
			bidding = false;
		}

		cout << "Current Bids: " << endl;
		cout << "Player " << players.at(0).get_name() << ": $" << player1_bid << endl;
		cout << "Player " << players.at(1).get_name() << ": $" << player2_bid << endl;
	}
	if (player1_bid > player2_bid) {	// player 1 claimed deed
		players.at(0).decrement_money(player1_bid);
		players.at(0).claim_deed(property);
	}
	else if (player2_bid > player1_bid) {	// player 2 claimed deed
		players.at(1).decrement_money(player2_bid);
		players.at(1).claim_deed(property);
	}
}

