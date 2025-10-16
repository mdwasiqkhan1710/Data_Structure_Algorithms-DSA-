//Find the Duplicate Number 

//Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans;

        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                ans = nums[i];
                break;
            }
        }
        return ans;
}

int findDuplicate2(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        int ans;

        for(int i=0; i<n; i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
            }
            else{
                ans=nums[i];
                break;
            }
        }
        return ans;
}

//Best Approach -- Slow and Fast pointer approach
int findDuplicate3(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        slow = nums[0];

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
}

int main(){
    vector<int> arr = {1,3,4,2,2};
    // int ans = findDuplicate(arr);
    // int ans2 = findDuplicate2(arr);
    int ans3 = findDuplicate3(arr);

    cout<<"Duplicate number is = "<<ans3<<endl;
    return 0;
}
