#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int n){
    for(int i=0; i<n; i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
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

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}