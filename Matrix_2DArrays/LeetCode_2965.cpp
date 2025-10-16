//Find missing and repeated values.

//You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set> 
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalSize = n * n;
        vector<int> arr;
        long long actualSum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                arr.push_back(grid[i][j]);
                actualSum += grid[i][j];
            }
        }

        int a = -1; // repeated number
        int b = -1; // missing number

        sort(arr.begin(), arr.end());

        // Find repeated number
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] == arr[i + 1]) {
                a = arr[i];
                break;
            }
        }

        // Calculate expected sum of numbers from 1 to n²
        long long expectedSum = (long long)totalSize * (totalSize + 1) / 2;
        
        // The difference between actual and expected sum gives us:
        // actualSum = expectedSum - b + a
        // So: b = a + expectedSum - actualSum
        b = a + expectedSum - actualSum;

        return {a, b};
}

//Optimized Approach

vector<int> findMissingAndRepeatedValues2(vector<vector<int>>& grid){
    int n = grid.size();
    unordered_set<int> s;

    int a, b;

    int expectedSum = (n*n)* ((n*n)+1)/2;
    int actualSum = 0;

    vector<int> ans;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            actualSum += grid[i][j];

            if(s.find(grid[i][j])==s.end()) s.insert(grid[i][j]);
            else a = grid[i][j];
        }
    }
    int val = expectedSum - actualSum;

    b = a + val;

    ans.push_back(a);
    ans.push_back(b);

    return ans;
}

int main(){
    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> ans = findMissingAndRepeatedValues2(grid);

    cout<<"{";
    for(int val:ans){
        cout<<val<<",";
    }
    cout<<"}"<<endl;

    return 0;
}