//Maximum Product Subarray

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
int maxProduct1(vector<int>& arr, int n){
    int maxProduct=INT_MIN;
    for(int st=0; st<n; st++){
        int currProduct=1;
        for(int end=st; end<n; end++){
            currProduct *= arr[end];
            maxProduct=max(maxProduct, currProduct);
        }
    }
    return maxProduct;
}

//Optimal Solution using Kadane's Algorithm
int maxProduct2(vector<int>& arr, int n){
    int maxProduct=INT_MIN; 
    int currProduct=1;

    for(int i=0; i<n; i++){
        currProduct *= arr[i];
        maxProduct=max(maxProduct, currProduct);
        if(currProduct==0){
            currProduct=1;
        }
    }

    currProduct=1;
    for(int i=n-1; i>=0; i--){
        currProduct *= arr[i];
        maxProduct=max(maxProduct, currProduct);
        if(currProduct==0){
            currProduct=1;
        }
    }

    return maxProduct;
}

int main(){
    vector<int> arr={2, 3, -2, 4};
    int n=arr.size();

    cout<<"Max product in subarray: "<<maxProduct1(arr, n)<<endl;
    cout<<"Max product in subarray: "<<maxProduct2(arr, n)<<endl;
    return 0;
}