class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> first;
        first.push_back(1);
        ans.push_back(first);

        if (numRows == 1)
            return ans;
        
        vector<int> second{1,1};
        ans.push_back(second);

        if(numRows == 2)
            return ans;
        
        for(int i =2; i<numRows;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            vector<int> last = ans.back();
            int sz = last.size();
            for(int j = 1; j<sz;j++)
            {
                temp.push_back(last[j] + last[j-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};