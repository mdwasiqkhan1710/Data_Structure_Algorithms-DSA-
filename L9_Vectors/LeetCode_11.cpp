// Conatiner with maximum water

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force approach -- Calculating water each container can hold and then returning the max value possible.
int maxWater1(vector<int>& height){
    int n = height.size();
    int ans=0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int maxHeight = min(height[i], height[j]);
            int width = j-i;
            int area = maxHeight * width;
            ans = max(ans, area);
        }
    }

    return ans;
}

//Optimal Solution -- Using two pointer Approach
int maxWater2(vector<int>& height){
    int maxWater=0;
    int hgt=0, wdt=0;
    int st=0, end=height.size()-1;

    while(st<end){
        hgt=min(height[st], height[end]);
        wdt=end-st;
        int area = hgt*wdt;

        maxWater=max(maxWater, area);
        height[st]<height[end] ? st++ : end--;
    }
    return maxWater;
}

int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int ans1 = maxWater1(height);
    cout<<"Max water: "<<ans1<<endl;

    int ans2 = maxWater2(height);
    cout<<"Max water: "<<ans2<<endl;
    
    return 0;
}