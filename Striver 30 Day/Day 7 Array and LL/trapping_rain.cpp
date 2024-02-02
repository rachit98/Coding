class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        vector<int> prefix_max,suffix_max;
        int pre_max = INT_MIN, suf_max = INT_MIN;
        for(int i=0;i<sz;i++)
        {
            prefix_max.push_back(pre_max);
            pre_max = max(pre_max,height[i]);
        }

        for(int i=sz-1;i>=0;i--)
        {
            suffix_max.push_back(suf_max);
            suf_max = max(suf_max,height[i]);
        }

        int water = 0;
        for(int i=0;i<sz;i++)
        {
            
            int level = min(prefix_max[i],suffix_max[sz-i-1]);
            if(level<height[i])
                continue;
            water += level - height[i];
            
        }
        return water;        
    }
};