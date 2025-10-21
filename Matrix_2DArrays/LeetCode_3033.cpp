//Modify the Array

//Given a 0-indexed m x n integer matrix matrix, create a new 0-indexed matrix called answer. Make answer equal to matrix, then replace each element with the value -1 with the maximum element in its respective column.
// Return the matrix answer.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> modifyArray(vector<vector<int>>& nums){
    int rows = nums.size();
    int cols = nums[0].size();

    for(int j=0; j<cols; j++){
        int maxVal = -1;
        for(int i=0; i<rows; i++){
            if(nums[i][j] != -1) maxVal = max(maxVal, nums[i][j]);
        }

        for(int i=0; i<rows; i++){
            if(nums[i][j]==-1) nums[i][j] = maxVal;
        }
    }

    return nums;
}

int main(){
    vector<vector<int>> nums = {{1,2,-1},{4,-1,6},{7,8,9}};
    vector<vector<int>> ans = modifyArray(nums);

    cout<<"{";
    for(int i=0; i<ans.size(); i++){
        cout<<"{";
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j];
            if(j!=ans[0].size()-1) cout<<", ";
            if(j==ans[0].size()-1) cout<<"}";   
        }
        if(i!=ans.size()-1) cout<<",";
    }
    cout<<"}";

    return 0;
}