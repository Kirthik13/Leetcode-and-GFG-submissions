class Solution {
public:
    vector<vector<int>>ans;
    void fn(int k,int sum,int curr_sum,int i,vector<int>&present)
    {
        if(sum<curr_sum) return;
        if(present.size()==k)
        {
               // for(auto i:present)
               //  {
               //      cout<<i<<" ";
               //  }
               //  cout<<endl;
            if(sum==curr_sum)
            {
                ans.push_back(present);
                
            }
            return;
        }
     
        for(int j=i;j<=9;j++){
            if(curr_sum+j<=sum){
                present.push_back(j);

                fn(k,sum,curr_sum+j,j+1,present);
                present.pop_back();
            }
        }

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>present;
        fn(k,n,0,1,present);
        return ans;
    }
};