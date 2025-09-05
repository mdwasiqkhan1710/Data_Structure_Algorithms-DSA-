// Writing the code to find the smallest and largest number in an array

#include <iostream>
using namespace std;

int smallestNum(int arr[], int n){
    int smallest = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }
    }
    return smallest;
}

int largestNum(int arr[], int n){
    int largest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}

int main(){
    int arr[5] = {99, 79, 53, 27, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Smallest value: "<<smallestNum(arr, n)<<endl;
    cout<<"Largest value: "<<largestNum(arr, n)<<endl;
    return 0;
}
