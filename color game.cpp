#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

enum color {
    red, green, blue, yellow, purple
};

color generateRandomColor() {
    int randomNum = rand() % 5;
    return static_cast<color>(randomNum);
}

string colorToString(color col) {
    switch (col) {
        case red:
            return "Red";
        case green:
            return "Green";
        case blue:
            return "Blue";
        case yellow:
            return "Yellow";
        case purple:
            return "Purple";
        default:
            return "Unknown";
    }
}

int main() {
    srand(time(0));

    color targetColor = generateRandomColor();
    string guess;
    while (true) {
        system("cls");
        cout << "Welcome to the Colored Square Game!" << endl;
        cout << "************************************" << endl;
        cout << "Guess the Color of the square (Red, Green, Blue, Yellow, or Purple)" << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        for (int i = 0; i < guess.length(); ++i) {
            guess[i] = tolower(guess[i]);
        }

        color userColor;
        bool validColor = true;

        if (guess == "red") {
            userColor = red;
        } else if (guess == "green") {
            userColor = green;
        } else if (guess == "blue") {
            userColor = blue;
        } else if (guess == "yellow") {
            userColor = yellow;
        } else if (guess == "purple") {
            userColor = purple;
        } else {
            validColor = false;
        }

        if (validColor) {
            if (userColor == targetColor) {
                cout << endl;
                cout << "Congratulations! You guessed the correct color." << endl;
                break;
            } else {
                cout << "Wrong guess. Try again!" << endl;
            }
        } else {
            cout << "Invalid color. Please enter a valid color." << endl;
        }

        Sleep(1000);
    } // while
    return 0;
} // main

