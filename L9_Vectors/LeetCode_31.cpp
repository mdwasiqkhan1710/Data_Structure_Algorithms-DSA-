// Next Permutation

// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextPermutation(vector<int> &nums, int n)
{
    vector<int> ans(n);

    // Step 1: Find the Pivot
    int pivot = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }
    // If no pivot is found
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    // Step 2: Find the element which is larger than pivot
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // Step 3: Reverse the array
    int i = pivot + 1;
    int j = n - 1;
    while (i <= j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }

    return nums;
}

int main(){
    vector<int> nums = {1,2,3};
    int n = nums.size();

    vector<int> ans = nextPermutation(nums, n);

    cout<<"Next Permutation for this array is : ";
    for(int val : ans){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}