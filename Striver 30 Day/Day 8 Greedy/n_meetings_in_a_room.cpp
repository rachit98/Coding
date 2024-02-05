static bool comp(vector<int> a, vector<int> b)
    {
        return a[1]<=b[1];
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int,int>> meets;
        for(int i=0;i<n;i++)
        {
            meets.push_back({start[i],end[i]});
        }
        sort(meets.begin(),meets.end(), comp);
        
        int count = 0;
        int curr_end = -1;
        for(auto m:meets)
        {
            if(m[0]>curr_end)
            {
                count++;
                curr_end = m[1];
            }
        }
        return count;
    }