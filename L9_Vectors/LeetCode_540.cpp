// Single Element in Sorted Array

#include <iostream>
#include <vector>
using namespace std;

// Brute force approach
int singleElement(vector<int> &nums)
{
    int n = nums.size();

    // if array has only 1 element then return same element
    if (n == 1)
        return nums[0];

    // Checking for first element if it satisfy condition of que
    if (nums[0] != nums[1])
        return nums[0];

    // checking for last element if it satisfy condition of que
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
        {
            return nums[i];
        }
    }
    return -1; // returning -1 if their is no element satisfying ques condition
}

// Optimal approach using binary search
int singleElementBinary(vector<int> &nums)
{
    int n = nums.size();
    int st = 0;
    int end = n - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        // If unique element occurs at index-1
        if (mid == 0 && nums[0] != nums[1])
            return nums[0];
        // If unique element occurs at last index
        if (mid == n - 1 && nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        // If there is only one element in the array
        if (n == 1)
            return nums[0];

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];
        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid - 1])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << "Element that occurs only once is: " << singleElement(nums) << endl;
    cout << "Element that occurs only once is: " << singleElementBinary(nums) << endl;
    return 0;
}