class Solution {
public:
    void dfs(string source,string dest, map<string,vector<pair<string,double>>>m,set<string>vis,double &ans,double tmp)
    {
        if(vis.find(source)!=vis.end()) return;
        else{
                vis.insert(source);
                if(source==dest)
                {
                    ans=tmp;    
                     return;
                }


               for(auto &i:m[source])
               {

                       dfs(i.first,dest,m,vis,ans,tmp*i.second);

               }
        }
    
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>>m;
        for(int i=0;i<eq.size();i++)
        {
            string f=eq[i][0];
            string d=eq[i][1];
            
            m[f].push_back({d,val[i]});
                m[d].push_back({f,1/val[i]});

        }
      
        vector<double>tot;
        set<string>vis;
        for(int i=0;i<q.size();i++)
        {
            string new_f=q[i][0];
            string new_d=q[i][1];
            double ans=-1.0;
            if(m.find(new_f)!=m.end()){
            dfs(new_f,new_d,m,vis,ans,1.0);
            }
            tot.push_back(ans);

        }
        return tot;
    }
};