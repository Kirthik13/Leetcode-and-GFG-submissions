class Solution {
public:
    unordered_map<int,int>dp;
    int fn(string &s,int idx)
    {
     if( idx==s.size()) return 1;
        if(idx>s.size()) return 0;
    
    if(dp.find(idx)!=dp.end()) return dp[idx];
        
    string s1=s.substr(idx,1);
        
     string s2=s.substr(idx,2);
        
    if(stoi(s1)==0) return 0;
   int f=0,sc=0;
    f=fn(s,idx+1);
    if((stoi(s2)>=27 or stoi(s2)<=0 ) )
    {
        // cout<<"s2 : "<<s2<<endl;

       sc=0;
    }
    else
    {
        sc=fn(s,idx+2);

    }

        return dp[idx]=f+sc;
       
     
        
    }
    int numDecodings(string s) {
        return fn(s,0);
        // return 0;
    }
};