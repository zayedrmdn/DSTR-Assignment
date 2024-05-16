#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // For rand()

using namespace std;

struct Node {
    string question;
    string answer;
    int points;
    Node* next;

    Node(string q, string a, int p, Node* nxt = nullptr)
        : question(q), answer(a), points(p), next(nxt) {}
};

class TriviaStack {
private:
    Node* top;
    int size;

public:
    // Constructor
    TriviaStack() : top(nullptr), size(0) {}

    // Destructor
    ~TriviaStack() {
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

    // Push a node to the top of the stack (traditional push)
    void push(string question, string answer, int points) {
        Node* newNode = new Node(question, answer, points);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Randomly insert a new node into the linked list to mimic shuffling
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

    Node* pop() {
        if (isempty()) {
            cout << "Stack is empty, cannot pop!" << endl;
            return nullptr; // Return nullptr if the stack is empty
        }
        Node* temp = top;
        top = top->next;
        size--;
        return temp; // Return the node that was popped
    }

    // Load questions from a file and shuffle them
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

