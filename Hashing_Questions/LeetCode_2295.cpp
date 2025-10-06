//Replace Elements in an Array

//You are given a 0-indexed array nums that consists of n distinct positive integers. Apply m operations to this array, where in the ith operation you replace the number operations[i][0] with operations[i][1].

// It is guaranteed that in the ith operation:
// operations[i][0] exists in nums.
// operations[i][1] does not exist in nums.
// Return the array obtained after applying all the operations.

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

// Brute Force approach (applicable to only some test cases)
vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations){
    int n = nums.size(); int m = operations.size();

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(nums[j] == operations[i][0]) nums[j] = operations[i][1];
        }
    }

    return nums;
}

vector<int> arrayChange2(vector<int>& nums, vector<vector<int>>& operations) {
        //Initilized unordered map for storing values from nums with val-->index mapping
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++){
            m[nums[i]] = i;
        }

        //Initilized idx to track subarrays from operations
        int idx = 0;

        while(idx < operations.size()){
            //Checking if old value is present in map
            int val = operations[idx][0];

            if(m.find(val) != m.end()){
                //Taking the index from nums array where old val is stored
                int numsIdx = m[val];

                //Replacing the old val from nums with new value from operations
                nums[numsIdx] = operations[idx][1];

                //Deleting the val from map
                m.erase(val);

                m[operations[idx][1]] = numsIdx;

                idx++;
            }else{
                idx++;
            }
        }

        return nums;
}

int main(){
    vector<int> nums={1,2,4,6};
    vector<vector<int>> opearations = {{1,3}, {4,7}, {6,1}};

    vector<int> ans2 = arrayChange2(nums, opearations);

    cout<<"{ ";
    for(int val : ans2){
        cout<<val<<" ";
    }
    cout<<"}";

    cout<<endl;

    return 0;
}