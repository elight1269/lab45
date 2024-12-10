#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_TRIES = 6; 
static string WORDS[] = { "this", "is", "a", "word" };

int getRandomWordIndex() {
    srand(time(0));
    return rand() % sizeof(WORDS) / sizeof(WORDS[0]);
}

int main() {
    int wordIndex = getRandomWordIndex();
    string hiddenWord = WORDS[wordIndex];
    string guessedWord(hiddenWord.length(), '*');

    int tries = 0;
    bool guessed = false;

    while (!guessed && tries < MAX_TRIES) {
        cout << "Enter a letter: ";
        char letter;
        cin >> letter;

        cout << "Enter the position of the letter (starting from 0): ";
        int position;
        cin >> position;

        if (position >= 0 && position < hiddenWord.length() && hiddenWord[position] == letter) {
            guessedWord[position] = letter;
            cout << "Correct!\n";
        }
        else {
            cout << "Incorrect!\n";
            tries++;
        }

        cout << "Word: " << guessedWord << endl;

        guessed = true;
        for (char c : guessedWord) {
            if (c == '*') {
                guessed = false;
                break;
            }
        }
    }

    if (guessed) {
        cout << "You win!\n";
    }
    else {
        cout << "You lose!\n";
        cout << "The word was: " << hiddenWord << endl;
    }

    return 0;
}