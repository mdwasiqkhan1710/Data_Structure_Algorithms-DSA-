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

vector<int> mergedArray2(vector<int>& nums1, vector<int>& nums2){
    int i=0, j=0;
    vector<int> ans;
    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i]>nums2[j]){
            ans.push_back(nums2[j]);
            j++;
        }else if (nums1[i]<nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }else if (nums1[i] == nums2[j]){
            ans.push_back(nums2[j]);
            ans.push_back(nums1[i]);
            j++;
            i++;
        }
    }

    while(i < nums1.size()){
        ans.push_back(nums1[i]);
        i++;
    }
    
    // Add remaining elements from nums2
    while(j < nums2.size()){
        ans.push_back(nums2[j]);
        j++;
    }

    ans.erase(remove(ans.begin(), ans.end(), 0), ans.end());

    return ans;
}

//Optimal Approcach 
vector<int> mergedArrayOptimalApprocah(vector<int>& nums1, vector<int>& nums2, int m, int n){
    int idx = m+n-1;
    int i = m-1;
    int j = n-1;

    while(i >= 0 && j >= 0){
        if(nums1[i]>=nums2[j]){
            nums1[idx] = nums1[i];
            idx--;
            i--;
        }else{
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }

    while(j>=0){
        nums1[idx] = nums2[j];
        idx--;
        j--;
    }

    nums1.erase(remove(nums1.begin(), nums1.end(), 0), nums1.end());

    return nums1;
}

int main(){
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = nums2.size();
    vector<int> ans = mergedArrayOptimalApprocah(nums1, nums2, m, n);
    
    for(int val:ans){
        cout<<val<<", ";
    }

    return 0;
}