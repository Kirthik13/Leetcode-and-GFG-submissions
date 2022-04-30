class Solution {
public:
    void dfs(string source,string dest, map<string,vector<pair<string,double>>>m,set<string>&vis,double &ans,double tmp)
    {
                if(source==dest)
                {
                    ans=tmp; 

                     return;
                }

                vis.insert(source);


               for(auto &i:m[source])
               {

                           if(vis.find(i.first)==vis.end())
                           {

                                dfs(i.first,dest,m,vis,ans,tmp*i.second);
                           }

               }

            vis.erase(source);
    
    }
//     void fn(set<int>&vis,int i)
//     {
//         if(i==3) return;
        
//         vis.insert(i);
//         for(auto &i:vis)
//         {
//            cout<<i<<" "; 
//         }
//         cout<<endl;
//         fn(vis,++i);
//          for(auto &i:vis)
//         {
//            cout<<i<<" "; 
//         }
//         cout<<endl;
//     }
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
            dfs(new_f,new_d,m,vis,ans,1.0);
            }
            tot.push_back(ans);

        }
        // fn(vi,0);
        return tot;
    }
};