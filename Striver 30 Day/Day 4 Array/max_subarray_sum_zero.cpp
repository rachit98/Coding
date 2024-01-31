class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int size = 0;
        for(int i=1;i<n;i++)
        {
            A[i] += A[i-1];
        }
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(A[i])!=mp.end())
            {
                size = max(size, i - mp[A[i]]);
            }
            else
                mp[A[i]] = i;
        }
        return size;
    }
};