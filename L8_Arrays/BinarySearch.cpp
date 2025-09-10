// Binary Search Algorithm

#include <iostream>
#include<vector>
using namespace std;

// Iterative Approach 
// First initialize start with 0 and end with n-1, then find the mid and compare the mid value to target value
// If arr[mid] == target ---- we have got the answer thus we need to return the index of mid
// If arr[mid] > target --- then we need to search in first half of the array i.e; end = mid-1
// If arr[mid] < target --- then we need to search in second half of the array i.e; start = mid+1

int binarySearch(vector<int>& arr, int target){
    int n = arr.size();
    int st = 0, end = n-1;

    while(st<=end){
        int mid = st+(end-st)/2;

        if(arr[mid]>target){
            end = mid-1;
        }else if (arr[mid]<target){
            st = mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

// Recursion Code for Binary Search
int recursiveBinarySearch(vector<int> arr, int tar, int st, int end){
    if(st<=end){

        int mid = st+(end-st)/2;

        if(tar>arr[mid]){
            return recursiveBinarySearch(arr, tar, mid+1, end);
        }else if(tar<arr[mid]){
            return recursiveBinarySearch(arr, tar, st, end-1);
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
    int target = 3;
    int n = arr.size();

    cout<<"Target value is present at index: "<<recursiveBinarySearch(arr, target, 0, n-1)<<endl;

    return 0;
}

