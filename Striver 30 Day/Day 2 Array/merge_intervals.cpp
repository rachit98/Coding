#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[0] < vec2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        int sz = intervals.size();

        for(int i=1;i<sz;i++)
        {
            vector<int> last_interval = ans.back();
            vector<int> current_interval = intervals[i];

            if(current_interval[0]<=last_interval[1])
            {
                vector<int> temp;
                int first = min(current_interval[0], last_interval[0]);
                int last = max(current_interval[1], last_interval[1]);
                temp.push_back(first);
                temp.push_back(last);

                ans.pop_back();
                ans.push_back(temp);
            }
            else
            {
                ans.push_back(current_interval);
            }
        }
        return ans;
    }
};