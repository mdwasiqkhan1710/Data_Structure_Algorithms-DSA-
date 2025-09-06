// Single Number Problem

#include <iostream>
#include <vector>
using namespace std;

int uniqueNum(vector<int> &nums)
{

    int ans = 0;

    for (int val : nums)
    {
        ans = ans ^ val;
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Unique digit in the array is: " << uniqueNum(nums) << endl;

    return 0;
}