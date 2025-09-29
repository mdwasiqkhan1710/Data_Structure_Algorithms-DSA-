//Rotate Array

//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rotate(vector<int>& nums, int k, int n){

    vector<int> pre;
    vector<int> post;

    for(int i=(n-k); i<n; i++){
        pre.push_back(nums[i]);
    }

    for(int i=0; i<n-k; i++){
        post.push_back(nums[i]);
    }

    for(int j=0; j<post.size(); j++){
        pre.push_back(post[j]);
    }

    return pre;
}

//Optimized Approach
vector<int> rotate2(vector<int>& nums, int k, int n){
    k = k % n;

    // Reverse the complete Array output will look {7,6,5,4,3,2,1}
    reverse(nums.begin(), nums.end());

    // Reverse the First K elements, output will look {5,6,7,4,3,2,1}
    reverse(nums.begin(), nums.begin() + k);

    // Reverse the remaining n-k elements output will look {7,6,5,1,2,3,4} which is the required ans
    reverse(nums.begin() + k, nums.end());

    return nums;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    int n = nums.size();

    vector<int> ans = rotate(nums, k, n);

    vector<int> ans2 = rotate2(nums, k, n);

    for(int val : ans2){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}