//Count the Number of Special Characters I

//You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
//Return the number of special letters in word.

#include <iostream>
#include <vector>
#include <string>
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

int main(){
    string word="aaAbcBC";
    
    int ans = numberOfSpecialChars(word);

    cout<<"Number of special Characters are : "<<ans<<endl;

    return 0;
}