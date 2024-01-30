#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        
        if(m==0)
        {
            for(int i=0;i<n;i++)
            {
                nums1[i] = nums2[i];
            }
            return;
        }

        int curr = m + n - 1;
        int first = m - 1;
        int second = n - 1;

        while(first>=0 and second >=0)
        {
            if(nums1[first]>=nums2[second])
            {
                nums1[curr] = nums1[first];
                first--;
                curr--;
            }

            else
            {
                nums1[curr] = nums2[second];
                second--;
                curr--;
            }
        }

        while(second>=0)
        {
            nums1[curr] = nums2[second];
            curr--;
            second--;
        }        

    }
};