// Search a 2D Matrix II

//Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int rowNum = 0, colNum = n-1;

        while(colNum>=0 && rowNum<m){
            if(target == matrix[rowNum][colNum]){
                return true;
            }else if(target < matrix[rowNum][colNum]){
                colNum--;
            }else {
                rowNum++;
            }
        }

        return false;
}

int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 12;

    bool ans = searchMatrix(matrix, target);

    cout<<"If target exist in matrix then output will be 1 else 0. \nOutput = "<<ans<<endl;
    return 0;
}