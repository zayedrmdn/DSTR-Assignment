#include "TriviaQuestions.hpp"
#include <ctime> // Include for time()
#include "TriviaMenu.hpp"
#include "TriviaPlayer.hpp"
using namespace std;


int main() {
    
    /*// Create an instance of TriviaStack
    TriviaQuestions tq;

    // Optionally seed the random number generator to get different shuffling results
    srand(static_cast<unsigned int>(time(nullptr)));

    // Load questions from the file, which will now randomly insert (shuffle) them
    tq.loadQuestions("C:\\Users\\Zayed\\Downloads\\Questions.txt"); // This works
	// tq.loadQuestions("C:\\Users\\Zayed\\Documents\\CodeProjects\\Cpp\\DSTR - Ass\\DSTR - Assignment\\DSTR Assignment\\Questions.txt"); // This doesnt work
    
    // Displaying questions to check if they're loaded and shuffled correctly
    cout << "Shuffled Trivia Questions:" << endl;
    while (!tq.isempty()) {
        Node* question = tq.pop(); // pop() also removes the question from the stack
        cout << "Question: " << question->question << endl;
        cout << "Answer: " << question->answer << endl;
        cout << "Points: " << question->points << endl << endl;
        delete question; // Free memory after displaying
    }

    return 0;*/

	TriviaMenu tm;
	tm.displayMenu();

	
    

}