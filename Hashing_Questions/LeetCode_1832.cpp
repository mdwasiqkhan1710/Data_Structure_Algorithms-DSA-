//Check if the Sentence is Pangram

//A pangram is a sentence where every letter of the English alphabet appears at least once.
//Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool checkIfPangram(string sentence){
    vector<char> freq(26, 0); //created vector for storing the freq of each character 

    //Going across the string to check and update the frequency of each character
    for(char ch : sentence){
        freq[ch-'a']++;
    }

    //Going across the vector freq to check if any charcter has 0 freq then return false else true
    for(int i=0; i<freq.size(); i++){
        if(freq[i]<1) return false;
    }

    return true;
}

//Optimized Approach 
bool checkIfPangram2(string sentence){
    unordered_map<char, int> m;

    for(int i=0; i<sentence.size(); i++){
        if(m.find(sentence[i]) == m.end()) m[sentence[i]] = 1;
        else m[sentence[i]]++;
    }

    if(m.size() >= 26) return true;

    return false;
}

int main(){
    string sentence = "thequickbrownfoxjumpsoverthelazydog";

    bool ans = checkIfPangram(sentence);
    bool ans2 = checkIfPangram2(sentence);

    cout<<"If given senetence is pangram then output will be 1 else 0 : "<<ans<<endl;
    cout<<"If given senetence is pangram then output will be 1 else 0 : "<<ans2<<endl;

    return 0;
}