class Solution {
public:
    // vector<vector<int>>ans;
//     void fn(vector<int>v,int idx,int n)
//     {
//         if(idx==n-1)
//         {
//             ans.emplace_back(v);
//             return ;
//         }
     
        
//         for(int i=idx;i<n;i++)
//         {
//             if(v[i]==v[idx] and idx!=i)
//             {
//                 continue;
//             }
            
//             swap(v[idx],v[i]);
          
//             fn(v,idx+1,n);
            

            
//         }
//     }
    set<vector<int>>st;
    void fn1(vector<int>v,int idx,int n,vector<int>&tem,vector<int>&vis)
    {
        if(tem.size()==n)
        {
            st.insert(tem);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                tem.push_back(v[i]);
                fn1(v,i,n,tem,vis);
                vis[i]=0;
                tem.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& v) {
        int n=v.size();
        // fn(v,0,n);
        vector<int>tem;
        vector<int>vis(n,0);
        vector<vector<int>>ans;
        
        fn1(v,0,n,tem,vis);
        
        for(auto &i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};