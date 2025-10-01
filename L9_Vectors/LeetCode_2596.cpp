//Find Common Elements Between Two Arrays


//You are given two integer arrays nums1 and nums2 of sizes n and m, respectively. Calculate the following values:
// answer1 : the number of indices i such that nums1[i] exists in nums2.
// answer2 : the number of indices i such that nums2[i] exists in nums1.
// Return [answer1,answer2].

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2){
    int n=nums1.size(); int m=nums2.size();
    int ans1=0, ans2=0;
    vector<int> result;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(nums1[i] == nums2[j]){
                ans1++;
                break;
            }
        }
    }

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(nums2[j]==nums1[i]){
                ans2++;
                break;
            }
        }
    }

    result.push_back(ans1);
    result.push_back(ans2);

    return result;
}

//Optimized Approach --- Using Hashing
vector<int> findIntersectionValues2(vector<int>& nums1, vector<int>& nums2){
    int n=nums1.size(), m=nums2.size();
    int ans1 = 0;
    int ans2 = 0;

    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    for(int i=0; i<n; i++){
        if(s2.find(nums1[i]) != s2.end()){
            ans1++;
        }
    }

    for(int i=0; i<m; i++){
        if(s1.find(nums2[i]) != s1.end()){
            ans2++;
        }
    }
    
    return {ans1, ans2};
}

int main(){
    vector<int> nums1={4,3,2,3,1};
    vector<int> nums2={2,2,5,2,3,6};

    vector<int> ans = findIntersectionValues(nums1, nums2);

    vector<int> ans2 = findIntersectionValues2(nums1, nums2);

    for(int val:ans2){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}