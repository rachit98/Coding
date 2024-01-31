class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int maxlength = 0;
        int curr_length = 0;
        int prev = INT_MIN;
        for(int n: nums)
        {
            if (maxlength == 0)
            {
                maxlength = 1;
                curr_length = 1;
                prev = n;
                continue;
            }
            if (n==(prev+1))
            {
                prev = prev + 1;
                curr_length++;
            }
            else if(n==prev)
                continue;
            else
            {
                prev = n;
                curr_length = 1;
            }
            maxlength = max(maxlength, curr_length);
        }
        return maxlength;
    }
};