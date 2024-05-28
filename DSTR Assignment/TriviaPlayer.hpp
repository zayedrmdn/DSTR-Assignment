// Handles all players related

/*
* TriviaPlayer.hpp
* Players will be constructed using a single linked list
* Each player will have a name, score, and a pointer to the next player
* User will input the number of players that are playing
* User will input the names of the players for the amount of players inputted one by one
* Each Score will be initialized to 0
* Each time a player answers a question correctly, their score will increase by the amount of points the question is worth
* Players will be displayed in order of their score from highest to lowest

*/
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>  // For rand()

using namespace std;

// Define a Player struct for the singly linked list used in TriviaPlayer
struct Player {
	string name;
	int score;
	Player* next;

	// Constructor for Player, initializes with name, score, and next pointer
	Player(string n, int s = 0, Player* nxt = nullptr)
		: name(n), score(s), next(nxt) {}
};

// TriviaPlayer manages a list of players using a singly linked list
class TriviaPlayer 
{
private:
	Player* head;  // Pointer to the head of the player list
	int numPlayers; // Number of players in the list

public:

	// Constructor initializes an empty player list
	TriviaPlayer() : head(nullptr), numPlayers(0) {}

	// Destructor to clear the player list and free memory
	~TriviaPlayer() {
		while (head != nullptr) 
		{
			Player* temp = head;
			head = head->next;
			delete temp;
		}
		cout << "Player list is deleted from memory!" << endl;
	}

	// Check if the player list is empty
	bool isempty() 
	{
		return head == nullptr;
	}

	// Add a new player to the list
	void addPlayer(string name) 
	{
		Player* newPlayer = new Player(name);
		newPlayer->next = head;
		head = newPlayer;
		numPlayers++;
	}

	// get the number of players
	int getNumPlayers() 
	{
		return numPlayers;
	}


	// Display all the players without sorting
	void displayPlayers()
	{
		Player* current = head;
		cout << "Players:" << endl;
		while (current != nullptr)
		{
			cout << "Name: " << current->name << " Score: " << current->score << endl;
			current = current->next;
		}
	}


};