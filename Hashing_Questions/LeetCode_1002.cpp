//Find common Characters

//Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> commonChars1(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);
        
        for(const string& word : words) {
            vector<int> freq(26, 0);
            for(char c : word) {
                freq[c - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }
        
        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < minFreq[i]; j++) {
                ans.push_back(string(1, 'a' + i));
            }
        }
        
        return ans;
}

//Optimized Approach using Hashing
vector<string> commonChars2(vector<string>& words) {
        int n = words.size();
        
        // Create a frequency map for the first word
        unordered_map<char, int> commonFreq;
        for(char c : words[0]) {
            commonFreq[c]++;
        }
        
        // For each subsequent word, update the common frequency
        for(int i = 1; i < n; i++) {
            unordered_map<char, int> currentFreq;
            
            // Count frequency in current word
            for(char c : words[i]) {
                currentFreq[c]++;
            }
            
            // Update common frequency to minimum of current and previous
            for(auto it = commonFreq.begin(); it != commonFreq.end(); it++) {
                char ch = it->first;
                if(currentFreq.find(ch) != currentFreq.end()) {
                    commonFreq[ch] = min(commonFreq[ch], currentFreq[ch]);
                } else {
                    commonFreq[ch] = 0;  // Character not present in current word
                }
            }
        }
        
        // Build the result
        vector<string> ans;
        for(auto& pair : commonFreq) {
            for(int i = 0; i < pair.second; i++) {
                ans.push_back(string(1, pair.first));
            }
        }
        
        return ans;
}

int main(){
    vector<string> words = {"bella","label","roller"};

    vector<string> ans = commonChars2(words);
    cout<<"{";
    for(string s : ans){
        cout<<s<<",";
    }
    cout<<"}";

    cout<<endl;
    
    return 0;

}