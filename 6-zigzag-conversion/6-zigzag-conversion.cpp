class Solution {
public:
    string convert(string s, int n) {
        map<int,vector<char>>m;
        
        int idx=0,f=1;
        for(int i=0;i<s.size();i++)
        {
            m[idx].push_back(s[i]);
            if(idx==n-1)
            {
                f=0;
            }
            if(idx==0) f=1;
            if(f)
            {
                idx++;
            }
            else{
                idx--;
            }
        }
        
        string ans;
        for(auto &i:m)
        {
            // cout<<i.first<<" --> ";
            for(auto &j:i.second)
            {
                ans.push_back(j);
                // cout<<j<<" ";
                
            }
            // cout<<endl;
        }
        return ans;
        
    }
};