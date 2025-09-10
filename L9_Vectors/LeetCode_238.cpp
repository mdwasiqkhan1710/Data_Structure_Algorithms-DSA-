#include <iostream>
#include <vector>
using namespace std;

//Brute Force Approach
vector<int> productExceptSelf1(vector<int>& nums, int n){

    vector<int> ans(n, 1);

    for(int i=0; i<n; i++){
        int prod = 1;
        for(int j=0; j<n; j++){
            if(i!=j){
                prod *= nums[j];
            }
        }
        ans[i]=prod;
    }
    return ans;
}


// Optimal Approach
vector<int> productExceptSelf2(vector<int>& nums, int n){
    vector<int> ans(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    for(int i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    for(int i=0; i<n; i++){
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

int main(){
    vector<int> nums={1, 2, 3, 4};
    int n = nums.size();
    // vector<int> ans1 = productExceptSelf1(nums, n);

    vector<int> ans2 = productExceptSelf2(nums, n);

    for(int val:ans2){
        cout<<val<<", ";
    }
    cout<<endl;

    return 0;
}