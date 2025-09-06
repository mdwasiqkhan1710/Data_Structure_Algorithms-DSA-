//Majority Element Problem

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//My Try 
int majorityElememt1(vector<int>& nums){
    int n=nums.size()/2;
    sort(nums.begin(), nums.end());
    int count=0;
    int ans=nums[0];
    for(int i=0; i<nums.size(); i++){

        if(nums[i]!=ans && count<n){
            ans=nums[i];
            count=1;
        }
        if(nums[i]==ans && count>n){
            count++;
            return ans;
        }
    }

    return ans;
}


// Brute Force Approach
int majorityElememt2(vector<int>& nums){
    for(int val:nums){
        int freq=0;
        for(int ele:nums){
            if(val==ele){
                freq++;
            }
        }
        if(freq>nums.size()/2){
            return val;
        }
    }
    return 0;
}


//Most Optimized approach --- Moore's Voting Algorithm
int majorityElememt3(vector<int>& nums){
    int ans=0, freq=0;
    for(int i=0; i<nums.size(); i++){
        if(freq==0){
            ans=nums[i];
        }
        if(nums[i]==ans){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={3,2,3,3,1,3,1,3,2};

    cout<<"Majority element is: "<<majorityElememt3(nums)<<endl;
    return 0;
}