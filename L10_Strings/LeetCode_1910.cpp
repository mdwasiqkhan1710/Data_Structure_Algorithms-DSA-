//Remove all Occurrences of a Substring

//Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string.

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string removeOccurrences(string s, string part) {
    
    while(s.length()>0 && s.find(part)<s.length()){
        s.erase(s.find(part), part.length());
    }
        
    return s;
}


int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    string ans = removeOccurrences(s, part);

    cout<<"Remaining string after deleting all substrings is : "<<ans<<endl;

    return 0;
}
