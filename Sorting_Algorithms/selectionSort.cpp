#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n){
    for(int i=0; i<n; i++){
        int smallestIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[smallestIdx]){
                swap(arr[j], arr[smallestIdx]);
            }
        }
    }
}

void printArray(vector<int> arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr={4, 1, 5, 2, 3};
    int n = arr.size();

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}