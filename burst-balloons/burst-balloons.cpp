class Solution {
public:
    int maxCoins(vector<int>& v) {
        vector<vector<int>>dp(v.size(),vector<int>(v.size()));
        
        for(int g=0;g<dp.size();g++)
        {
            for(int i=0,j=g;j<dp.size();i++,j++)
            {
                int max=INT_MIN;
                
                for(int k=i;k<=j;k++)
                {
                    int left=(k==i)?0:dp[i][k-1];
                    int right=(k==j)?0:dp[k+1][j];
                    int val=((i==0)?1:v[i-1])*v[k]*((j==v.size()-1)?1:v[j+1]);
                    
                    int total=left+val+right;
                    if(total>max)
                    {
                        max=total;
                    }

                }
                dp[i][j]=max;
            }
        }
        return dp[0][dp.size()-1];
    }
};