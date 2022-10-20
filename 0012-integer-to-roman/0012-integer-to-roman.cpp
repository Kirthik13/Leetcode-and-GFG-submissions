class Solution {
public:
    string intToRoman(int n) {
        map<int,string>m;
        m[1]="I";
        m[4]="IV";
        m[5]="V";
        m[9]="IX";            
        m[10]="X";
        m[40]="XL";        
        m[50]="L";
        m[90]="XC";                
        m[100]="C";
        m[400]="CD";
        m[500]="D";
        m[900]="CM";
        m[1000]="M";
        
        
        string ans;
        while(n>0)
        {
            auto it=m.lower_bound(n);
            if(it->first!=n)
            {
                it--;
            }
            
            n-=it->first;
            ans+=it->second;
            
        }
        return ans;
        
        
        
        
        
        
    }
};