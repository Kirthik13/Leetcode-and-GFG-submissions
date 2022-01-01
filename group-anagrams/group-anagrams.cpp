class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
            vector<vector<string>>res;
    if(v.size()==0)
    {
        return res;
    }
          vector<string>v2=v;
    map<string,int>m;
    for(int i=0;i<v.size();i++)
    {
        string s=v2[i];
        sort(s.begin(),s.end());
        v2[i]=s;
        m[s]++;
    }
    vector<int>flag(v.size(),0);
    // for(auto i:v2)
    // {
    //     cout<<i<<" ";
    // }

    for(int i=0;i<v2.size();i++)
    {
        if(flag[i]!=1)
        {
        vector<string>ans;
        string s=v2[i];
        ans.push_back(v[i]);
        flag[i]=1;
        if(m[s]>1 ){
        for(int j=i+1;j<v.size();j++)
        {
            if(s==v2[j] )
            {
                ans.push_back(v[j]);
                // cout<<"v[j]: "<<v[j]<<endl;
                flag[j]=1;
            }
        }
        }
        res.push_back(ans);
        }
    }
    return res;
    }
};