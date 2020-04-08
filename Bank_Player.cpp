#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include <time.h>
#include "Monopoly_Classes.h"
using namespace std;

// https://www.oreilly.com/library/view/c-cookbook/0596007612/ch08s02.html

// PROPERTIES Class ===========================================================================

Properties::Properties() {
	string name = " ", ownership = " ";
	int base_price = 0, base_rent = 0, house1_rent = 0, house2_rent = 0, house3_rent = 0, house4_rent = 0, hotel_rent = 0;
	int double_rent, num_of_houses = 0, num_of_hotels = 0, mortgage_cost = 0, unmortgage_cost = 0;
	bool mortgage_status = false;
}

Properties::Properties(string property_name, int price, int start_rent, int house1rent, int house2rent, int house3rent, int house4rent, int hotelrent, int mortgageCost, int unmortgageCost) {
	name = property_name;
	base_price = price;
	base_rent = start_rent;
	double_rent = base_rent * 2;
	house1_rent = house1rent;
	house2_rent = house2rent;
	house3_rent = house3rent;
	house4_rent = house4rent;
	hotel_rent = hotelrent;
	num_of_houses = 0;
	num_of_hotels = 0;
	mortgage_cost = mortgageCost;
	unmortgage_cost = unmortgageCost;
	mortgage_status = false;
	ownership = "free";
}

string Properties::get_name() const {
	return name;
}

int Properties::get_price() const {
	return base_price;
}

int Properties::get_rent() const {
	if (num_of_hotels == 1) {
		return hotel_rent;
	}
	else if (num_of_houses == 1) {
		return house1_rent;
	}
	else if (num_of_houses == 2) {
		return house2_rent;
	}
	else if (num_of_houses == 3) {
		return house3_rent;
	}
	else if (num_of_houses == 4) {
		return house4_rent;
	}
	else if (num_of_houses == 0 && num_of_hotels == 0) {
		return base_rent;
	}
}

int Properties::get_double_rent() const {
	return double_rent;
}

int Properties::get_num_of_houses() const {
	return num_of_houses;
}

int Properties::get_num_of_hotels() const {
	return num_of_hotels;
}

int Properties::get_mortgage_cost() const {
	return mortgage_cost;
}

int Properties::get_unmortgage_cost() const {
	return unmortgage_cost;
}

bool Properties::get_mortgage_status() const {
	return mortgage_status;
}

string Properties::get_ownership() const {
	return ownership;
}

void Properties::build_house() {
	if (num_of_houses >= 0 && num_of_houses <= 4) {
		num_of_houses++;	// Max = 4 houses
	}
	if (num_of_houses >= 5) {
		build_hotel();
	}
}

void Properties::sell_house() {
	if (num_of_hotels == 0 && !(num_of_houses == 0)) {
		num_of_houses--;	// Min = 0 houses
	}
	else if (num_of_hotels == 1) {
		sell_hotel();
	}
	if (num_of_houses <= 0) {
		num_of_houses = 0;
	}
}

void Properties::build_hotel() {
	num_of_hotels = 1;	// Max = 1 hotel, 5 houses == 1 hotel
	num_of_houses = 0;
}

void Properties::sell_hotel() {
	num_of_hotels = 0;	// Min = 0 hotels
	num_of_houses = 4;
}

void Properties::mortgage_property() {
	mortgage_status = true;		// property rent => inactive
}

void Properties::unmortgage_property() {
	mortgage_status = false;	// property rent => active
}


// PLAYER Class =======================================================================

Player::Player() {
	string player_name = " ";
	int money = 0;
	vector<string> claimed_deeds;
}

Player::Player(string name) {
	player_name = name;
	money = 1500;
	vector<string> claimed_deeds;
}

string Player::get_player_name() const {
	return player_name;
}

int Player::get_money() const {
	return money;
}

vector<string> Player::get_deeds() const {
	return claimed_deeds;
}

int Player::roll_dice() const {
	srand(time(0));
	int roll1 = (rand() % 6) + 1;
	int roll2 = (rand() % 6) + 1;
	return roll1 + roll2;
}

