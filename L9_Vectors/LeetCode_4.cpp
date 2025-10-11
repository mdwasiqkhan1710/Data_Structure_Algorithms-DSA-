//Median of two sorted arrays

//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Brute force approach
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> sorted;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                sorted.push_back(nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                sorted.push_back(nums2[j]);
                j++;
            } else {
                sorted.push_back(nums1[i]);
                sorted.push_back(nums2[j]);
                i++;
                j++;
            }
        }

        while (i < m) {
            sorted.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            sorted.push_back(nums2[j]);
            j++;
        }

        if ((n + m) % 2 == 0) {
            int mid = (n + m) / 2;
            double ans = (sorted[mid] + sorted[mid-1]) / 2.0;
            return ans;
        } else {
            int mid = (n + m) / 2.0;
            double ans = sorted[mid];
            return ans;
        }

        return -1.0000;
}

//Optimized Space Complexity 
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(); int n2=nums2.size();
        int i=0; int j=0;
        
        int n = n1 + n2;
        int idx2 = n/2; int idx1 = idx2-1;

        int count = 0;
        int idxElement1 = -1; int idxElement2 = -1;

        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                if(count == idx1) idxElement1 = nums1[i];
                if(count == idx2) idxElement2 = nums1[i];
                count++;
                i++;
            }else if(nums1[i] > nums2[j]){
                if(count == idx1) idxElement1 = nums2[j];
                if(count == idx2) idxElement2 = nums2[j];
                count++;
                j++;
            }
        }

        while(i<n1){
            if(count == idx1) idxElement1 = nums1[i];
                if(count == idx2) idxElement2 = nums1[i];
                count++;
                i++;
        }

        while(j<n2){
            if(count == idx1) idxElement1 = nums2[j];
                if(count == idx2) idxElement2 = nums2[j];
                count++;
                j++;
        }

        if(n%2 == 1) return static_cast<double>(idxElement2);
        else {
            double ans = static_cast<double>(idxElement1) + static_cast<double>(idxElement2);
            return ans / 2.0;
        }
}

//Best Approach using Binary Search 
double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for optimization
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;  // Left partition size
        
        int left = 0, right = m;
        
        while (left <= right) {
            // Partition position in nums1
            int partition1 = (left + right) / 2;
            // Partition position in nums2 (depends on partition1)
            int partition2 = half - partition1;
            
            // Edge cases: if partition is at boundary
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            // Check if we found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Correct partition found
                if (total % 2 == 0) {
                    // Even total length: average of two middle elements
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    // Odd total length: maximum of left partition
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2) {
                // Too many elements from nums1 in left partition, move left
                right = partition1 - 1;
            }
            else {
                // Too few elements from nums1 in left partition, move right
                left = partition1 + 1;
            }
        }
        
        return 0.0;  // Should never reach here for valid inputs
}


int main(){
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {5,6,7};

    double ans = findMedianSortedArrays3(nums1, nums2);

    cout<<"Median of these two sorted arrays is : "<<ans<<endl;

    return 0;
}