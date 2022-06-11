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
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        queue<Node*>q;
       q.push(node);
                    m[node->val]=new Node(node->val);

        while(!q.empty())
        {
            Node* el=q.front();
            q.pop();

            
            for(auto &it:el->neighbors)
            {
                if(m.find(it->val)==m.end())
                {
                    m[it->val]=new Node(it->val);
                                    q.push(it);

                }
                m[el->val]->neighbors.push_back(m[it->val]);
            }
        }

        return m[node->val];
    }
};