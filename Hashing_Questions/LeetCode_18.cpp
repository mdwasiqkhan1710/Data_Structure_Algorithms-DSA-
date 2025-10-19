//4 Sum Problem 

//Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//Brute force approach 
vector<vector<int>> fourSum(vector<int>& nums, int target){
    int n = nums.size();
    set<vector<int>> unique;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                        vector<int> quads = {nums[i], nums[j], nums[k], nums[l]};
                        sort(quads.begin(), quads.end());
                        if(unique.find(quads) == unique.end()){
                        unique.insert(quads);
                    }
                    }
                }
            }
        }
    }

    vector<vector<int>> result(unique.begin(), unique.end());
    return result;
}

//Otpimized Approach using Two Pointer 
vector<vector<int>> fourSum2(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;

        for(int j=i+1; j<n; j++){
            if(j > i + 1 && nums[j] == nums[j-1]) continue;

            int st=j+1; int end=n-1;

            while(st<end){
                long long sum = (long long)nums[i]+ (long long)nums[j]+ (long long)nums[st]+ (long long)nums[end];

                if(sum<target) st++;
                else if(sum>target) end--;
                else{
                    ans.push_back({nums[i], nums[j], nums[st], nums[end]});
                    st++;
                    end--;

                    while(st < end && nums[st] == nums[st-1]) st++;
                    while(st < end && nums[end] == nums[end+1]) end--;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {2,2,2,2};
    int target = 8;
    vector<vector<int>> result = fourSum2(nums, target);

    //Printing the answer
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