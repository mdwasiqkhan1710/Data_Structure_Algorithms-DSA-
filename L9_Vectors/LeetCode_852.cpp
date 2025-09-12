#include <iostream>
#include <vector>
using namespace std;

// Brute Force approach -- using linear searh
int peakIndex(vector<int>& arr){
    int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            if (i != 0 && i != n - 1) {
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    return i;
                }
            }

            if (i == 0 && arr[i] > arr[i + 1])
                return i;
            if (i == n - 1 && arr[i] > arr[i - 1])
                return i;
        }
        return -1;
}

// Optimal approach -- using Binary Search
int peakIndexBinary(vector<int>& arr){
    int st=0, end=arr.size()-1;

    while(st<=end){
        int mid=st+(end-st)/2;

        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;

        if(arr[mid]<arr[mid+1]){
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}


int main(){
    vector<int> nums={0, 2, 1, 0};
    cout<<"Index of peak element is: "<<peakIndex(nums)<<endl;
    cout<<"Index of peak element is: "<<peakIndexBinary(nums)<<endl;
    return 0;
}