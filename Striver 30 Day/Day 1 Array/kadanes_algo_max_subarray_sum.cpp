#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum = 0;
        int sz = nums.size();

        for(int i=0;i<sz;i++)
        {
            sum += nums[i];
            max_sum = max(max_sum, sum);
            sum = max(sum,0);
        }
        return max_sum;
    }
};