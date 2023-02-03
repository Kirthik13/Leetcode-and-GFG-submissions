class Solution {
public:
    string convert(string s, int n) {
        
        int idx{},f=1;
        map<int,vector<char>>m;
        for(int i=0;i<s.size();i++)
        {
            m[idx].push_back(s[i]);
             if(idx==n-1)
            {
                f=0;
            }
            if(idx==0)
            {
                f=1;
            }
           
            
            if(f) idx++;
            else idx--;
            
        }
        
        string res;
        for(auto &i:m)
        {
            for(auto &j:i.second)
            {
                res.push_back(j);
            }
        }
        
        return res;
    }
};