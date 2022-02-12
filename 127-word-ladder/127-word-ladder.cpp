class Solution {
public:
    int bfs(string &s1,string &s2,unordered_set<string> &st)
    {
        queue<string>q;
        q.push(s1);
        int ans{};
        while(!q.empty())
        {
            int n=q.size();
            ans++;
            while(n--)
            {
                string cur=q.front();
                q.pop();
                for(int i=0;i<cur.size();i++)
                {
                    string tem=cur;
                    for(int j=97;j<=122;j++)
                    {
                        tem[i]=(char)j;
                        if(tem==s2) return ans+1;
                        
                        if(tem==cur) continue;
                        
                        if(st.count(tem))
                        {
                            st.erase(tem);
                            q.push(tem);
                        }
                        
                    }
                }
            }
                
        }
        return 0;
            
    }
    int ladderLength(string s1, string s2, vector<string>& v) {
       unordered_set<string>st;
        for(auto &i:v)
        {
            st.insert(i);
        }
        if(st.find(s2)==st.end()) return 0;
        return bfs(s1,s2,st);
    }
};