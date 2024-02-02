class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        
        int k = nums.size();
        int sz = nums.size();
        int slow = 1;
        for(int i=1;i<sz;i++)
        {
            if(nums[i] == nums[i-1])
            {
                k--;
            }
            else
            {
                nums[slow] = nums[i];
                slow++;
            }
        }
        return k;
    }
};