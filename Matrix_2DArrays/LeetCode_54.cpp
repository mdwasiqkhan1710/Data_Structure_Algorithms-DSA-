//Spiral Matrix

//Given an m x n matrix, return all elements of the matrix in spiral order.

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n=mat[0].size();
        int startRow = 0, endRow = m-1, startCol = 0, endCol = n-1;
        vector<int> ans;

        while(startRow<=endRow && startCol<=endCol){
            //Adding elements from top row to ans vector
            for(int j=startCol; j<=endCol; j++){
                ans.push_back(mat[startRow][j]);
            }

            //Adding elements from right col to ans vector
            for(int i=startRow+1; i<=endRow; i++){
                ans.push_back(mat[i][endCol]);
            }

            //Adding elements from bottom row to ans vector
            for(int j=endCol-1; j>=startCol; j--){
                if(startRow == endRow){
                    break;
                }
                ans.push_back(mat[endRow][j]);
            }

            //Adding elements from left col to ans vector
            for(int i=endRow-1; i>=startRow+1; i--){
                if(startCol == endCol){
                    break;
                }
                ans.push_back(mat[i][startCol]);
            }

            startRow++; endRow--; startCol++; endCol--;
        }

        return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    vector<int> result = spiralOrder(matrix);

    cout<<"{";
    for(int val:result){
        cout<<val<<",";
    }
    cout<<"}"<<endl;

    return 0;
}