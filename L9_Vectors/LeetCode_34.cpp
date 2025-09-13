//Find first and last position of the element in sorted array

#include <iostream>
#include <vector>
using namespace std;

//Brute Force
vector<int> searchRange1(vector<int>& nums, int target, int n){
    
    vector<int> ans;
    for(int i=0; i<n-1; i++){
        if(nums[i]==target){
            ans.push_back(i);
            ans.push_back(i+1);
            break;
        }
    }

    if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
    }

    return ans;
}

//Optimal Approach -- using Binary Search

int firstOccurence(vector<int>& nums, int target){
        int st=0, end=nums.size()-1;
        int firstIdx = -1;

        while(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target){
                firstIdx=mid;
                end=mid-1;
            }else if(nums[mid] < target){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return firstIdx;
    }

    int secondOccurence(vector<int>& nums, int target){
        int st=0, end=nums.size()-1;
        int secondIdx = -1;

        while(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target){
                secondIdx=mid;
                st=mid+1;
            }else if(nums[mid] < target){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return secondIdx;
    }

vector<int> searchRange2(vector<int>& nums, int target, int n){

        //Edge case where size of array is 0
        if(n==0) return {-1, -1};
        
        //Checking for first Occurence
        int first = firstOccurence(nums, target);
        //If there is no first index then surely there will be no last index thus returned {-1, -1}
        if (first == -1) return {-1, -1};


        int last = secondOccurence(nums, target);

        return {first, last};
}


int main(){
    vector<int> nums={5, 7, 7, 8, 8, 10};
    int target=8;
    int n = nums.size();

    vector<int> ans = searchRange2(nums, target, n);
    for(int val:ans){
        cout<<val<<", ";
    }
    return 0;
}
