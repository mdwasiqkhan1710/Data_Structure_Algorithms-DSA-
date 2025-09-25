// Merge Two 2D Arrays by Summing Values

#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i=0, j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i][0] < nums2[j][0]){
                ans.push_back(nums1[i]);
                i++;
            }else if(nums1[i][0] > nums2[j][0]){
                ans.push_back(nums2[j]);
                j++;
            }else{
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }

        // Add remaining elements from nums1, if any.
        while (i < nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2, if any.
        while (j < nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }

// [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]

int main(){
    vector<vector<int>> nums1 = {{1,2}, {2,3}, {4,5}};
    vector<vector<int>> nums2 = {{1,4}, {3,2}, {4,1}};

    vector<vector<int>> ans = mergeArrays(nums1, nums2);

    for (auto& innerVec : ans) {
        cout << "[";
        for (size_t i = 0; i < innerVec.size(); i++) {
            cout << innerVec[i];
            if (i != innerVec.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}