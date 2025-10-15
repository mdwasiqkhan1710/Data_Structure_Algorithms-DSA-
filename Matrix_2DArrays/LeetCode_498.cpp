//Diagonal Traverse

//Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

#include <iostream>
#include <vector>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int row = 0, col = 0;
        vector<int> ans(m * n);

        for (int i = 0; i < m * n; i++) {
            ans[i] = mat[row][col];
            // diagonally upward-right
            if ((row + col) % 2 == 0) {
                if (col == n - 1)
                    row++;
                else if (row == 0)
                    col++;
                else {
                    row--;
                    col++;
                }
            }
            // diagonally downward-left
            else {
                if (row == m - 1)
                    col++;
                else if (col == 0)
                    row++;
                else {
                    row++;
                    col--;
                }
            }
        }

        return ans;
}

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans = findDiagonalOrder(mat);

    cout<<"{";
    for(int val:ans){
        cout<<val<<",";
    }
    cout<<"}"<<endl;

    return 0;
}