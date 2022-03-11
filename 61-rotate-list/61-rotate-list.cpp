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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        
        ListNode* h=head;
        int l{},c{};
        while(h)
        {
            l++;
            h=h->next;
        }
        c=k%l;
        if(c==0)
        {
            return head;
        }
        int g=l-c;
        
        int f=0;
        // cout<<"c : "<<c<<" l : "<<l<<" g : "<<g<<endl;
        h=head;
        ListNode* p=NULL;
        while(f!=g)
        {
            p=h;

            h=h->next;
            f++;
        }
        // cout<<" p ->val : "<<p->val<<endl;
        p->next=NULL;
        ListNode* tem=h;
        while(tem->next)
        {
            tem=tem->next;
        }
        tem->next=head;
        return h;
        
    }
};