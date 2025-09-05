#include <iostream>
using namespace std;

//Linear Search -- Running the loop through complete array, and if target is found then returning the index value.

int linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            return i;
        }
    }

    return -1; //If target value is not found
}

int main(){
    int arr[7]={4, 2, 7, 8, 1, 2, 5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target=5;

    cout<<"Target value is found at index: "<<linearSearch(arr, size, target)<<endl;

    return 0;
}