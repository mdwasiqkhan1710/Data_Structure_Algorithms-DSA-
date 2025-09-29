// Reverse Prefix of Word

//Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.
// For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
// Return the resulting string.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reversePrefix(string word, char ch) {
        int idx = -1;
        for(int i=0; i<word.size(); i++){
            if(word[i] == ch){
                idx = i;
                break;
            }
        }

        if(idx == -1) return word;

        int st = 0, end = idx;

        while(st<=end){
            swap(word[st], word[end]);
            st++;
            end--;
        }

        return word;
}

int main(){
    string word = "abcdefd";
    char ch = 'd';

    string ans = reversePrefix(word, ch);

    cout<<"Answer after reversing is: "<<ans<<endl;

    return 0;
}