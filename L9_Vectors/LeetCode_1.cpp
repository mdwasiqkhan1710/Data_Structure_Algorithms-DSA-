//Two Sum

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Brute force approach
vector<int> twoSum(vector<int>& nums, int target){

    vector<int> ans;

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

//Better approach
vector<int> twoSumBetter(vector<int>& nums, int target){
    int st=0, end=nums.size()-1;
    vector<int> ans; //Vector initilized to store the answer 

    //Sorting the array first
    sort(nums.begin(), nums.end());

    while(st<=end){
        if(nums[st]+nums[end]==target){
            ans.push_back(st);
            ans.push_back(end);
        }

        if(nums[st]+nums[end]>target) end--;
        else st++;
    }

    return ans;
}

//Optimized Approach using -- Hashing
vector<int> twoSumBest(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            int second = target - first;

            if(m.find(second) != m.end()){
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }

            m[first] = i;
        }

        return ans;
}


int main(){
    vector<int> nums={2, 3, 7, 11, 15};
    int target = 26;
    
    vector<int> ans = twoSum(nums, target);
    vector<int> ans2 = twoSumBetter(nums, target);
    vector<int> ans3 = twoSumBest(nums, target);

    cout<<"Adding the elements on following indices will result in given target : ";
    for(int val : ans2){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}