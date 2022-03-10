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
         if(!l1 or !l2)
         {
             if(!l1) return l2;
             return l1;

         }
        ListNode* h1=l1;
        ListNode* h2=l2;
        string s1,s2;
        while(h1)
        {
            s1.push_back(char(h1->val)+48);
            h1=h1->next;
        }
        while(h2)
        {
            s2.push_back(char(h2->val)+48);
            h2=h2->next;
        } 
        h1=l1;
        h2=l2;
        int car{};
        ListNode* dum=new ListNode(0);
        ListNode* p=dum;
        int i=0;
        for( i=0;i<min(s1.size(),s2.size());i++)
        {
            int a=(int(s1[i])-48)+(int(s2[i])-48)+car;
            // cout<<"A : "<<a<<endl;
            p->next=new ListNode(a%10);
            car=a/10;
            p=p->next;
             
        }
        while(i<s1.size())
        {
            int a=(int(s1[i])-48)+car;
            p->next=new ListNode(a%10);
            p=p->next;
                        car=a/10;

            i++;
        }
        
        while(i<s2.size())
        {
            int a=(int(s2[i])-48)+car;
            p->next=new ListNode(a%10);
            p=p->next;
            car=a/10;
            i++;
        }
        if(car)
        {
            p->next=new ListNode(car);
            p=p->next;
        }
        p->next=NULL;
        return dum->next;
            
    }
};