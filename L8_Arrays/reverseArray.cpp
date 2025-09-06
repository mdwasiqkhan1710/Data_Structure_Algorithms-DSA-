#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr, int size){
    int start = 0, end = size-1;

    while(start<end){
        swap(arr[start], arr[end]);
        start++; end--;
    }
}

int main(){
    vector<int> arr={4, 2, 7, 8, 1, 2};
    int size = 6;

    reverseArray(arr, size);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<", ";
    }
    return 0;    
}