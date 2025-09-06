// Pair Sum : Given an array and target value we need to return the elements whose sum equals target.
// arr={2, 7, 11, 15} and Target = 9
// Asnwer will be {2, 7}

#include <iostream>
#include <vector>
using namespace std;

// brute force approach
vector<int> pairSum1(vector<int> arr, int n, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
        }
    }
    return ans;
}

// Optimal Approach
vector<int> pairSum2(vector<int> &arr, int n, int target)
{
    vector<int> ans;
    int st = 0, end = n - 1;
    while (st < end)
    {
        int Sum=arr[st] + arr[end];
        if (Sum > target)
        {
            end--;
        }
        else if (Sum < target)
        {
            st++;
        }
        else
        {
            ans.push_back(arr[st]);
            ans.push_back(arr[end]);
            return ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int n = arr.size();
    int target = 9;

    vector<int> ans = pairSum2(arr, n, target);
    cout << "Target equals: " << ans[0] << " & " << ans[1] << endl;
    return 0;
}