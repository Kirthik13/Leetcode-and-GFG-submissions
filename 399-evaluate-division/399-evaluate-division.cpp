class Solution {
public:
    double dfs(string source,string dest, map<string,vector<pair<string,double>>>m,set<string>vis)
    {
                if(source==dest)
                {

                     return 1.0;
                }

                vis.insert(source);


               for(auto &i:m[source])
               {

                           if(vis.find(i.first)==vis.end())
                           {
                                double res=dfs(i.first,dest,m,vis);

                                if(res!=-1.0) return res*i.second;
                           }

               }

            // vis.erase(source);
            return -1.0;
    
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
        set<string>vis;        set<int>vi;

        for(int i=0;i<q.size();i++)
        {
            string new_f=q[i][0];
            string new_d=q[i][1];
            double ans=-1.0;
            if(m.find(new_f)!=m.end()){
            ans= dfs(new_f,new_d,m,vis);
            }
            tot.push_back(ans);

        }
        // fn(vi,0);
        return tot;
    }
};