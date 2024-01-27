class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size();
        int low = 0;
        int mid = 0;
        int high = sz - 1;

        while(mid<=high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
        
    }
};