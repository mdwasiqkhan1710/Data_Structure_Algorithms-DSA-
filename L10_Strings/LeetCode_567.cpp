//Permutation in String

//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isFreqSame(vector<int>& freq1, vector<int>& freq2){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
}

bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);

        for(int i=0; i<s1.size(); i++){
            freq[s1[i] - 'a']++;
        }

        int windowSize = s1.size();

        for(int i=0; i<s2.size(); i++){
            int windowIdx = 0, idx = i;
            vector<int> windowFreq(26, 0);

            while(windowIdx < windowSize && idx < s2.size()){
                windowFreq[s2[idx] - 'a']++;
                idx++; 
                windowIdx++;
            }

            if(isFreqSame(freq, windowFreq)){
                return true;
            }
        }

        return false;
}

int main(){
    string s1="ab";
    string s2="cbdbaooa";

    bool ans = checkInclusion(s1, s2);

    cout<<"If s2 has permutaion of s1 then answer will 1 else 0 : "<<ans<<endl;

    return 0;
}