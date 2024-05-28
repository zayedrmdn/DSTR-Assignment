// Handles the main menu for the trivia game
/*
* TriviaMenu.hpp
* The main menu will display the following options:
* 1. Start the game
* 2. Exit the game
* 
* If the user selects option 1, the game will start and asks for the number of players and their names one by one
* If the user selects option 2, the game will exit.
* The main menu will loop until the user selects option 2 to exit the game.
* 
* After the number and names of players are inputted, 
* The game will ask the players to choose between 3 decks (Unanswered Deck, Discarded Deck, Answered Deck)
* If players choose the Unanswered Deck,
* the game will load the questions from the 'Questions.txt' file to an 'Unanswered Deck' Single Linked List.
* The game will then shuffle the questions and display them one by one to the players (three time only).
* Each time a question is displayed, the players have the option to answer the question or discard it.
* 
* If players choose the Discarded Deck,
* Initially, the Discarded Deck will be empty.
* If a player discards a question, it will be moved to the Discarded Deck.
* The game will display the questions in the Discarded Deck to the players.
* The structure of the Discarded Deck will be a Doubly Linked List.
* 
* If players choose the Answered Deck,
* Initially, the Answered Deck will be empty.
* If a player answers a question correctly, it will be moved to the Answered Deck.
* The game will display the questions in the Answered Deck to the players but will not allow them to answer them.
* The structure of the Answered Deck will be a Circular Linked List.
* 
* 

*/

#pragma once
#include <iostream>
#include <string>
#include "TriviaPlayer.hpp"
#include "TriviaQuestions.hpp"
#include <ctime> // Include for time()
#include <cstdlib>  // For using rand()

using namespace std;

class TriviaMenu
{
private:
	TriviaPlayer tp; // TriviaPlayer object to manage players
	TriviaQuestions tq; // TriviaQuestions object to manage questions
	DiscardedQuestions dq; // DiscardedQuestions object to manage discarded questions
	AnsweredDeck ad; // AnsweredDeck object to manage answered questions

public:

	// Constructor
	TriviaMenu() {}

	// Destructor
	~TriviaMenu() {}

	// Display the main menu and handle user input
	void displayMenu()
	{
		int choice = 0;
		while (choice != 2)
		{
			cout << "Trivia Game Main Menu" << endl;
			cout << "1. Start the game" << endl;
			cout << "2. Exit the game" << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				startGame();
				break;
			case 2:
				cout << "Exiting the game..." << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
			}
		}
	}

	// Start the trivia game by getting the number of players and their names
	void startGame()
	{
		int numPlayers;
		cout << "Enter the number of players: ";
		cin >> numPlayers;

		for (int i = 0; i < numPlayers; i++)
		{
			string name;
			cout << "Enter player " << i + 1 << "'s name: ";
			cin >> name;
			tp.addPlayer(name);
		}

		cout << "Game started with " << numPlayers << " players!" << endl;
		
		tp.displayPlayers(); // Temporary, remove later

		// Display the options for the players to choose the deck
		chooseDeck();
	}

	// Display the options for the players to choose the deck
	void chooseDeck()
	{
		int choice = 0;
		while (choice != 4)
		{
			cout << "***********************" << endl;
			cout << "Choose a deck:" << endl;
			cout << "1. Unanswered Deck" << endl;
			cout << "2. Discarded Deck" << endl;
			cout << "3. Answered Deck" << endl;
			cout << "4. Exit" << endl;
			cout << "***********************" << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				unansweredDeck();
				break;
			case 2:
				//discardedDeck();
				break;
			case 3:
				//answeredDeck();
				break;
			}
		}
	}

	// Unanswered Deck
	void unansweredDeck()
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		tq.loadQuestions("C:\\Users\\Zayed\\Downloads\\Questions.txt");

		cout << "Shuffled Trivia Questions:" << endl;
		while (!tq.isempty()) {
			Node* question = tq.pop(); 
			
			cout << "Question: " << question->question << endl;

			string answer;
			cout << "Enter your answer: (A/B/C/D) or skip (S)" << endl;
			cin >> answer;

			// Check if the answer is correct, incorrect, or skipped
			if (answer == question->answer)
			{
				cout << "Correct answer!" << endl;
				// Move the question to the Answered Deck
				ad.addAnsweredQuestion(question->question, question->answer, question->points);
			}
			else if (answer == "S")
			{
				cout << "Question skipped!" << endl;
				// Move the question to the Discarded Deck
				dq.addQuestion(question->question, question->answer, question->points);
			}
			else
			{
				cout << "Incorrect answer!" << endl;
				// Move the question to the Discarded Deck
				dq.addQuestion(question->question, question->answer, question->points);
			}
			
			delete question;
		}
	}

	// Discarded Deck
	void discardedDeck()
	{
		dq.displayQuestions();
	}


	// Answered Deck
	void answeredDeck()
	{
		ad.displayAnsweredQuestions();
	}


};
