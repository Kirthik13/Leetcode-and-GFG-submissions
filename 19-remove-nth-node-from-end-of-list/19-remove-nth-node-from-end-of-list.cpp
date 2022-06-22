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
    int findlen(ListNode* head)
    {
        ListNode* h=head;
        int c{};
        while(h)
        {
            c++;
            h=h->next;
        }
        return c;
    }
    ListNode* resnode(ListNode* root,int k,int curr)
    {
        if(k==curr)
        {
            ListNode* res=root->next;
            delete(root);
            return res;
        }
        root->next=resnode(root->next,k,curr+1);
        return root;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h=head;
        int len=findlen(h);
        h=head;
        
        int k=len-n+1;
        
        ListNode* fn=resnode(head,k,1);
        return fn;
        
    }
};