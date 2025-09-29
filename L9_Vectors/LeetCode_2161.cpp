//Partition Array According to Given Pivot

//You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
// Every element less than pivot appears before every element greater than pivot.
// Every element equal to pivot appears in between the elements less than and greater than pivot.
// The relative order of the elements less than pivot and the elements greater than pivot is maintained.

#include <iostream>
#include <vector>
using namespace std;

//Brute Force Approach
vector<int> pivotArray(vector<int>& nums, int pivot, int n) {
        vector<int> v1, v2, v3;

        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                v1.push_back(nums[i]);
            }else if(nums[i]>pivot){
                v3.push_back(nums[i]);
            }else{
                v2.push_back(nums[i]);
            }
        }

         vector<int> ans;

            for(int i=0; i<v1.size(); i++){
                ans.push_back(v1[i]);
            }

            for(int i=0; i<v2.size(); i++){
                ans.push_back(v2[i]);
            }

            for(int i=0; i<v3.size(); i++){
                ans.push_back(v3[i]);
            }

            return ans;
}

//Optimized Approach
vector<int> pivotArray2(vector<int>& nums, int pivot, int n) {
        
        int i=0; int j=n-1;

        vector<int> ans(n, pivot);
        int ansSt = 0, ansEnd = n-1;

        while(i<n && j>=0){
            if(nums[i]<pivot){
                ans[ansSt++] = nums[i];
            }

            if(nums[j]>pivot){
                ans[ansEnd--] = nums[j];
            }

            i++;
            j--;
        }

        return ans;
}

int main(){
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    int n=nums.size();

    vector<int> ans=pivotArray(nums, pivot, n);
    vector<int> ans2=pivotArray2(nums, pivot, n);

    for(int val : ans2){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}