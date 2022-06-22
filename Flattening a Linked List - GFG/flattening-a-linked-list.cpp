// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* midnode(Node* head)
{
    Node* f=head->bottom;
    Node* s=head;
    
    while(f and f->bottom)
    {
        f=f->bottom->bottom;
        s=s->bottom;
    }
    return s;
    
}
Node* sort(Node* l1,Node* l2)
{
    Node* dum=new Node(-1);
    Node* curr=dum;
    
    while(l1 and l2)
    {
        if(l1->data<=l2->data)
        {
            curr->bottom=l1;
            l1=l1->bottom;
            // l1=l1->bottom;
            
        }
        else{
            curr->bottom=l2;
            l2=l2->bottom;
            
        }
        curr=curr->bottom;
        
    }
    while(l1)
    {
         curr->bottom=l1;
            l1=l1->bottom;
        curr=curr->bottom;
            
    }
    while(l2)
    {
         curr->bottom=l2;
            l2=l2->bottom;
        curr=curr->bottom;
            
    }
    curr->bottom=NULL;
    return dum->bottom;
}
Node* merge(Node* root)
{
    if(!root->bottom) return root;
    
    Node* l1=root;
    Node* mid=midnode(l1);
    Node* l2=mid->bottom;
    mid->bottom=NULL;
    
    
    return sort(merge(l1),merge(l2));
}
Node *flatten(Node *root)
{
    Node* h1=root;
    Node* down=root;
    while(down->bottom)
    {
        down=down->bottom;
    }
    Node*  prev=h1;
    h1=h1->next;
   while(h1)
   {
       
            prev->next=NULL;
            Node* h2=h1;
           down->bottom=h2;
           
           while(down->bottom)
           {
               down=down->bottom;
           }
           prev=h1;
         
       
       h1=h1->next;
   }
   
   Node* ansnode=merge(root);
    
   // Your code here
}

