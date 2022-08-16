class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size()==1) return 0;
        map<char,pair<int,int>>m;
        for(int i=0;i<s.size();i++)
        {
                if(m.find(s[i])!=m.end())
                {
                    auto p=m[s[i]];
                    p.second+=1;
                    p.first=i;
                    
                    m[s[i]]=p;
                    continue;
                    
                }
               m[s[i]]={i,1};
        }
        
        int curridx=INT_MAX;
        
        for(auto &i:m)
        {
            // cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
            if(i.second.second==1)
            {
                curridx=min(i.second.first,curridx);
                
            }
        }
        
        return curridx==INT_MAX?-1:curridx;
    }
};