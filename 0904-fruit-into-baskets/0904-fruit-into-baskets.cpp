class Solution {
public:
    int totalFruit(vector<int>& v) {
        int ans=INT_MIN,st{};
        map<int,int>m;
        for(int i=0;i<v.size();i++)
        {
            
            m[v[i]]++;
            if(m.size()>2)
            {
                if(m[v[st]]==1)
                {
                    m.erase(v[st]);
                }
                else{
                    m[v[st]]--;
                }
                st++;
            }
            
            // cout<<st<<" "<<i-st+1<<endl;
            if(m.size()<=2){
            ans=max(ans,i-st+1);
            }
        }
                  

        return ans;
    }
};