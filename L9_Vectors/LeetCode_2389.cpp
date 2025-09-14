// Longest Subsequence with limited sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approach
vector<int> answerQueries(vector<int> &nums, vector<int> &queries, int n, int m)
{

    sort(nums.begin(), nums.end());
    vector<int> ans(m);
    vector<int> sum(n);
    sum[0] = nums[0];

    for (int i = 1; i < n; i++)
        sum[i] = nums[i] + sum[i - 1];

    // Edge case
    for (int i = 0; i < m; i++)
    {
        if (queries[i] < sum[0])
        {
            ans[i] = 0;
            continue;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int currCount = 0;

        for (int j = 0; j < n; j++)
        {
            if (sum[j] <= queries[i])
            {
                currCount++;
            }
            else
            {
                break;
            }
        }
        ans[i] = currCount;
    }

    return ans;
}

//Optimal Approach 
vector<int> answerQueriesBinary(vector<int> &nums, vector<int> &queries, int n, int m){
        sort(nums.begin(), nums.end());
        vector<int> ans(m);
        vector<int> sum(n);
        sum[0] = nums[0];

        for(int i=1; i<n; i++) sum[i] = nums[i]+sum[i-1];

        //Edge case
        for(int i=0; i<m; i++){
            if(queries[i]<sum[0]){
                ans[i]=0;
                continue;
            }
        }

        for(int i=0; i<m; i++){
            int q = queries[i];
            int st=0, end=n-1;
            int count=0;

            while(st<=end){
                int mid = st+(end-st)/2;

                if(sum[mid]<=q){
                    count = mid+1;
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
            ans[i]=count;
        }
        return ans;
}

int main()
{
    vector<int> nums = {4, 5, 2, 1}, queries = {3, 10, 21};
    int n = nums.size();
    int m = queries.size();

    // vector<int> answer = answerQueries(nums, queries, n, m);
    vector<int> answer = answerQueriesBinary(nums, queries, n, m);

    for (int val : answer)
    {
        cout << val << ", ";
    }

    return 0;
}