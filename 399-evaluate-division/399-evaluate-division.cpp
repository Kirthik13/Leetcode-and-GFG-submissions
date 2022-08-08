class Solution {
public:
    void dfs(string source,string dest,unordered_set<string>vis,  map<string,vector<pair<string,double>>>&m,double &ans,double temp)
    {
         
                if(source==dest)
                {
                    ans=temp;
                    return;
                }
                vis.insert(source);

                for(auto &it:m[source])
                {
                    if(vis.find(it.first)==vis.end()){
                        dfs(it.first,dest,vis,m,ans,temp*it.second);
                    }
                }
        
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& vals, vector<vector<string>>& q) {
        
        map<string,vector<pair<string,double>>>m;
        for(int i=0;i<eq.size();i++)
        {
            string a=eq[i][0];
            string b=eq[i][1];
            
            m[a].push_back({b,vals[i]});
            m[b].push_back({a,1/vals[i]});
            
            
        }
        
        vector<double>totans;
        unordered_set<string>vis;
        for(int i=0;i<q.size();i++)
        {
            string source=q[i][0];
            string dest=q[i][1];
            
            double ans=-1.0;
            
            if(m.find(source)!=m.end())
            {
                dfs(source,dest,vis,m,ans,1.0);
            }
            totans.push_back(ans);
            
        }
        return totans;
        
    }
};