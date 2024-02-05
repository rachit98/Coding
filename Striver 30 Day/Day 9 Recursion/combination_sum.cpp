class Solution {
public:
    void helper(vector<int> nums,int idx, int sum, int target, vector<int> curr, vector<vector<int>>& ans)
    {
        if(idx>=nums.size())
            return;
        if(sum>target)
            return;
        if(sum==target)
        {
            ans.push_back(curr);
            return;
        }
        helper(nums,idx + 1,sum,target, curr, ans);
        curr.push_back(nums[idx]);
        helper(nums,idx,sum + nums[idx], target, curr, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        helper(candidates,0,0,target,{},ans);
        return ans;
    }
};