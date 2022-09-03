class Solution {
public:
        vector<int>totans;
    void fn(int n,int k,string s)
    {
        if(n==0)
        {
            int g=stoi(s);   
            totans.push_back(g);
            return;
        }
        
         for(int i=0;i<=9;i++)
        {
             char ch=char(i)+'0';
             
             if((s.size()==0 and i!=0) or abs((int(s.back())-'0')-i)==k)
             {
                
                s.push_back(ch);
                 fn(n-1,k,s);
                 s.pop_back();
             }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
       fn(n,k,"");
        return totans;
    }
};