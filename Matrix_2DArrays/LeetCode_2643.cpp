//Row With Maximum Ones

//Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.
// In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.
// Return an array containing the index of the row, and the number of ones in it.

#include <iostream>
#include <vector>
using namespace std;

//Brute force approach
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        int finalCount = 0;
        int finalIdx = 0;

        for (int i = 0; i < m; i++) {
            int currCount = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    currCount++;
            }
            if (currCount > finalCount) {
                finalCount = currCount;
                finalIdx = i;
            }
        }
        ans.push_back(finalIdx);
        ans.push_back(finalCount);

        return ans;
}

int main(){
    vector<vector<int>> mat = {{0,0},{1,1},{0,0}};

    vector<int> ans = rowAndMaximumOnes(mat);

    cout<<"{";
    for(int val : ans){
        cout<<val<<",";
    }
    cout<<"}"<<endl;

    return 0;
}