//Unique Number of Occurrences

//Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr){

    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<int> freq;
    int count = 1;
    int curr = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] == curr){
            count++;
        }else{
            freq.push_back(count);
            count=1;
            curr=arr[i];
        }
    }

    freq.push_back(count);

    int m = freq.size();

    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            if(freq[i] == freq[j]) return false;
        }
    }

    return true;
}

//Optimized approach -- Using Hashing
bool uniqueOccurrences2(vector<int>& arr) {
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            if (m.find(arr[i]) == m.end())
                m[arr[i]] = 1;
            else
                m[arr[i]]++;
        }

        unordered_set<int> seen;
        for (auto i = m.begin(); i != m.end(); i++) {
            if (seen.find(i->second) != seen.end())
                return false;

            else
                seen.insert(i->second);
        }

        return true;
}

int main(){
    vector<int> arr={1,2,2,1,1,3};

    bool ans = uniqueOccurrences(arr);
    bool ans2 = uniqueOccurrences2(arr);

    cout<<"For true output will be 1 and for false output will be 0 : "<<ans2<<endl;

    return 0;
}