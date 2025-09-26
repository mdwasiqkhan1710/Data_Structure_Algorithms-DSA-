//Rearrange Array Elements by Sign

//You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

#include <iostream>
#include <vector>
using namespace std;

//Brute force approach
vector<int> rearrangeArray(vector<int>& nums, int n) {
        vector<int> pts; // vector for storing positive numbers
        vector<int> nts; // vector for storing negative numbers

        for (int num : nums) {
            if (num > 0) {
                pts.push_back(num);
            } else {
                nts.push_back(num);
            }
        }

        vector<int> ans(n);
        int i = 0, j = 0, idx = 0;

        while (idx < n) {
            if (idx % 2 == 0) {
                ans[idx++] = pts[i++];
            } else {
                ans[idx++] = nts[j++];
            }
        }

        return ans;
}

int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};
    int n = nums.size();

    vector<int> ans = rearrangeArray(nums, n);

    for(int val : ans){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}