#include "TriviaHeader.hpp"
#include <ctime> // Include for time()

int main() {
    // Create an instance of TriviaStack
    TriviaStack ts;

    // Optionally seed the random number generator to get different shuffling results
    srand(static_cast<unsigned int>(time(nullptr)));

    // Load questions from the file, which will now randomly insert (shuffle) them
    ts.loadQuestions("C:\\Users\\twfqt\\Downloads\\Questions.txt");

    // Displaying questions to check if they're loaded and shuffled correctly
    cout << "Shuffled Trivia Questions:" << endl;
    while (!ts.isempty()) {
        Node* question = ts.pop(); // pop() also removes the question from the stack
        cout << "Question: " << question->question << endl;
        cout << "Answer: " << question->answer << endl;
        cout << "Points: " << question->points << endl << endl;
        delete question; // Free memory after displaying
    }

    return 0;
}