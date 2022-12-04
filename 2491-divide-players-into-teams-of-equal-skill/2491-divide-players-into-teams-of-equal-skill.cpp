#define ll unsigned long long
class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        sort(begin(v),end(v));
        int n=v.size();
        ll int i{},j=n-1,totans{},fl=1;
        ll int reqsum=v[i]+v[j];
        while(i<n/2 and j>=n/2)
        {
           ll int curr=v[i]+v[j];
            if(curr==reqsum)
            {
                totans+=(v[i]*v[j]);
            }
            else{
                fl=0;
                break;
            }
            i++;
            j--;
        }
        
        if(!fl) return -1;
        
        return totans;
        
        
    }
};