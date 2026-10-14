
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word, int left, int right) {

    // Base case: we have reached the middle
    if (left >= right) {
        return true;
    }

    // If the characters are different
    if (word[left] != word[right]) {
        return false;
    }

    // Compare the next inner pair
    isPalindrome(word, left + 1, right - 1);
}

int main() {
    string word;

    cout << "Enter a word: ";
    cin >> word;

    bool result = isPalindrome(word, 0, word.length() - 1);

    if (result) {
        cout << word << " is a palindrome." << endl;
    } else {
        cout << word << " is not a palindrome." << endl;
    }

    return 0;
}
