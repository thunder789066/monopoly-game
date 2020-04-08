#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void get_properties();
void get_player_info();

int menu();
void gameplay();
void player1_turn();
void player2_turn();
void check_position(int player, int player_position);
void auction(string property);
int set_position(int position);
void display_deeds(int player);

class Properties {
public:
	Properties();
	Properties(string name, int base_price, int base_rent, int house1_rent, int house2_rent, int house3_rent, int house4_rent, int hotel_rent, int mortgage_cost, int unmortgage_cost);
	string get_name() const;
	int get_price() const;
	int get_rent() const;
	int get_double_rent() const;
	int get_num_of_houses() const;
	int get_num_of_hotels() const;
	int get_mortgage_cost() const;
	int get_unmortgage_cost() const;
	bool get_mortgage_status() const;
	string get_ownership() const;
	void build_house();
	void sell_house();
	void build_hotel();
	void sell_hotel();
	void mortgage_property();
	void unmortgage_property();
private:
	string name;
	int base_price;
	int base_rent;
	int double_rent;
	int house1_rent;
	int house2_rent;
	int house3_rent;
	int house4_rent;
	int hotel_rent;
	int num_of_houses;
	int num_of_hotels;
	int mortgage_cost;
	int unmortgage_cost;
	bool mortgage_status;
	string ownership;
};

class Player : public Properties {
public:
	Player();
	Player(string name);
	string get_player_name() const;
	int get_money() const;
	vector<string> get_deeds() const;
	int roll_dice() const;
	int get_house_cost(string property) const;
	bool has_deed(string property) const;
	void increment_money(int pay);
	void decrement_money(int charge);
	void claim_deed(string property);
	int railroad_rent(string property) const;
	bool color_group_check(string property) const;
private:
	string player_name;
	int money;
	vector<string> claimed_deeds;
};
