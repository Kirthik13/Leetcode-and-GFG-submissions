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
    unordered_map<Node*,Node*>m;
    Node* dfs(Node* node)
    {
        if(m.find(node)==m.end())
        {
            int val=node->val;
            Node* newnode=new Node(val);
            m[node]=newnode;
            
            
        }
        
        
        Node* curr=m[node];
        for(auto &it:node->neighbors)
        {
            if(m.find(it)==m.end())
            {
                Node* newnode=dfs(it);
                m[it]=newnode;
            }
            curr->neighbors.push_back(m[it]);

        }
        return curr;
        
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
       return dfs(node);
    }
};