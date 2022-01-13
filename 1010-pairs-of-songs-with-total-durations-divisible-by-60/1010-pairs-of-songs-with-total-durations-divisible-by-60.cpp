class Solution {
public:
    // void mergesort()
    int numPairsDivisibleBy60(vector<int>& v) {
        int n=v.size();
          unordered_map<int,int>m;
    int c=0;
    for(int i=0;i<n;i++)
    {
        int a=v[i]%60;
        if(a==0)
        {
            c+=m[0];
        }
        else{
            c+=m[(60-a)%60];
        
        }
        m[a]++;
    }
        return c;
    }
};