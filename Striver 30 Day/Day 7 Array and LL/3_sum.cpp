class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            if(i>0 and nums[i]==nums[i-1])
                continue;
            int j = i + 1;
            int k = sz -1;

            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k and nums[j-1]==nums[j])
                        j++;
                    while(k>j and nums[k+1]==nums[k])
                        k--;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
            

        }
        return ans;

    }
};