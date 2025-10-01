//Contains Duplicates

//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//Brute force approach
bool containsDuplicate1(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]==nums[j]) return true;
            }
        }
        return false;
}

//Optimized Approach -- Hashing Used
bool containsDuplicate2(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;

        for(int i=0; i<n; i++){
            if(s.find(nums[i]) != s.end()) return true;
            else s.insert(nums[i]);
        }

        return false;
}

int main(){
    vector<int> nums={1,2,3,1};
    bool ans = containsDuplicate1(nums);
    bool ans2 = containsDuplicate2(nums);

    cout<<ans<<endl;
    cout<<ans2<<endl;

    return 0;
}