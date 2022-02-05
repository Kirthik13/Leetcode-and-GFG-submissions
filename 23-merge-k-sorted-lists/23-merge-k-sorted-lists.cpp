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
    ListNode* mergeKLists(vector<ListNode*>& v) {
        // map<int,int>m;
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto &i:v)
        {
            ListNode* p=i;
            while(p){
            // m[p->val]++;
                pq.push(p->val);
                p=p->next;
            }
            
        }
        ListNode* dum=new ListNode(0);
        ListNode* h=dum;
//         for(auto &i:m)
//         {
//             int dat=i.first,occ=i.second;
//             while(occ--)
//             {
//                 ListNode* node=new ListNode(dat);
//                 h->next=node;
//                 h=h->next;
                
//             }
            
//         }
        while(!pq.empty())
        {
            int dat=pq.top();
             pq.pop();
             ListNode* node=new ListNode(dat);
             h->next=node;
             h=h->next;
        }
        h->next=NULL;
        return dum->next;
    }
};