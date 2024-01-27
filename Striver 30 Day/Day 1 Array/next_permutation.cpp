#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int new_max = -1;
        int new_max_index = -1;
        int size = nums.size();
        int old_max_index = -1;

        for(int i = size - 2; i>=0;i--)
        {
            for(int j = i+1; j<size;j++)
            {
                if (nums[i]<nums[j])
                {
                    if(nums[j]<new_max or new_max == -1)
                    {
                        new_max = nums[j];
                        new_max_index = j;
                        old_max_index = i;
                    }
                }
            }
            if(new_max_index!=-1)
                break;
        }
        if(new_max_index == -1)
            sort(nums.begin(), nums.end());

        else
        {
            swap(nums[old_max_index], nums[new_max_index]);
            sort(nums.begin() + old_max_index + 1,nums.end());
        }
        
    }
};

/*

Last from the last element of array, find the number just greater than it which is at a higher index.

Swap these two numbers and then sort the remaining (later part of array)
*/