class Solution {
public:
     // if (k == 1) // if k == 1 then we found all subsets
//             return true;
        
//         if (curr_sum == target) // we found one subset, go on to the next one starting from curr_sum = 0
//             return backtrack(matchsticks, visited, target, 0, 0, k-1);
        
//         for (int j = i; j < matchsticks.size(); j++) {
//             if (visited[j] || curr_sum + matchsticks[j] > target) continue; // if we visited this index already or curr_sum + matchsticks[j] > target then we can't use it
            
//             visited[j] = true;
//             if (backtrack(matchsticks, visited, target, curr_sum + matchsticks[j], j+1, k)) return true;
//             visited[j] = false;
//         }
        
//         return false;
    bool fn(vector<int>& v,int idx,int n,int currsum,int target,int nos,vector<int>&vis)
    {
        if(nos==1) return 1;
        if(currsum==target)
        {
            return fn(v,0,n,0,target,nos-1,vis);
            

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
       
        return fn(v,0,n,0,target,4,vis);

     
    }
};