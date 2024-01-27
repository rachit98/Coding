#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profits;
        profits.push_back(0);
        int sz = prices.size();

        for(int i=1;i<sz;i++)
        {
            profits.push_back(prices[i] - prices[i-1]);
        }

        int max_profit = INT_MIN;
        int sum = 0;
        for(int i=0;i<profits.size();i++)
        {
            sum += profits[i];
            max_profit = max(sum,max_profit);
            sum = max(0,sum);
        }
        return max_profit;
    }
};