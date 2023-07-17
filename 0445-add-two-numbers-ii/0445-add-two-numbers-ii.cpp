/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1;
        ListNode* h2=l2;
        
        string s1,s2;
        while(h1)
        {
            int v=h1->val;
            char ch=v+'0';
            s1.push_back(ch);
            h1=h1->next;
        }
        
        while(h2)
        {
            int v=h2->val;
            char ch=v+'0';
            s2.push_back(ch);
            h2=h2->next;
        }
        // cout<<s1<<" "<<s2<<endl;
        
        
        int i=s1.size()-1;
        int j=s2.size()-1;
        
        
        string totans;
        int carry{};
        while(i>=0 and j>=0)
        {
            int a=s1[i]-'0';
            int b=s2[j]-'0';
            // cout<<a<<" "<<b<<endl;
            int ans=a+b+carry;
            if(ans>=10)
            {
                carry=ans/10;
                totans.push_back((ans%10)+'0');
            }
            else{
                totans.push_back((ans)+'0');
                                carry=0;

            }
            i--;
            j--;
        }
        
        
        while(i>=0)
        {
            
            int a=s1[i]-'0';
            int ans=a+carry;
             if(ans>=10)
            {
                carry=ans/10;
                totans.push_back((ans%10)+'0');
            }
            else{
                totans.push_back((ans)+'0');
                carry=0;
            }
            
            i--;
        }
        while(j>=0)
        {
            
            int b=s2[j]-'0';
            int ans=b+carry;
             if(ans>=10)
            {
                carry=ans/10;
                totans.push_back((ans%10)+'0');
            }
            else{
                totans.push_back((ans)+'0');
                                carry=0;

            }
            j--;
        }
        if(carry>0)
        {
            int ans=carry;
            
            totans.push_back((ans)+'0');
                                // carry=0;

        }
        ListNode* dum=new ListNode();
        ListNode* newnode=dum;
        
        for(int i=totans.size()-1;i>=0;i--)
        {
            newnode->next=new ListNode(totans[i]-'0');
            newnode=newnode->next;
        }
        
        
        return dum->next;
    }
};