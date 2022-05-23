class Solution {
public:
    int ans=INT_MIN;
  int dp[601][101][101];
    int fn(vector<string>& v, int &max_0, int &max_1, unordered_map<int,pair<int,int>>&m,int i,int curr_z,int curr_one,int st)
    {
        if(curr_z>max_0 or curr_one>max_1) return -1;
        
        if(i>=v.size())
        {
               if(curr_z<=max_0 and curr_one<=max_1)
               {
                   int siz=st;
                   ans=max(ans,siz);
               }
            return 0;
        }
        // if(dp.find({i,{curr_z,curr_one}})!=dp.end()) return   dp[{i,{curr_z,curr_one}}];
        if(dp[i][curr_z][curr_one]!=-1) return dp[i][curr_z][curr_one];
        // st++;
        int l=1+fn(v,max_0,max_1,m,i+1,curr_z+m[i].first,curr_one+m[i].second,st);
        // if(st>0){
        // st--;
        // }
        int r=fn(v,max_0,max_1,m,i+1,curr_z,curr_one,st);
        
       return dp[i][curr_z][curr_one]=max(l,r);

        
    }
    int findMaxForm(vector<string>& v, int max_0, int max_1) {
        unordered_map<int,pair<int,int>>m;
        for(int i=0;i<v.size();i++)
        {
            int z{},o{};
            for(auto &j:v[i])
            {
                if(j=='0') z++;
                else{ 
                    o++;
                }
            }
            m[i]={z,o};
        }
        // vector<string>st;
        int st{};
        memset(dp,-1,sizeof(dp));
        int g=fn(v,max_0,max_1,m,0,0,0,st);
        return g;
    }
};