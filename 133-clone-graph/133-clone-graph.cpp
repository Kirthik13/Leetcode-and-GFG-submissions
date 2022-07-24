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
     Node* bfs(Node* node1)
    {
       
        int val=node1->val;
        Node* newnode=new Node(val);
        m[node1]=newnode;
            
        Node* curr=m[node1];
        
         queue<Node*>q;
         q.push(node1);
         int g=0;
         
         while(!q.empty())
         {
            auto node=q.front();
          
             q.pop();
            for(auto &it:node->neighbors)
            {
                if(m.find(it)==m.end())
                {
                    // Node* newnode=dfs(it);
                    int val=it->val;
                    Node* newnode=new Node(val);
                     m[it]=newnode;
                    q.push(it);
                    // m[it]=newnode;
                }
                
                    m[node]->neighbors.push_back(m[it]);
                

            }
             // g=1;
         }
        return curr;
        
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
       // return dfs(node);
        return bfs(node);
    }
};