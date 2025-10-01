//Check if All Characters Have Equal Number of Occurrences

//Given a string s, return true if s is a good string, or false otherwise.
// A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <algorithm>
using namespace std;

//Brute Force Approach 
bool areOccurrencesEqual(string s) {
        vector<int> freq;
        int count = 1;

        sort(s.begin(), s.end());
        char curr = s[0];

        for(int i=1; i<s.size(); i++){
            if(curr == s[i]){
                count++;
            }else{
                freq.push_back(count);
                count = 1;
                curr = s[i];
            }
        }

        freq.push_back(count);

        for(int i=0; i<freq.size()-1; i++){
            if(freq[i] != freq[i+1])
            return false;
        }

        return true;
}

//Optimized Approach
bool areOccurrencesEqual2(string s) {
        unordered_map<char, int> map;

        for(int i=0; i<s.size(); i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = 1;
            }else{
                map[s[i]]++;
            }
        }

        int count = map[s[0]];
        for(auto i=map.begin(); i!=map.end(); i++){
            if(i->second != count){
                return false;
            }
        }

        return true;
}

int main(){
    string s="abacbc";
    bool ans = areOccurrencesEqual(s);
    bool ans2 = areOccurrencesEqual2(s);

    cout<<"1 means Ture and 0 means False, thus Answer from Brute approach: "<<ans<<endl;
    cout<<endl;
    cout<<"1 means Ture and 0 means False, thus Answer from Optimized approach: "<<ans2<<endl;
    cout<<endl;
    return 0;
}