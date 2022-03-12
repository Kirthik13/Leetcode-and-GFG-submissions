// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
 
    Node* parent(Node* root,unordered_map<Node*,Node*>&m,int target)
    {
        Node* res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            if(target==t->data) res=t;
            if(t->left)
            {
                m[t->left]=t;
                q.push(t->left);
            }
            if(t->right)
            {
                m[t->right]=t;
                q.push(t->right);
            }
            
        }
        return res;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>m;
        unordered_set<Node*>st;
        // parent(root,m,NULL);
        
        Node* node=parent(root,m,target);
       
        queue<Node*>q;
        q.push(node);
        int ans{};
        st.insert(node);
        while(!q.empty())
        {
            int n=q.size();
            // ans++;
            int fl=0;
            for(int i=0;i<n;i++)
            {
                Node* t=q.front();
                q.pop();
                
                if(t->left and st.find(t->left)==st.end())
                {
                    q.push(t->left);
                    st.insert(t->left);
                    fl=1;
                }
                if(t->right and st.find(t->right)==st.end())
                {
                    q.push(t->right);
                    st.insert(t->right);
                    fl=1;
                }
                if(m[t]!=NULL and st.find(m[t])==st.end() )
                {
                    q.push(m[t]);
                    fl=1;
                    st.insert(m[t]);
                }
            }
            if(fl) ans++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends