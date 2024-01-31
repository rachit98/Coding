class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> store;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int low = j+1;
                int high = nums.size() - 1;
                long long new_sum = (long long)(target) - (long long)(nums[i]) -  (long long)(nums[j]);
            
                while(low<high)
                {
                    long long total = nums[low] + nums[high];
                    if (total == new_sum)
                    {
                        store.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                    }
                    else if (total > new_sum)
                        high--;
                    else
                        low++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto v:store)
        {
            ans.push_back(v);
        }
        return ans;
    }
};