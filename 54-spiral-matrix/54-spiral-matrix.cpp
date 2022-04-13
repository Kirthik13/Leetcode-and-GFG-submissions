class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        int left=0,right=n-1,top=0,bot=m-1;
        vector<int>tot;
        while(left<=right and top<=bot)
        {
            for(int i=left;i<=right;i++)
            {
                tot.push_back(v[top][i]);
            }
            top++;
            
            for(int i=top;i<=bot;i++)
            {
                tot.push_back(v[i][right]);
            }
            right--;
                        if(left>right or top>bot) break;

            for(int i=right;i>=left;i--)
            {
                tot.push_back(v[bot][i]);
            }
            bot--;
            for(int i=bot;i>=top;i--)
            {
                 tot.push_back(v[i][left]);
            }
            left++;
        }
        return tot;
    }
};