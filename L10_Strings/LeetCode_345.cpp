//Reverse Vowels of a String

//Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isVowel(char c) {
        // Fast vowel check without using set
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

string reverseVowels(string s) {
        int st = 0, end = s.size() - 1;

        while (st < end) {
            // Find next vowel from left
            while (st < end && !isVowel(s[st])) {
                st++;
            }

            // Find next vowel from right
            while (st < end && !isVowel(s[end])) {
                end--;
            }

            // Swap if both are vowels
            if (st < end) {
                swap(s[st], s[end]);
                st++;
                end--;
            }
        }

        return s;
}

int main(){
    string s = "IceCreAm";

    string ans = reverseVowels(s);

    cout<<ans<<endl;
    return 0;
}