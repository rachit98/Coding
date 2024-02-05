class Solution {
public:
    void helper(vector<int> nums, int idx,vector<int> curr, set<vector<int>>& store)
    {
        if(idx==nums.size())
        {
            
            store.insert(curr);
            return;
        }
        helper(nums, idx + 1, curr, store);
        curr.push_back(nums[idx]);
        helper(nums, idx + 1, curr, store);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> store;
        sort(nums.begin(),nums.end());
        helper(nums,0,{},store);
        vector<vector<int>> ans;
        for(auto st:store)
            ans.push_back(st);
        return ans;
    }
};