// Merge Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Brute Force Approach, combine both arrays and then sort them. TC = O((m+n) log(m+n))
vector<int> mergedArray(vector<int>& nums1, vector<int>& nums2){
    for(int i=0; i<nums2.size(); i++){
        nums1.push_back(nums2[i]);
    }

    sort(nums1.begin(), nums1.end());

    return nums1;
}




int main(){
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 5, 6};

    vector<int> ans = mergedArray(nums1, nums2);
    
    for(int val:ans){
        cout<<val<<", ";
    }

    return 0;
}