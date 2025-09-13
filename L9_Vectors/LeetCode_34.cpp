//Find first and last position of the element in sorted array

#include <iostream>
#include <vector>
using namespace std;

//Brute Force
vector<int> searchRange(vector<int>& nums, int target, int n){
    
    vector<int> ans;
    for(int i=0; i<n-1; i++){
        if(nums[i]==target){
            ans.push_back(i);
            ans.push_back(i+1);
            break;
        }
    }

    if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
    }

    return ans;
}

int main(){
    vector<int> nums={5, 7, 7, 8, 8, 10};
    int target=2;
    int n = nums.size();

    vector<int> ans = searchRange(nums, target, n);
    for(int val:ans){
        cout<<val<<", ";
    }
    return 0;
}
