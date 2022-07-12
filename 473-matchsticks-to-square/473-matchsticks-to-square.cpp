class Solution {
public:

    bool fn(vector<int>& v,int idx,int n,int currsum,int target,int nos,vector<int>&vis)
    {
        if(nos==3) return 1;
        
        if(currsum==target)
        {
            return fn(v,0,n,0,target,nos+1,vis);
            

        }
      
        
        for(int i=idx;i<v.size();i++)
        {
            if(vis[i] or currsum+v[i]>target) continue;
            
            vis[i]=1;
            if(fn(v,i+1,n,currsum+v[i],target,nos,vis)) return 1;
            vis[i]=0;
        }
        return 0;
        
        
    }
    bool makesquare(vector<int>& v) {
        int n=v.size();
        
        int totsum=accumulate(begin(v),end(v),0);
       
        if(totsum%4!=0) return 0;
        
        int target=totsum/4;
        
        // int maxi=*max_element(begin(v),end(v));
        
        // if(maxi>target) return 0;
        
        vector<int> vis(n,0);
       
        return fn(v,0,n,0,target,0,vis);

     
    }
};