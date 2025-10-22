//Set Matrix Zeros

//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        unordered_set<int> rIdx;
        unordered_set<int> cIdx;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j]==0){
                    rIdx.insert(i);
                    cIdx.insert(j);
                }
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(rIdx.find(i) != rIdx.end()) matrix[i][j] = 0;
                if(cIdx.find(j) != cIdx.end()) matrix[i][j] = 0;
            }
        }

        return matrix;
}

int main(){
    vector<vector<int>> nums = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    vector<vector<int>> ans = setZeroes(nums);

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