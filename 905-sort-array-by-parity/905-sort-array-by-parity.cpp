class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        int n=v.size();
        int odd=n-1,even=0;
        while(even<odd )
        {
            if(v[even]%2==0)
            {
                even++;
            }
            else{
                // if(v[odd]%2==0){
                swap(v[even],v[odd]);
                // }
                odd--;
                // even++;
            }
            // for(auto &i:v)
            // {
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            
        }
        return v;
        
    }
};