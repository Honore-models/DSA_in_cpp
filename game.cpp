#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAX_WRONG_GUESSES = 6; // limited number of chances

// ---------- Category data ----------
map<string, vector<string>> buildCategories() {
    map<string, vector<string>> categories;

    categories["Animals"] = {
        "elephant", "giraffe", "kangaroo", "dolphin", "cheetah", "penguin", "gorilla"
    };

    categories["Teams"] = {
        "arsenal", "barcelona", "liverpool", "juventus", "chelsea", "napoli", "inter"
    };

    categories["Districts"] = {
        "kicukiro", "gasabo", "nyarugenge", "musanze", "huye", "rubavu", "kayonza"
    };

    categories["Films"] = {
        "inception", "titanic", "gladiator", "avatar", "interstellar", "joker", "frozen"
    };

    categories["Books"] = {
        "dune", "emma", "beloved", "invisible", "sapiens", "outliers", "hamlet"
    };

    return categories;
}

// ---------- Helper functions ----------

// Prints the word with unguessed letters replaced by underscores
string maskedWord(const string& word, const vector<char>& guessedLetters) {
    string result;
    for (char c : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
            result += c;
        } else {
            result += '_';
        }
    }
    return result;
}

bool alreadyGuessed(const vector<char>& guessedLetters, char letter) {
    return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
}

bool wordFullyGuessed(const string& word, const vector<char>& guessedLetters) {
    for (char c : word) {
        if (!alreadyGuessed(guessedLetters, c)) {
            return false;
        }
    }
    return true;
}

// Lets the user pick a category; returns the chosen category name
string chooseCategory(const map<string, vector<string>>& categories) {
    vector<string> names;
    for (const auto& pair : categories) {
        names.push_back(pair.first);
    }
    sort(names.begin(), names.end());

    while (true) {
        cout << "\nChoose a category:\n";
        for (size_t i = 0; i < names.size(); i++) {
            cout << "  " << (i + 1) << ") " << names[i] << "\n";
        }
        cout << "Enter the number of your choice: ";

        string input;
        if (!getline(cin, input)) {
            exit(0); // no more input available
        }

        try {
            int choice = stoi(input);
            if (choice >= 1 && choice <= (int)names.size()) {
                return names[choice - 1];
            }
        } catch (...) {
            // fall through to error message below
        }
        cout << "Invalid choice, please try again.\n";
    }
}

// Picks a random word from the given category's word list
string pickRandomWord(const vector<string>& words) {
    int index = rand() % words.size();
    return words[index];
}

// Plays a single round of the game. Returns false if the user typed "exit"
// (meaning the whole program should terminate), true otherwise.
bool playRound(const map<string, vector<string>>& categories) {
    string category = chooseCategory(categories);
    string word = pickRandomWord(categories.at(category));

    vector<char> guessedLetters;
    vector<char> wrongLetters;
    int wrongGuesses = 0;

    cout << "\nCategory: " << category << "\n";
    cout << "The word has " << word.size() << " letters. Start guessing!\n";

    while (wrongGuesses < MAX_WRONG_GUESSES) {
        cout << "\nWord: " << maskedWord(word, guessedLetters) << "\n";
        if (!wrongLetters.empty()) {
            cout << "Wrong guesses (" << wrongGuesses << "/" << MAX_WRONG_GUESSES << "): ";
            for (char c : wrongLetters) cout << c << " ";
            cout << "\n";
        }
        cout << "Guess a letter (or type 'exit' to quit): ";

        string input;
        if (!getline(cin, input)) {
            // No more input available (e.g. end of file) - treat as exit
            cout << "\nNo more input. Goodbye.\n";
            return false;
        }

        // Trim whitespace
        while (!input.empty() && isspace((unsigned char)input.back())) input.pop_back();
        while (!input.empty() && isspace((unsigned char)input.front())) input.erase(input.begin());

        // Check for exit command (case-insensitive)
        string lowerInput = input;
        for (char& c : lowerInput) c = tolower((unsigned char)c);
        if (lowerInput == "exit") {
            cout << "\nThanks for playing! Goodbye.\n";
            return false;
        }

        // Validate: must be exactly one alphabetic character
        if (input.size() != 1 || !isalpha((unsigned char)input[0])) {
            cout << "Please enter a single letter (a-z), or 'exit' to quit.\n";
            continue;
        }

        char letter = tolower((unsigned char)input[0]);

        if (alreadyGuessed(guessedLetters, letter) || alreadyGuessed(wrongLetters, letter)) {
            cout << "You already guessed '" << letter << "'. Try a different letter.\n";
            continue;
        }

        if (word.find(letter) != string::npos) {
            guessedLetters.push_back(letter);
            cout << "Good guess! '" << letter << "' is in the word.\n";

            if (wordFullyGuessed(word, guessedLetters)) {
                cout << "\nWord: " << maskedWord(word, guessedLetters) << "\n";
                cout << "Congratulations, you guessed the word: " << word << "! You win!\n";
                return true;
            }
        } else {
            wrongLetters.push_back(letter);
            wrongGuesses++;
            cout << "Sorry, '" << letter << "' is not in the word.\n";
        }
    }

    cout << "\nYou've run out of chances! The word was: " << word << "\n";
    cout << "Better luck next time!\n";
    return true;
}

// Asks the user if they want to play again. Returns true for yes.
bool askPlayAgain() {
    while (true) {
        cout << "\nDo you want to play again? (y/n): ";
        string input;
        if (!getline(cin, input)) {
            return false; // no more input available
        }
        for (char& c : input) c = tolower((unsigned char)c);

        if (input == "y" || input == "yes") return true;
        if (input == "n" || input == "no") return false;

        cout << "Please answer 'y' or 'n'.\n";
    }
}

int main() {
    srand((unsigned int)time(nullptr));

    map<string, vector<string>> categories = buildCategories();

    cout << "=========================================\n";
    cout << "        WELCOME TO WORD GUESS GAME        \n";
    cout << "=========================================\n";

    bool continuePlaying = true;
    while (continuePlaying) {
        bool didNotExit = playRound(categories);
        if (!didNotExit) {
            // user typed "exit" mid-round
            break;
        }
        continuePlaying = askPlayAgain();
    }

    cout << "\nThanks for playing Word Guess Game. See you next time!\n";
    return 0;
}