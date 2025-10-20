//Subarray Sums Divisible by K

//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Burte Force Approach
int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];

                if(sum % k == 0) count++;
            }
        }
        return count;
}

//Optimized Approach
int subarraysDivByK2(vector<int>& nums, int k) {
        int n = nums.size(); //Size of input array
        unordered_map<int, int> m; // Map to store frequency of remainders
        int count = 0; 
        int sum = 0;

        if(n==0) return 0;
        m[0] = 1; // Important: prefix sum 0 has remainder 0. Initial sum = 0 and that sum % k will be equal to 0 always
        

        int i=0;

        while(i<n){
            sum += nums[i++]; //Store prefix Sum
            int rem = sum % k; // Calculate remainder
            if(rem < 0) rem += k;

            // If we've seen this remainder before, it means we found subarrays divisible by k
            if(m.find(rem) != m.end()) count += m[rem];
            
            // Update frequency of current remainder
            m[rem]++;
        }

        return count;
}


int main(){
    vector<int> nums = {4,5,0,-2,-3,1}; 
    int k = 5;
    int ans = subarraysDivByK(nums, k);
    int ans2 = subarraysDivByK2(nums, k);

    cout<<"Number of subarrays divisible by k are : "<<ans<<endl;
    cout<<"Number of subarrays divisible by k are : "<<ans2<<endl;
    
    return 0;
}