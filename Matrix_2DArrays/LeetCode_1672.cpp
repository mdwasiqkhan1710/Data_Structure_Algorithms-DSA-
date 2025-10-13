// Richest Customer Wealth

//You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

// A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

#include <iostream>
#include <vector>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
        int highest = INT_MIN; int rows=accounts.size(); int cols = accounts[0].size();

        for(int i=0; i<rows; i++){
            int currWealth = 0;
            for(int j=0; j<cols; j++) currWealth += accounts[i][j];
            if(currWealth > highest) highest = currWealth;
        }

        return highest;
}

int main(){
    vector<vector<int>> accounts = {{2,8,7},{7,1,3},{1,9,5}};

    int ans = maximumWealth(accounts);

    cout<<"Maximum wealth = "<<ans<<endl;

    return 0;
}