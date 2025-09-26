// Remove Element

#include <iostream>
#include <vector>
using namespace std;

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

int main(){
    vector<int> nums = {3, 2, 2, 3};
    int val = 2;

    int ans = removeElement(nums, val);

    cout<<val<<endl;
    
    return 0;
}