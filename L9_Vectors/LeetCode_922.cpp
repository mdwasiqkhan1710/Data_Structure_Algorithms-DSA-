// Sort Array by Parity II

// Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
// Return any answer array that satisfies this condition.

#include <iostream>
#include <vector>
using namespace std;

// Brute force approach
vector<int> sortArrayByParityII(vector<int> &nums, int n)
{

    vector<int> even;
    vector<int> odd;

    for (int num : nums)
    {
        if (num % 2 == 0)
        {
            even.push_back(num);
        }
        else
        {
            odd.push_back(num);
        }
    }

    vector<int> ans(n);

    int i = 0, j = 0;
    int idx = 0;

    while (i < even.size() || j < odd.size())
    {
        if (idx % 2 == 0)
        {
            ans[idx++] = even[i++];
        }
        else
        {
            ans[idx++] = odd[j++];
        }
    }

    return ans;
}

// Optimal Approach -- removed/reduced usage of extra space
vector<int> sortArrayByParityIIOptimal(vector<int> &nums, int n)
{
    vector<int> ans(n);
    int evenIdx = 0, oddIdx = 1;

    for (int num : nums)
    {
        if (num % 2 == 0)
        {
            ans[evenIdx] = num;
            evenIdx += 2;
        }
        else
        {
            ans[oddIdx] = num;
            oddIdx += 2;
        }
    }

    return ans;
}

// Most optimized Approach
vector<int> sortArrayByParityIIOptimized(vector<int> &nums, int n)
{
    int i = 0; // Pointer for even indices
    int j = 1; // Pointer for odd indices

    while (i < n && j < n)
    {
        // Find even index that has an odd number
        while (i < n && nums[i] % 2 == 0)
        {
            i += 2;
        }

        // Find odd index that has an even number
        while (j < n && nums[j] % 2 == 1)
        {
            j += 2;
        }

        // If both pointers are valid, swap the mismatched elements
        if (i < n && j < n)
        {
            swap(nums[i], nums[j]);
        }
    }

    return nums;
}

int main()
{
    vector<int> nums = {4, 2, 5, 7};
    int n = nums.size();

    vector<int> ans = sortArrayByParityII(nums, n);
    vector<int> ans2 = sortArrayByParityIIOptimal(nums, n);
    vector<int> ans3 = sortArrayByParityIIOptimized(nums, n);

    for (int val : ans3)
    {
        cout << val << ", ";
    }
    cout << endl;

    return 0;
}