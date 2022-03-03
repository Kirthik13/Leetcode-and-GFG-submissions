class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        if(v.size()<3) return 0;
        int c{},l{};
        for(int i=2;i<v.size();i++)
        {
            if(v[i]-v[i-1]!=v[i-1]-v[i-2])
            {
                c+=(l*(l+1))/2;
                l=0;
            }
            else{
                l++;
            }
        }
        if(l!=0)
        {
                    c+=(l*(l+1))/2;
   
        }
        return c;
    }
};