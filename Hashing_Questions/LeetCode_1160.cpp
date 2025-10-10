//Find Words that can be formed by characters

//You are given an array of strings words and a string chars.
// A string is good if it can be formed by characters from chars (each character can only be used once for each word in words).
// Return the sum of lengths of all good strings in words.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Brute Force -- TC = O(N * K * M); 
// n = number of words in words array
// k = average length of each word
// m = length of chars string

int countCharacters(vector<string>& words, string chars) {
        int idx = 0;
        int count = 0;

        while (idx < words.size()) {
            string currWord = words[idx];
            bool isPossible = true;

            // Create a copy of chars to track used characters
            string availableChars = chars;

            // Check each character in current word
            for (int i = 0; i < currWord.size(); i++) {
                bool found = false;

                // Search for current character in availableChars
                for (int j = 0; j < availableChars.size(); j++) {
                    if (currWord[i] == availableChars[j]) {
                        found = true;
                        // Remove the used character
                        availableChars[j] = ' '; // Mark as used
                        break;
                    }
                }

                if (!found) {
                    isPossible = false;
                    break;
                }
            }

            if (isPossible) {
                count += currWord.size();
            }

            idx++;
        }
        return count;
}

//Optimized Approach - Using Hashing
int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chCount;
        for (int i = 0; i < chars.size(); i++) {
            if (chCount.find(chars[i]) == chCount.end())
                chCount[chars[i]] = 1;
            else
                chCount[chars[i]]++;
        }

        int idx = 0;
        int count = 0;

        while (idx < words.size()) {
            string currWord = words[idx];
            unordered_map<char, int> copyCount = chCount;
            bool isPossible = true;

            for (int i = 0; i < currWord.size(); i++) {
                char ch = currWord[i];

                if (copyCount.find(ch) != copyCount.end() && copyCount[ch] != 0)
                    copyCount[ch]--;
                else {
                    isPossible = false;
                    break;
                }
            }

            if (isPossible)
                count += currWord.size();

            idx++; 
        }

        return count;
}

int main(){
    string chars = "atach";
    vector<string> words = {"cat","bt","hat","tree"};
    int ans = countCharacters(words, chars);

    cout<<ans<<endl;

    return 0;
}