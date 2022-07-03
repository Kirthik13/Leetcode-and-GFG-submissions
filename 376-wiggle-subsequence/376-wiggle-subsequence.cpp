class Solution {
public:
    int dp[1001][2];
    int f(vector<int>& nums, int  i, int positive){
        if(i==nums.size()-1) return  1;
        if(dp[i][positive]!=-1) return dp[i][positive];
        if(positive){
            if(nums[i+1] - nums[i]>0)
                return 1 + f(nums, i+1, 0);
            return f(nums, i+1, 1);
        }
        if(!positive  && nums[i+1]-nums[i]<0)
             return 1 + f(nums, i+1, 1);
        return f(nums, i+1 , 0);
    }
        int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1 , sizeof dp);
        return max(f(nums,0, 1), f(nums, 0, 0));
    }
   
};