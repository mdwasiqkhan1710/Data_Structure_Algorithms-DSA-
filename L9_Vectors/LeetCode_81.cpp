// Searh in rotated sorted array II

#include <iostream>
#include <vector>
using namespace std;

bool searchSortedArray(vector<int> nums, int target){
    int st=0, end=nums.size()-1;

    while(st<=end){
            int mid=st+(end-st)/2;
            
            if(nums[mid]==target) return true;
            
            //Edge case
            if(nums[st]==nums[mid] && nums[mid]==nums[end]){
                st++;
                end--;
            }else if(nums[st]<=nums[mid]){
                if(nums[st]<=target && target<nums[mid]){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }else {
                if(nums[mid]<target && target<=nums[end]){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return false;
}

int main(){
    vector<int> nums={2, 5, 6, 0, 0, 1, 2};
    int target=9;

    cout<<"If target is present answer will be true(1) & if not then false(0): "<<searchSortedArray(nums, target)<<endl;
    return 0;
}