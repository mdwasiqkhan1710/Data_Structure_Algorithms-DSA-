//Sort Array by Increasing Frequency

//Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
// Return the sorted array.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int i=0; i<nums.size(); i++){
            if(freq.find(nums[i]) == freq.end()) freq[nums[i]] = 1;
            else freq[nums[i]]++;
        }

        sort(nums.begin(), nums.end(), [&](int n1, int n2){
            if(freq[n1] != freq[n2]) return freq[n1]<freq[n2];
            else return n2<n1;
        });

        return nums;
}

int main(){
    vector<int> nums = {1,1,2,2,2,3,3,3,3,4,5};

    vector<int> ans = frequencySort(nums);

    for(int val:ans){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}
