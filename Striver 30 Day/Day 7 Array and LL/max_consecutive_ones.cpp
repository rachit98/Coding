class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int global_max = 0;
        int local_max = 0;
        for(auto i:nums)
        {
            if(i==1)
            {
                local_max++;
                global_max = max(local_max,global_max);
            }
            else
                local_max = 0;
        }
        return global_max;

    }
};