class Solution {
public:
    int romanToInt(string s) {
        int ans{};
        map<string,int>m;
        m["I"]=1;
        m["IV"]=4;        
        m["V"]=5;
        m["IX"]=9;        
        m["X"]=10;
        m["XL"]=40;
        
        m["L"]=50;
        m["XC"]=90;
        
        m["C"]=100;
        m["CD"]=400;
    
        m["D"]=500;
        m["CM"]=900;
        
        m["M"]=1000;
        
        int n=s.size(),i{};
        while(i<n)
        {
            string t=s.substr(i,2);
                if(m.find(t)!=m.end() and t.size()==2)
                {
                    ans+=m[t];
                    i+=2;
                }
                else{
                    string temp;
                    temp+=s[i];
                    if(m.find(temp)!=m.end())
                    {
                        ans+=m[temp];
                        i++;
                    }
                }
                
        }
        
        return ans;
        
    }
};