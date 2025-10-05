//Unique Number of Occurrences

//Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool uniqueOccurrences(vector<int>& arr){

    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<int> freq;
    int count = 1;
    int curr = arr[0];

    for(int i=1; i<n-1; i++){
        if(arr[i] == curr){
            count++;
        }else{
            freq.push_back(count);
            count=0;
            curr=arr[i];
        }
    }

    int m = freq.size();

    int lastCount = freq[m-1];

    if(arr[n-1] == arr[n-2]){
        lastCount++;
        freq[m-1] = lastCount;
    }else{
        freq.push_back(1);
    }

    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            if(freq[i] == freq[j]) return false;
        }
    }

    return true;
}

int main(){
    vector<int> arr={1,2,2,1,1,3};

    bool ans = uniqueOccurrences(arr);

    cout<<"For true output will be 1 and for false output will be 0 : "<<ans<<endl;

    return 0;
}