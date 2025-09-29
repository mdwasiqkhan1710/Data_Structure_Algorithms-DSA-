// Remove Element

#include <iostream>
#include <vector>
using namespace std;

//Brute Force approach
int removeElement(vector<int>& nums, int val) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                count++;
            }
        }

        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == val) {
                it = nums.erase(it); // Erase returns the next iterator
            } else {
                ++it; // Only increment if no erase
            }
        }

        return count;
}

//Optimized approach
int removeElement2(vector<int>& nums, int val) {
        int count = 0;
        int n=nums.size();
        int k=0;

        for(int i=0; i<n; i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
}

int main(){
    vector<int> nums = {3, 2, 2, 3};
    int val = 2;

    int ans = removeElement2(nums, val);

    cout<<val<<endl;
    
    return 0;
}