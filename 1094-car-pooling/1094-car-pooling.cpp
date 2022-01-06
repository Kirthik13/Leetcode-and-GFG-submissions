class Solution {
public:
    bool carPooling(vector<vector<int>>& v, int cap) {
     
     int dp[1000]={0};
    int f=0;
    for(auto i:v)
    {
        for(int j=i[1];j<i[2];j++)
        {
            dp[j]+=i[0];
            if(cap<dp[j])
            {
                return 0;
                // cout<<"false";
                // f=1;
                // break;
            }
        }

    }
    
    return 1;
    }
};