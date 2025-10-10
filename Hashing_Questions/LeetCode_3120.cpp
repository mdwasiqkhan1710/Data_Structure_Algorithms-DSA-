//Count the Number of Special Characters I

//You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
//Return the number of special letters in word.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//Brute Force approach 
int numberOfSpecialChars(string word) {
        vector<int> lower(26,-1);
        vector<int> upper(26,-1);

        for(int i=0; i<word.size(); i++){
            if(word[i]>='a'&&word[i]<='z') lower[word[i]-'a']=i;
            else if(word[i]>='A'&&word[i]<='Z') upper[word[i]-'A']=i;
        }

        int count=0;
        for(int i=0; i<26; i++){
            if(lower[i]!=-1 && upper[i]!=-1) count++;
        }

        return count;
}

//Optimized approach using Hashing
int numberOfSpecialChars2(string word) {
        unordered_map<char, int> lower;
        unordered_map<char, int> upper;

        int n = word.size(); int count = 0;

        for(int i=0; i<n; i++){
            //Checking for Upper Case Letters
            if(word[i]>='A' && word[i]<='Z' && upper.find(word[i])==upper.end()){
                upper[word[i]]=i;
            }
            //Checking for Lower case letters
            else if(word[i]>='a' && word[i]<='z' && lower.find(word[i])==lower.end()){
                lower[word[i]]=i;
            }
        }

        //Checking and updating the count of special characters
        for(auto& ch : lower){
            char lowerChar = ch.first;
            char upperChar = lowerChar - 32;
            
            // Check if uppercase exists
            if(upper.find(upperChar) != upper.end()){
                count++;
            }
        }

        return count;
}

int main(){
    string word="aaAbcBC";
    
    int ans = numberOfSpecialChars(word);
    int ans2 = numberOfSpecialChars2(word);

    cout<<"Number of special Characters are : "<<ans<<endl;
    cout<<"Number of special Characters are : "<<ans2<<endl;

    return 0;
}