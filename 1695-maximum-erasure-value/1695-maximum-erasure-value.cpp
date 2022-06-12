class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        unordered_map<int,int>m;
        int sum{},ans{};
        int n=v.size();
        vector<int>pre(n);
        pre[0]=v[0];
        for(int i=1;i<v.size();i++)
        {
            pre[i]=pre[i-1]+v[i];
        }
        
        
        // for(auto &i:pre) cout<<i<<" ";
        //     cout<<endl;
        int st{};
        for(int i=0;i<v.size();i++)
        {
            if(m.find(v[i])==m.end())
            {
                sum+=v[i];
                m[v[i]]=i;
            }
            else{
                sum=0;
                st=max(st,m[v[i]]);
                sum=(pre[i]-pre[st]);
                // cout<<"sum : "<<sum<<endl;
                m[v[i]]=i;
            }
            ans=max(sum,ans);

            
        }
        return ans;
    }
};