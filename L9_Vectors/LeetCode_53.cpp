//Maximum Subarray sum

#include <iostream>
#include <vector>
using namespace std;

//Brute Force Approach
int maxSum1(vector<int>& nums, int n){
    int maxSum = INT_MIN;
    
    for(int st=0; st<n; st++){
        int currSum=0;
        for(int end=st; end<n; end++){
            currSum+=nums[end];
            maxSum=max(currSum, maxSum);
        }
    }

    return maxSum;
}


//Kadane's Algorithm
int maxSum2(vector<int>& nums, int n){
    int maxSum=INT_MIN;
    int currSum=0;

    for(int val:nums){
        currSum+=val;
        maxSum=max(maxSum,currSum);

        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}

int main(){
    vector<int> nums={3, -4, 5, 4, -1, 7, -8};
    int n = nums.size();

    cout<<"Max subarray sum using brute force approach= "<<maxSum1(nums, n)<<endl;
    cout<<"Max subarray sum using Kadane's Algorithm= "<<maxSum2(nums, n)<<endl;

    return 0;
}