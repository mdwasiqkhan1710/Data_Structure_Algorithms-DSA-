// Best Time to Buy and Sell Stock Problem 

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
int maxProfit1(vector<int>& prices, int n){
    int maxProfit = INT_MIN;

    for(int i=0; i<n; i++){
        int currProfit=0;
        for(int j=i+1; j<n; j++){
            currProfit = prices[j] - prices[i];
            maxProfit = max(currProfit, maxProfit);
        }
    }
    if(maxProfit<0) return 0;
    return maxProfit;
}

// Optimal Approach 
int maxProfit2(vector<int>& prices, int n){
    int maxProfit=0;
    int bestBuy=prices[0];

    for(int i=1; i<n; i++){
        if(prices[i]>bestBuy){
            maxProfit = max(maxProfit, prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();

    int ans1=maxProfit1(prices, n);
    int ans2=maxProfit2(prices, n);
    cout<<"Maximum Profit seller can get is: "<<ans1<<endl;
    cout<<"Maximum Profit seller can get is: "<<ans2<<endl;
    return 0;
}