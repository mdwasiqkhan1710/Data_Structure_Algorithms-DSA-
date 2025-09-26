// Remove Duplicates from Sorted Array

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

#include <iostream>
#include <vector>
using namespace std;

// Brute force
int removeDuplicates(vector<int> &nums, int n)
{
    int k = 1;
    int curr = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != curr)
        {
            k++;
            curr = nums[i];
        }
    }

    // changing array as per ques
    int newCurr = nums[0];
    int pos = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != newCurr)
        {
            newCurr = nums[i];
            swap(nums[i], nums[pos]);
            pos++;
        }
    }

    return k;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4};
    int n = nums.size();

    int ans = removeDuplicates(nums, n);
    cout << ans << endl;

    return 0;
}