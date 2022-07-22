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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        vector<int>pq;
        
        vector<int>org;
        ListNode* h1=head;
        while(h1)
        {
            if(h1->val<x) pq.push_back(h1->val);
            else org.push_back(h1->val);
            h1=h1->next;
        }
        
        ListNode* dum=new ListNode(-200);
        ListNode* curr=dum;
        
        for(auto &i:pq)
            
        {
            ListNode* newnode=new ListNode(i);
            curr->next=newnode;
            curr=curr->next;
        }
        
        for(auto &i:org)
        {
            ListNode* newnode=new ListNode(i);            
            curr->next=newnode;
            curr=curr->next;
        }
        curr->next=NULL;
        return dum->next;
    }
};