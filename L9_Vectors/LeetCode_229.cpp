//Majority Element II

#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums, int n) {
        int count1=0, count2=0, ele1=0, ele2=1;
        

        for(int i=0; i<n; i++){
            if(ele1==nums[i]) count1++;
            else if(ele2==nums[i]) count2++;
            else if(count1==0){
                ele1=nums[i];
                count1=1;
            }else if(count2==0){
                ele2=nums[i];
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
            
            count1=0, count2=0;
            for(int i=0; i<n; i++){
                if(nums[i]==ele1) count1++;
                else if(nums[i]==ele2) count2++;
            }

            vector<int> ans;
            if(count1>n/3) ans.push_back(ele1);
            if(count2>n/3) ans.push_back(ele2);

            return ans;
        }

int main(){
    vector<int> nums={1,2};
    int n=nums.size();
    vector<int> ans=majorityElement(nums, n);

    for(int val:ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}