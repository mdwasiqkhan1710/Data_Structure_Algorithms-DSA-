// 3 Sum Problem 

//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Brute Force Approach -- Time Complexity = O(N^3 * log(uniqueTriplets))
vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    set<vector<int>> uniqueTriplets; // Using set to avoid duplicates
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    // Create a triplet and sort it to handle duplicates
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    if(uniqueTriplets.find(triplet) == uniqueTriplets.end()){
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }
    }
    
    // Convert set to vector
    vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
    return result;
}

// Little Optimized Approach - Time Complexity : O(uniqueTriplets + n)
vector<vector<int>> threeSum2(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uniqueTriplets;

        for(int i=0; i<n; i++){
            int tar = -nums[i];
            set<int> s;
            for(int j=i+1; j<n; j++){
                int third = tar - nums[j];
                if(s.find(third) != s.end()){
                    vector<int> triplets = {nums[i], nums[j], third};
                    sort(triplets.begin(), triplets.end());
                    uniqueTriplets.insert(triplets);
                }
                s.insert(nums[j]);
            }
        }
        
        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());

        return ans;
}

//Most Optimized Approach
vector<vector<int>> threeSum3(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j = i+1; int k = n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];

                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; 
                    k--;

                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }
        }
        return ans;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<vector<int>> result = threeSum(nums);
    // vector<vector<int>> result = threeSum2(nums);
    vector<vector<int>> result = threeSum3(nums);

    cout << "[";
    for(int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j];
            if(j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}