int Player::get_house_cost(string property) const {
	if (property == "Mediterranean Avenue" || property == "Baltic Avenue" || property == "Oriental Avenue" || property == "Vermont Avenue" || property == "Connecticut Avenue") {
		return 50;
	}
	else if (property == "St. Charles Place" || property == "States Avenue" || property == "Virginia Avenue" || property == "St. James Place" || property == "Tennessee Avenue" || property == "New York Avenue") {
		return 100;
	}
	else if (property == "Kentucky Avenue" || property == "Indiana Avenue" || property == "Illinois Avenue" || property == "Atlantic Avenue" || property == "Ventnor Avenue" || property == "Marvin Gardens") {
		return 150;
	}
	else if (property == "Pacific Avenue" || property == "North Carolina Avenue" || property == "Pennsylvania Avenue" || property == "Park Place" || property == "Boardwalk") {
		return 200;
	}
}

bool Player::has_deed(string property) const {
	for (int i = 0; i < claimed_deeds.size(); ++i) {
		if (claimed_deeds.at(i) == property) {
			return true;
		}
		else {
			return false;
		}
	}
}

void Player::increment_money(int pay) {
	money += pay;
}

void Player::decrement_money(int charge) {
	money -= charge;
}

void Player::claim_deed(string property) {
	claimed_deeds.push_back(property);
}

int Player::railroad_rent(string property) const {
	int num_of_railroads = 0;
	for (int i = 0; i < claimed_deeds.size(); ++i) {
		if (claimed_deeds.at(i) == "Reading Railroad" || claimed_deeds.at(i) == "Pennsylvania Railroad" || claimed_deeds.at(i) == "B & O Railroad" || claimed_deeds.at(i) == "Short Line") {
			num_of_railroads++;
		}
	}
	return num_of_railroads * 25;
}

bool Player::color_group_check(string property) const {
	if (property == "Mediterranean Avenue" || property == "Baltic Ave") {
		if (has_deed(property) == true && (has_deed("Mediterranean Avenue") == true && has_deed("Baltic Ave"))) {
			return true;
		}
		else { return false; }
	}
	else if (property == "Oriental Ave" || property == "Vermont Ave" || property == "Connecticut Ave") {
		if (has_deed(property) == true && (has_deed("Oriental Ave") == true && has_deed("Vermont Ave") == true && has_deed("Connecticut Ave") == true)) {
			return true;
		}
		else { return false; }
	}
	else if (property == "St. Charles Place" || property == "States Ave" || property == "Virginia Ave") {
		if (has_deed(property) == true && (has_deed("St. Charles Place") == true && has_deed("States Ave") == true && has_deed("Virginia Ave") == true)) {
			return true;
		}
		else { return false; }
	}
	else if (property == "St. James Place" || property == "Tennessee Ave" || property == "New York Ave") {
		if (has_deed(property) == true && (has_deed("Oriental Ave") == true && has_deed("Tennessee Ave") == true && has_deed("New York Ave") == true)) {
			return true;
		}
		else { return false; }
	}
	else if (property == "Kentucky Ave" || property == "Indiana Ave" || property == "Illinois Ave") {
		if (has_deed(property) == true && (has_deed("Kentucky Ave") == true && has_deed("Indiana Ave") == true && has_deed("Illinois Ave") == true)) {
			return true;
		}
		else { return false; }
	}
	else if (property == "Atlantic Ave" || property == "Ventnor Ave" || property == "Marvin Gardens") {
		if (has_deed(property) == true && (has_deed("Atlantic Ave") == true && has_deed("Ventnor Ave") == true && has_deed("Marvin Gardens") == true)) {
			return true;
		}
		else { return false; }
	}
	else if (property == "Pacific Ave" || property == "North Carolina Ave" || property == "Pennsylvania Ave") {
		if (has_deed(property) == true && (has_deed("Pacific Ave") == true && has_deed("North Carolina Ave") == true && has_deed("Pennsylvania Ave") == true)) {
			return true;
		}
		else { return false; }
	}
	else if (property == "Park Place" || property == "Boardwalk") {
		if (has_deed(property) == true && (has_deed("Park Place") == true && has_deed("Boardwalk") == true)) {
			return true;
		}
		else { return false; }
	}
	else if (property == "Electric Company" || property == "Water Works") {
		if (has_deed(property) == true && (has_deed("Electric Company") == true && has_deed("Water Works") == true)) {
			return true;
		}
		else { return false; }
	}
}
