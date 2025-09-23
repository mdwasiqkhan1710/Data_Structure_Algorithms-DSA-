#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
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

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}