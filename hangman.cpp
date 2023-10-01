#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string words[6] = {"programming", "computer", "cheese", "balloon", "criminal", "friend"};
  string hangmanArt[7] = {
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "     |\n"
    "=========="
};

  srand(time(NULL));
  int ranNum = rand();
  int arraySize = (sizeof(words)/sizeof(string));
  int ranWordNum = ranNum % arraySize;

  string word = words[ranWordNum];

  // Make the placeholder for letters guessed
  string guessingWord;
  for (int i = 0; i < word.size(); i++) {
    guessingWord.append("_");
  }

  bool win = false;
  bool lose = false;
  int turn = 0;
  int oldTurn = -1;
  char guessedLetter;
  vector<char> usedLetters;

  cout << "Welcome to hangman!" << endl;
  while (win == false && lose == false) { // Game loop
    if (turn > oldTurn) {
      cout << hangmanArt[turn] << endl;
    }
    cout << endl << "Word: " << guessingWord << " (" << guessingWord.size() << ") letters" << endl;

    if (oldTurn != -1) { // Print used letters
      cout << "(Used letters:";
      for (char letter : usedLetters) {
        cout << " " << letter;
      }
      cout << ")";
    }
    cout << endl << "Enter letter to guess: ";
    cin >> guessedLetter;

    // Checks if guessed letter has already been guessed
    if (find(usedLetters.begin(), usedLetters.end(), guessedLetter) == usedLetters.end()) {
      usedLetters.push_back(guessedLetter);
    } else {
      while (find(usedLetters.begin(), usedLetters.end(), guessedLetter) != usedLetters.end()) {
        cout << "Letter has already been guessed" << endl;

        cout << "(Used letters:";
        for (char letter : usedLetters) {
          cout << " " << letter;
        }
        cout << ")";

        cout << endl << "Enter a different letter to guess: ";
        cin >> guessedLetter;
      }
    }

    int position = word.find(guessedLetter);

    if (position != string::npos) {
      cout << guessedLetter << " is in the word!" << endl;
      while (position < word.size() && position != string::npos) {
        guessingWord[position] = guessedLetter;
        position = word.find(guessedLetter, position + 1);
      }
      oldTurn = turn;
    } else {
      cout << guessedLetter << " isn't in the word." << endl;
      oldTurn = turn;
      turn++;
    }

    if (guessingWord.find("_") == string::npos) {
      win = true;
    } else if (turn == sizeof(hangmanArt)/sizeof(hangmanArt[0])) {
      lose = true;
    }

  }

  cout << endl << "The word was " << word << endl;

  return 0;
}
