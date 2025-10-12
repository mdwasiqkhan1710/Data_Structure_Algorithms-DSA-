//Search a 2D Matrix

//You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

#include <iostream>
#include <vector> 
using namespace std;

//Brute force approach
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
}

//Optimized Approach - Binary search 
bool searchInRow(vector<vector<int>>& matrix, int target, int row){
        int n=matrix[0].size();
        int st = 0, end = n-1;

        //Applying Binary search on the selected row to find the ans
        while(st<=end){
            int mid=st+(end-st)/2;

            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) st = mid + 1;
            else end = mid - 1;
        }

        return false;
}

bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        //Binary Search on all rows to find correct row where target exists
        int m=matrix.size(); int n=matrix[0].size();
        int stRow = 0, endRow = m-1;

        while(stRow<=endRow){
            int midRow = stRow + (endRow-stRow)/2;

            if(target>=matrix[midRow][0] && target<=matrix[midRow][n-1]){
                //Desired row is found now apply Binary search on this row to find the target
                return searchInRow(matrix, target, midRow);
            }else if (target>=matrix[midRow][n-1]){
                //Target is greater than last ele of mid row thus search in lower row
                stRow = midRow+1;
            }else{
                //Target is smaller than first ele of mid row thus search in upper row
                endRow = midRow-1;
            }
        }
        return false;
}

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;

    bool ans = searchMatrix2(matrix, target);

    cout<<"If target value is found then output will be 1 else 0.\nOutput = "<<ans<<endl;

    return 0;
}