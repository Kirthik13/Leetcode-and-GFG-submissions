class Solution {
public:
    vector<vector<int>>ans;
void f(vector<int>v,vector<int>v2,int i,int s,int sum)
{
    if(s>sum) return;

     if(i==v.size()){
    
        if(s==sum)
        {
            ans.push_back(v2);
        }
            return;
    }
    // }
    // for(int j=i;j<v.size();j++)
    // {
    // if(s+v[i]<=sum){
    v2.push_back(v[i]);
    f(v,v2,i,s+v[i],sum);
    v2.pop_back();
    f(v,v2,i+1,s,sum);

    // }

}
    vector<vector<int>> combinationSum(vector<int>& v, int sum) {
        f(v,{},0,0,sum);
        return ans;
    }
};