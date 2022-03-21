class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        if(n==1) return {1};
            
        unordered_map<char,int>m;
        vector<int>tot;
        for(int i=0;i<n;i++)
        {
            m[s[i]]=i;
        }
        int i=0;
        while(i<n)
        {
            int st=i;
            int en=m[s[i]];
            int j=st+1;
            while(j<en)
            {
                if(m[s[j]]<=en)
                {
                    j++;
                }
                else{
                    en++;
                }
            }
            
           tot.push_back(en-st+1);
            i=en+1;
        }
        return tot;
    }
};