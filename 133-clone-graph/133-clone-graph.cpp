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
    
    Node* cre(Node* node)
    {
        if(m.find(node->val)!=m.end())
        {
            return m[node->val];
        }
        Node* newnode=new Node(node->val);
        m[node->val]=newnode;
        for(auto it:node->neighbors)
        {
            newnode->neighbors.push_back(cre(it));
        }
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        return cre(node);
    }
};