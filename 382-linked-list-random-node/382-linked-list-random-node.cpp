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
private:
    ListNode* head;
    
public:
    // vector<int>v;
    Solution(ListNode* head) {
//         ListNode* h=head;
//         while(h!=NULL)
//         {
//             int k=h->val;
//             v.emplace_back(k);
//             h=h->next;
//         }
        
        this->head=head;
    }
    
    int getRandom() {
        int res=head->val;
        int i=2;
        ListNode* node=head->next;
        while(node)
        {
            int j=rand()%i;
            if(j==0)
            {
                res=node->val;
            }
                i++;
            
            
            node=node->next;
        }
        return res;
    
        // return v[rand()%v.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */