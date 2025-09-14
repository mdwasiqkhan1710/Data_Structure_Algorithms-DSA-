//Geeks for Geeks

// You are given an array with unique elements of stalls[], which denote the positions of stalls. 
// You are also given an integer k which denotes the number of aggressive cows. 
// The task is to assign stalls to k cows such that the minimum 
// distance between any two of them is the maximum possible.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& arr, int N, int C,int mid){
    int cowsCount=1, lastStallPos=arr[0];

    for(int i=1; i<N; i++){
        if((arr[i]-lastStallPos)>=mid){
            cowsCount++;
            lastStallPos=arr[i];
        }

        if(cowsCount==C){
            return true;
        }
    }

    return false;
}

int getDistance(vector<int>& arr, int N, int C){

    sort(arr.begin(), arr.end());
    int minOfArr=arr[0];
    int maxofArr=arr[N-1];

    //Binary search code
    int st=1, end=maxofArr-minOfArr;
    int ans=-1;

    while(st<=end){
        int mid=st+(end-st)/2;

        if(isPossible(arr, N, C, mid)){
            ans=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={1, 2, 8, 4, 9};
    int C = 3;
    int N = arr.size();

    cout<<getDistance(arr, N, C)<<endl;
    return 0;
}