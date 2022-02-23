/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>m;
    //dfs
    
    // Node* cre(Node* node)
    // {
    //     if(m.find(node->val)!=m.end())
    //     {
    //         return m[node->val];
    //     }
    //     Node* newnode=new Node(node->val);
    //     m[node->val]=newnode;
    //     for(auto it:node->neighbors)
    //     {
    //         newnode->neighbors.push_back(cre(it));
    //     }
    //     return newnode;
    // }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        queue<Node*>q;
        q.push(node);
        m[node->val]= new Node(node->val);
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            for(auto it:curr->neighbors)
            {
                if(m.find(it->val)==m.end())
                {
                    Node* newnode=new Node(it->val);
                    m[newnode->val] = newnode;

                    q.push(it);
                }
                m[curr->val]->neighbors.push_back(m[it->val]);
            }
        }
        //dfs
        return m[node->val];
        // return cre(node);
    }
};