class Solution {
public:
        set<string>cont;
        queue<pair<string,int>>q;
    
    vector<char>v2={'A','C','G','T'};
    void fn(string &s,int mins)
    {
        
        for(int i=0;i<v2.size();i++)
        {
            for(int j=0;j<s.size();j++)
            {
                string t=s;
                s[j]=v2[i];
                if(cont.find(s)!=cont.end())
                {
                    q.push({s,mins+1});
                    cont.erase(s);
                }
                s=t;
            }
        }
        
        
    }
    int minMutation(string st, string en, vector<string>& v) {
        
        for(auto &i:v)
        {
            cont.insert(i);
        }
        q.push({st,0});
        
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto cur=q.front().first;
                auto mins=q.front().second;
                
                q.pop();
                
                
                if(cur==en) return mins;
                
                fn(cur,mins);
                
                
            }
        }
        
        return -1;
    }
    
};