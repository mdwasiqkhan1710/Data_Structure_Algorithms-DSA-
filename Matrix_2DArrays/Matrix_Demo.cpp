//Matrix Basic Understanding

#include <iostream>
#include <vector>
using namespace std;

//Linear Search on 2D Array
pair<int, int> linearSearch(vector<vector<int>>& arr, int target){
    int rows= arr.size();
    int cols= arr[0].size();

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(arr[i][j]==target){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

//Maximum Row Sum
int maxSum(vector<vector<int>>& arr){
    int rows = arr.size();
    int cols = arr[0].size();

    int maxSum = INT_MIN;

    for(int i=0; i<rows; i++){
        int currSum = 0;
        for(int j=0; j<cols; j++){
            currSum += arr[i][j];
        }
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

//Diagonal Sum
int diagonalSum(vector<vector<int>>& arr){

    //Here the matrix will always be square matrix meaning that rows = cols
    int rows = arr.size();
    int cols = arr[0].size();
    int diaSum = 0;
    int n = cols;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(i==j) diaSum += arr[i][j];
            else if (j==n-i-1) diaSum += arr[i][j];
        }
    }

    return diaSum;
}

int main(){
    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
    int tar=11;

    // pair<int, int> ans = linearSearch(arr, tar);
    // cout<<"Target value is present in cell : {"<<ans.first<<", "<<ans.second<<"}"<<endl;

    // int highestSum = maxSum(arr);
    // cout<<"Max Sum = "<<highestSum<<endl;

    int sumDiagonal = diagonalSum(arr);
    cout<<"Sum of the Diagonal = "<<sumDiagonal<<endl;

    return 0;
}