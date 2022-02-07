class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>st;
        char c;
        for(auto &i:t)
        {
            st[i]++;
        }
        for(auto &i:s)
        {
            if(st[i]>0)
            {
                st[i]--;
            }
        }
        for(auto &i:st)
        {
            if(i.second==1)
            {
                c=i.first;
                break;
            }
        }
        return c;
    }
};