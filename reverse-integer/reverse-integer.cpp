class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        
        // cout<<s;
        // reverse(s.begin(),s.end());
         std::reverse(s.begin(), s.end());
        if(x<0)
        {
            s.pop_back();   
                   

        }
        stringstream ss(s);
        //string s;
                int ans;

        ss>>ans;
        if(ans>=INT_MAX or ans<=INT_MIN)
        {
            return 0;
        }
        if(x<0){
                    return -ans;

        }
        return ans;
    }
};