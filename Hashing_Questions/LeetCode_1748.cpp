//Sum of Unique Elements

//You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
//Return the sum of all the unique elements of nums.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Brute Force Approach
int sumOfUnique(vector<int>& nums) {
        int sum=0; int n=nums.size();

        sort(nums.begin(), nums.end());

        if(n==1) return nums[0];

        if(nums[0] != nums[1]) sum += nums[0];
        if(nums[n-1] != nums[n-2]) sum += nums[n-1];

        for(int i=1; i<n-1; i++){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                sum += nums[i];
            }else{
                continue;
            }
        }

        return sum;
}

//Optimized Approach -- Using Hashing
int sumOfUnique2(vector<int>& nums) {
        int sum=0; int n=nums.size();
        unordered_map<int, int> m;

        for(int i=0; i<n; i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }
            else{
                m[nums[i]]++;
            }
        }

        for(auto i = m.begin(); i != m.end(); i++){
            if(i->second == 1) {
                sum += i->first;
            }
        }

        return sum;
}


int main(){
    vector<int> nums={1, 2, 3, 2};
    vector<int> nums2={1,2,3,4,5};
    
    //Brute force approach ans
    cout<<"Brute Force Ans for arr1 = "<<sumOfUnique(nums)<<endl;
    cout<<"Brute Force Ans for arr2 = "<<sumOfUnique(nums2)<<endl;

    //Optimized Approach ans
    cout<<"Optimized Approach Ans for arr1 = "<<sumOfUnique2(nums)<<endl;
    cout<<"Optimized Approach Ans for arr2 = "<<sumOfUnique2(nums2)<<endl;
    
    return 0;
}