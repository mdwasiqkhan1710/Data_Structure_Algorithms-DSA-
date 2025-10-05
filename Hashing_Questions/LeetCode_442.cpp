//Find All Duplicates in an Array

//Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.
//You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Brute force approach
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans; 
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
            }
        }

        return ans;
}

//Optimized Approach
vector<int> findDuplicates2(vector<int>& nums) {
        vector<int> ans; 
        int n = nums.size();

        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }else{
                m[nums[i]]++;
            }
        }

        for(auto i=m.begin(); i!=m.end(); i++){
            if(i->second == 2){
                ans.push_back(i->first);
            }
        }

        return ans;
}


int main(){
    vector<int> nums={4,3,2,7,8,2,3,1};

    vector<int> ans = findDuplicates(nums);
    vector<int> ans2 = findDuplicates2(nums);

    for(int val : ans2){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}