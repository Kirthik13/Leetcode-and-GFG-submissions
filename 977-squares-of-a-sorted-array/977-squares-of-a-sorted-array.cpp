class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        int n=v.size();
        vector<int>tot(n);
        int i=n-1,l{},r=n-1;
        while(l<=r)
        {
            if(abs(v[r])>abs(v[l]))
            {
                tot[i]=pow(v[r],2);
                r--;
            }
            else{
                tot[i]=pow(v[l],2);
                l++;
            }
            i--;
        }
        return tot;
    }
};