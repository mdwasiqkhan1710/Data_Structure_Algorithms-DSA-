// Sort Array by Parity

//Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
// Return any array that satisfies this condition.

#include <iostream>
#include <vector>
using namespace std;

//Brute Force Approach 
vector<int> sortArrayByParity(vector<int>& nums){
    vector<int> even;
    vector<int> odd;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]%2 == 0){
            even.push_back(nums[i]);
        }else{
            odd.push_back(nums[i]);
        }
    }

    for(int num: odd){
        even.push_back(num);
    }

    return even;
}

//Optimal Approach - Two pointer 

vector<int> sortArrayByParity2(vector<int>& nums) {
        int st=0, end=nums.size()-1;
        if(nums.size()==1) return nums;

        while(st<=end){
            if(nums[st]%2 == 0){
                st++;
            }else if(nums[st]%2 != 0){
                swap(nums[st], nums[end]);
                end--;
            }
        }
        return nums;
}

int main(){
    vector<int> nums = {3, 1, 2, 4};

    vector<int> ans = sortArrayByParity(nums);

    for(int val: ans){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}