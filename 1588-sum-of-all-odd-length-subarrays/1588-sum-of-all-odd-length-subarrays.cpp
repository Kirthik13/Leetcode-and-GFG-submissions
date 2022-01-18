class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& v) {
        int n=v.size();
        if(n==1)
        {
            return v.front();
        }
int c{};
for(auto &i:v)
{
    c+=i;
}
        if(n<=2)
        {
            return c;
        }
    
for(int i=1;i<v.size();i++)
{
    v[i]=v[i]+v[i-1];
}
// for(auto i:v)
// {
//     cout<<i<<" ";
// }
// cout<<nx;
int f=0;

     f=2;
// for(int i=0;i<)
for(int i=0;i<n;i++)
{
//    for(int j=i+2;j<n;j+=f)
//    {
        while(f+i<n){
            // deb(v[f+i]);
            if(i!=0){
       c=c+v[f+i]-v[i-1];
            
            }
            else{
                c+=v[f+i];
            }

        f+=2;
        }
    f=2;
//    }

}
        return c;
    }
};