#include<bits/stdc++.h>
using namespace std;
class NumberGuessingGame {

public:
    int target;
    int attempts;

    NumberGuessingGame() {
        srand(time(0));
        target = rand() % 100 + 1; // Generate a random number between 1 and 100
        attempts = 0;
    }

    void play() {
        int guess = 0;
        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "I have selected a number between 1 and 100." << endl;
        cout << "Can you guess what it is?" << endl;

        while (guess != target) {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess < target) {
                cout << "Too low! Try again." << endl;
            } else if (guess > target) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            }
        }
    }
};

int main() {
    NumberGuessingGame game;
    game.play();
    return 0;
}
