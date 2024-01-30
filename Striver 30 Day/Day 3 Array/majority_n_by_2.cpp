class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr= nums[0];
        int counter = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==curr)
                counter++;
            else
            {
                if(counter==0)
                {
                    curr = nums[i];
                    counter = 1;
                }
                else
                    counter--;
            }
        }
        return curr;
    }
};