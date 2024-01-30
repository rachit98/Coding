class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first = INT_MIN;
        int second = INT_MIN;
        int count_first = 0;
        int count_second = 0;
        int sz = nums.size();

        for(int i=0;i<sz;i++)
        {
            if(nums[i]==first)
            {
                count_first++;
            }
            else if(nums[i]==second)
            {
                count_second++;
            }
            else if(count_first==0)
            {
                first = nums[i];
                count_first++;
            }
            else if(count_second==0)
            {
                second = nums[i];
                count_second++;
            }
            else
            {
                count_first--;
                count_second--;
            }
        }

        vector<int> major_elements;
        count_first = 0;
        count_second = 0;
        for(int i:nums)
        {
            if (i==first)
                count_first++;
            if (i==second)
                count_second++;
        }
        int min_count = sz/3 + 1;
        if (count_first>=min_count)
            major_elements.push_back(first);
        if (count_second>=min_count)
            major_elements.push_back(second);
        
        return major_elements;
    }
};