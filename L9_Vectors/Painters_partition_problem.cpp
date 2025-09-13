// Painters Partition Problem -- Geeks for Geeks

// Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

// Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime){
        int painters=1, currtime=0;
        
        for(int i=0; i<n; i++){
            if(currtime+arr[i]<=maxAllowedTime){
                currtime += arr[i];
            }else{
                painters++;
                currtime=arr[i];
            }
        }
        
        return painters <= m ? true : false;
    }

int minTime(vector<int>& arr, int n, int m){
        int maxVal=INT_MIN;
        int sumArr=0;
        
        //Calculating max value in the array
        for(int i=0; i<n; i++){
            if(arr[i]>maxVal){
                maxVal=arr[i];
            }
        }
        
        //Calculating the sum of all elements of the array
        for(int i=0; i<n; i++){
            sumArr += arr[i];
        }
        
        int st=maxVal; int end=sumArr;
        int ans=-1;
        
        while(st<=end){
            int mid=st+(end-st)/2;
            
            if(isValid(arr, n, m, mid)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        
        return ans;
}

int main(){
    vector<int> arr={5, 10, 30, 20, 15};
    int m = 4; 
    int n = arr.size();

    cout<<"Minimum amount of time required to paint: "<<minTime(arr, m, n)<<endl;
    return 0;
}