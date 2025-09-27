//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

#include <iostream>
#include <vector>
using namespace std;

//Brute force approach
vector<int> sortColors(vector<int>& nums, int n) {
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        return nums;
}

//Another brute force approach
vector<int> sortColors2(vector<int>& nums, int n){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i=0; i<n; i++){
        if(nums[i] == 0) count0++;
        else if(nums[i] == 1) count1++;
        else count2++;
    }

    vector<int> ans(n);
    int idx=0;

    //Pushing 0 in the answer vector
    for(int j=0; j<count0; j++){
        ans[idx++] = 0;
    }

    //Pushing 1 in the answer vector
    for(int j=0; j<count1; j++){
        ans[idx++] = 1;
    }

    //Pushing 2 in the answer vector
    for(int j=0; j<count2; j++){
        ans[idx++] = 2;
    }

    return ans;
}

int main(){
    vector<int> nums = {2,0,1,1,0,2};
    int n = nums.size();

    vector<int> ans = sortColors(nums, n);
    vector<int> ans2 = sortColors2(nums, n);

    for(int val: ans2){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}