class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int cnt1[7]={0};
        int cnt2[7]={0};
        int same[7]={0};
        int n=t.size();
        for(int i=0;i<n;i++)
        {
            ++cnt1[t[i]];
            ++cnt2[b[i]];
            
            if(t[i]==b[i]) ++same[t[i]];
        }
        
        
        for(int i=1;i<=6;i++)
        {
            // cout<<" i : "<<i<<" cnt1[i] : "<<cnt1[i]<<" cnt2[i] : "<<cnt2[i]<<endl;
            if(cnt1[i]+cnt2[i]-same[i]==n)
            {
                return n-max(cnt1[i],cnt2[i]);
            }
        }
        return -1;
    }
};