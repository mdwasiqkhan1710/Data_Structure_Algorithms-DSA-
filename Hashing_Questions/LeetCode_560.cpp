// SubArray Sum equals K

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
//  A subarray is a contiguous non-empty sequence of elements within an array.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force Approach
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }

    return count;
}

// Optimized Approach
int subarraySum2(vector<int> &nums, int k)
{
    int n = nums.size(); // Calculated the size of nums array
    int count = 0;       // Initilized the count variable for storing the final ans

    vector<int> prefixSum(n, 0); // created a vector for storing prefix sum values
    prefixSum[0] = nums[0];      // Intilized first ele of prefixSum arr with first ele of nums arr

    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + nums[i]; // calculated the remaining values of prefixSum arr

    unordered_map<int, int> m; // created map for storing the prefixsum with its freq

    // Calculating the freq for each values
    for (int j = 0; j < n; j++)
    {
        if (prefixSum[j] == k)
            count++; // checked if curr value of prefix sum = k then update the final ans "count"

        int val = prefixSum[j] - k; // value which we have to look in the map

        if (m.find(val) != m.end())
            count += m[val]; // updated the count variable using the freq stored in map for the val if val is found in map

        if (m.find(prefixSum[j]) == m.end())
        { // If val is not found then add it to map with freq
            m[prefixSum[j]] = 0;
        }

        m[prefixSum[j]]++; // updating the freq if found in map
    }
    return count;
}

int main()
{
    vector<int> nums = {9, 4, 20, 3, 10, 5};
    int k = 33;

    int ans = subarraySum(nums, k);
    int ans2 = subarraySum2(nums, k);

    cout << "Number of subarrays with sum equals to k is/are Ans1 : " << ans << endl;
    cout << "Number of subarrays with sum equals to k is/are Ans2 : " << ans2 << endl;

    return 0;
}