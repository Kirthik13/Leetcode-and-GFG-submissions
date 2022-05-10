class Solution {
public:
    void fn(int k,int sum,int curr_sum,int i,vector<int>present,vector<vector<int>>&ans)
    {
        if(sum<curr_sum) return;
        if(present.size()==k)
        {
               
            if(sum==curr_sum)
            {
                ans.push_back(present);
                
            }
            return;
        }
     
        for(int j=i;j<=9;j++){
            if(curr_sum+j<=sum){
                present.push_back(j);

                fn(k,sum,curr_sum+j,j+1,present,ans);
                present.pop_back();
            }
        }

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>present;
            vector<vector<int>>ans;

        fn(k,n,0,1,present,ans);
        return ans;
    }
};