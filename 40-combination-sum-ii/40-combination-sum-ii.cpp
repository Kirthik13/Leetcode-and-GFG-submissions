class Solution {
public:
    vector<vector<int>>st;
    void fn(vector<int>& v,int idx,int n, int target,vector<int>&temp,int sum)
    {
          if(sum==target)
          {
              st.push_back(temp);
              return;
          }
        if(idx>=n)
        {
            if(sum==target) st.push_back(temp);
            return ;
        }
        
        for(int i=idx;i<v.size();i++)
        {
            if(i!=idx and v[i]==v[i-1]) continue;
            
            if(sum+v[idx]<=target)
            {   
                temp.push_back(v[i]);
                fn(v,i+1,n,target,temp,sum+v[i]);
                if(temp.size()>0)temp.pop_back();

            }
            // fn(v,idx+1,n,target,temp,sum);
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(begin(v),end(v));
        vector<int>temp;
        int n=v.size();
        fn(v,0,n,target,temp,0);
        // vector<vector<int>>curr(begin(st),end(st));
        return st;
    }
};