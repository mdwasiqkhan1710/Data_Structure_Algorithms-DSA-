// Count the Number of Special Characters II

// You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
// Return the number of special letters in word.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

// Brute force approach
int numberOfSpecialChars(string word)
{
    int n = word.size();
    int count = 0;
    unordered_set<char> processed;

    for (int i = 0; i < n; i++)
    {
        char current = word[i];

        // Only process lowercase letters we haven't processed yet
        if (current >= 'a' && current <= 'z' && processed.find(current) == processed.end())
        {
            char upperCase = current - 32; // Convert to uppercase
            int firstUpper = -1;
            int lastLower = -1;

            // Find first uppercase occurrence
            for (int j = 0; j < n; j++)
            {
                if (word[j] == upperCase)
                {
                    firstUpper = j;
                    break;
                }
            }

            // Find last lowercase occurrence
            for (int j = n - 1; j >= 0; j--)
            {
                if (word[j] == current)
                {
                    lastLower = j;
                    break;
                }
            }

            // Check if uppercase exists AND all lowercase come before first uppercase
            if (firstUpper != -1 && lastLower < firstUpper)
            {
                count++;
            }

            processed.insert(current);
        }
    }
    return count;
}

// Optimized Approach
int numberOfSpecialChars2(string word)
{
    unordered_map<char, int> lower;
    unordered_map<char, int> upper;

    int n = word.size();
    int count = 0;

    // Checking for Upper Case Letters
    for (int i = 0; i < n; i++)
    {
        char curr = word[i];
        if (curr >= 'A' && curr <= 'Z' && upper.find(curr) == upper.end())
        {
            upper[curr] = i;
        }
    }

    // Checking for Lower case letters
    for (int i = n - 1; i >= 0; i--)
    {
        char curr = word[i];
        if (curr >= 'a' && curr <= 'z' && lower.find(curr) == lower.end())
        {
            lower[curr] = i;
        }
    }

    // Checking and updating the count of special characters
    for (auto &pair : lower)
    {
        char lowerChar = pair.first;      // The lowercase character
        char upperChar = lowerChar - 32;  // Convert to uppercase
        int lastLowerIndex = pair.second; // Last occurrence of lowercase

        // Check if uppercase exists and last lowercase comes before first uppercase
        if (upper.find(upperChar) != upper.end() && lastLowerIndex < upper[upperChar])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string word = "aaAbcBC";

    cout << "Number of special characters are : " << numberOfSpecialChars(word) << endl;

    cout << "Number of special characters are : " << numberOfSpecialChars2(word) << endl;

    return 0;
}
