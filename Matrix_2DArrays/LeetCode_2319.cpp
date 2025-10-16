//Check if Matrix is X-Matrix

//A square matrix is said to be an X-Matrix if both of the following conditions hold:

// All the elements in the diagonals of the matrix are non-zero.
// All other elements are 0.
// Given a 2D integer array grid of size n x n representing a square matrix, return true if grid is an X-Matrix. Otherwise, return false.

#include <iostream>
#include <vector>
using namespace std;

bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //Primary Diagonal Check
                if(i==j && grid[i][j] == 0) return false;

                //Secondary Diagonal Check
                if(j==n-i-1 && grid[i][j] == 0) return false;

                //Remaining elements check
                if(i!=j && j!=n-i-1 && grid[i][j]!=0) return false;
            }
        }
        return true;
}

int main(){
    vector<vector<int>> grid = {{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}};

    bool ans = checkXMatrix(grid);

    cout<<"If your matrix is X-Matrix then output will be 1 else 0.\nOutput : "<<ans<<endl;

    return 0;
}