// Reverse words in a String

//Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
       reverse(s.begin(), s.end());
       string ans="";

       for(int i=0; i<s.length(); i++){
        string word="";
        while(i<s.length() && s[i]!=' '){
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if(word.length()>0){
            ans += " "+word;
        }

       }

       return ans.substr(1); 
}

int main(){
    string s = " the sky is blue ";

    string ans = reverseWords(s);

    cout<<"After reversing the words of the string : "<<ans<<endl;

    return 0;
}