int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    if(A.size()==0)
    return 0;
    map<int,int> mp;
    int xorr = 0;
    for(auto x:A)
    {
        xorr = xorr^x;
        if(xorr==B)
        count++;
        int tar = B ^ xorr;
        if(mp.find(tar)!=mp.end())
        {
            count+=mp[tar];
        }
        mp[xorr]+=1;
    }
    return count;
}