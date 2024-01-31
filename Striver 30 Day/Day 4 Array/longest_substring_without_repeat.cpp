class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<2)
            return s.length();
        
        int start_pos = 0;
        unordered_map<char,int> mp;
        int max_length = 1;
        int curr_len = 0;

        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])==mp.end())
                mp[s[i]] = i;
            else if(mp[s[i]]<start_pos)
            {
                mp[s[i]] = i;
            }
            else
            {
                curr_len = i - start_pos;
                start_pos = mp[s[i]] + 1;
                mp[s[i]] = i;
                max_length = max(max_length, curr_len);
            }

        }
        curr_len = s.length() - start_pos;
        max_length = max(max_length, curr_len);

        return max_length;
    }
};