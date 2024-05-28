#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // For using rand()

using namespace std;

// Define a Node struct for the singly linked list used in TriviaQuestions
struct Node {
    string question;
    string answer;
    int points;
    Node* next;

    // Constructor for Node, initializes with question details and next pointer
    Node(string q, string a, int p, Node* nxt = nullptr)
        : question(q), answer(a), points(p), next(nxt) {}
};

// TriviaQuestions manages a stack of trivia questions using a singly linked list
class TriviaQuestions {
private:
    Node* top;  // Pointer to the top of the stack
    int size;   // Keeps track of the number of elements in the stack

public:
    // Constructor initializes an empty stack
    TriviaQuestions() : top(nullptr), size(0) {}

    // Destructor to clear the stack and free memory
    ~TriviaQuestions() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        cout << "Trivia stack is deleted from memory!" << endl;
    }

    // Check if the stack is empty
    bool isempty() {
        return top == nullptr;
    }

    // Push a new question to the stack
    void push(string question, string answer, int points) {
        Node* newNode = new Node(question, answer, points);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Insert a new node at a random position in the stack to mimic shuffling
    void randomInsert(Node** head, Node* newNode) {
        if (*head == nullptr || rand() % (size + 1) == 0) {
            newNode->next = *head;
            *head = newNode;
        }
        else {
            Node* current = *head;
            int pos = rand() % size;
            for (int i = 0; i < pos - 1 && current->next != nullptr; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    // Pop the top question from the stack
    Node* pop() {
        if (isempty()) {
            cout << "Stack is empty, cannot pop!" << endl;
            return nullptr;
        }
        Node* temp = top;
        top = top->next;
        size--;
        return temp;
    }

    // Load questions from a file, create nodes, and randomly insert them into the stack
    void loadQuestions(string filepath) {
        ifstream file(filepath);
        string line;
        while (getline(file, line)) {
            size_t firstComma = line.find(',');
            size_t secondComma = line.find_last_of(',');
            string question = line.substr(0, firstComma);
            string answer = line.substr(firstComma + 1, secondComma - firstComma - 1);
            trim(answer);
            string pointsStr = line.substr(secondComma + 1);
            trim(pointsStr);
            int points = stoi(pointsStr);
            Node* newNode = new Node(question, answer, points);
            randomInsert(&top, newNode);
        }
        file.close();
    }

    // Utility function to trim whitespace from both ends of a string
    static void trim(string& str) {
        const char* typeOfWhitespaces = " \t\n\r\f\v";
        str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
        str.erase(0, str.find_first_not_of(typeOfWhitespaces));
    }
};

// Define a DNode struct for the doubly linked list used in DiscardedQuestions
struct DNode {
    string question;
    string answer;
    int points;
    DNode* next;
    DNode* prev;

    // Constructor for DNode, initializes with question details and pointers
    DNode(string q, string a, int p, DNode* nxt = nullptr, DNode* prv = nullptr)
        : question(q), answer(a), points(p), next(nxt), prev(prv) {}
};

// DiscardedQuestions manages a list of discarded questions using a doubly linked list
class DiscardedQuestions {
private:
    DNode* head;  // Pointer to the start of the list
    DNode* tail;  // Pointer to the end of the list
    int size;     // Keeps track of the number of elements in the list

public:
    // Constructor initializes an empty list
    DiscardedQuestions() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor to clear the list and free memory
    ~DiscardedQuestions() {
        while (head != nullptr) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add a new question to the end of the list
    void addQuestion(string question, string answer, int points) {
        DNode* newNode = new DNode(question, answer, points);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Remove the last question from the list
    DNode* removeLastQuestion() {
        if (tail == nullptr) {
            cout << "List is empty, nothing to remove!" << endl;
            return nullptr;
        }
        DNode* temp = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            head = tail = nullptr;
        }
        size--;
        return temp;
    }

	// Display all the questions in the discarded deck
	void displayQuestions()
	{
		if (head == nullptr)
		{
			cout << "Discarded Deck is empty!" << endl;
			return;
		}
		DNode* current = head;
		while (current != nullptr)
		{
			cout << "Question: " << current->question << endl;
			cout << "Answer: " << current->answer << endl;
			cout << "Points: " << current->points << endl << endl;
			current = current->next;
		}
	}
};

// Answered Deck
// Answered deck using Single linked list
// Answered deck will be used to store the questions that have been answered correctly

// AnsweredDeck class
class AnsweredDeck
{
private:
    Node* head;  // Pointer to the head of the answered deck
    int size;    // Keeps track of the number of elements in the answered deck

public:
    // Constructor initializes an empty answered deck
    AnsweredDeck() : head(nullptr), size(0) {}

    // Destructor to clear the answered deck and free memory
    ~AnsweredDeck() {}

    // Add correctly answered question to the answered deck
    void addAnsweredQuestion(string question, string answer, int points)
    {
        Node* newNode = new Node(question, answer, points);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Display all the questions in the answered deck
    void displayAnsweredQuestions()
    {

        if (head == nullptr)
        {

            cout << "Answered Deck is empty!" << endl;
            return;
        }
        else
        {
            Node* current = head;
            while (current != nullptr)
            {
                cout << "Question: " << current->question << endl;
                cout << "Answer: " << current->answer << endl;
                cout << "Points: " << current->points << endl << endl;
                current = current->next;
            }
        }

    }
};