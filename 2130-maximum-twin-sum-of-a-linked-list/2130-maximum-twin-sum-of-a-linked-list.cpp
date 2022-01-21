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
    ListNode* rev(ListNode* head)
    {
        if(!head or !head->next)
        {
            return head;
        }
        ListNode* tem=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return tem;
        
    }
    int pairSum(ListNode* head) {
        
        ListNode* h1=head;
        ListNode* h2=head;
        ListNode* dum=new ListNode(0);
        ListNode* h3=dum;
        while(h2)
        {
            ListNode* n=new ListNode(h2->val);
            h3->next=n;
            h2=h2->next;
            h3=h3->next;
        }
        h3->next=NULL;
        
        h2=rev(dum->next);
        
        ListNode* mh=head;
        ListNode* rh=h2;
        int ans=INT_MIN;
        while(mh and rh)
        {
            ans=max(ans,mh->val+rh->val);
            // cout<<mh->val<<" "<<rh->val<<endl;
            mh=mh->next;
            rh=rh->next;
        }
        return ans;

    }
};