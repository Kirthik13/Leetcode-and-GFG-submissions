class Solution {
public:
    vector<string>ans;
    unordered_map<string,int>m;
    void fn( vector<vector<char>>&adj,int i,string &digits,string tem)
    {
        if(i>=digits.size())
        {
            if(tem.size()>0)
            {
                if(m.find(tem)==m.end())
                {
                    ans.push_back(tem);
                    m[tem]++;
                }
            }
                
            return;
        }
        for(auto j:adj[int(digits[i])-48])
        {
            fn(adj,i+1,digits,tem+j);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<vector<char>>adj(10);
        adj[2]={'a','b','c'};
        adj[3]={'d','e','f'};
        adj[4]={'g','h','i'};
        adj[5]={'j','k','l'};
        adj[6]={'m','n','o'};
        adj[7]={'p','q','r','s'};
        adj[8]={'t','u','v'};
        adj[9]={'w','x','y','z'};
        fn(adj,0,digits,"");
        return ans;
    }
    
};