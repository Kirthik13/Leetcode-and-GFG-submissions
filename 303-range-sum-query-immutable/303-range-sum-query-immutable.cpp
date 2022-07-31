class segmentnode
{
  public:
    int start,end,val;
    segmentnode* left;
    segmentnode* right;
    
    segmentnode(int l,int r)
    {
        this->start=l;
        this->end=r;
        this->val=0;
        left=NULL;
        right=NULL;
        
        
        
    }
        
    
};
class NumArray {
public:
    segmentnode* root;
    
    segmentnode* buildtree(vector<int>&v,int l,int r)
    {
        if(l>r) return NULL;
        
        segmentnode* node=new segmentnode(l,r);
        if(l==r)
        {
            node->val=v[l];
            return node;
        }
        
        int mid=(l+r)/2;
        node->left=buildtree(v,l,mid);
        node->right=buildtree(v,mid+1,r);
        
        node->val=node->left->val+node->right->val;
        
        return node;
        
    }
    
    int sumtree(segmentnode* root,int l,int r)
    {
        if(root==NULL) return 0;
        if(root->start==l and root->end==r)
        {
            return root->val;
        }
        
        int mid=(root->start+root->end)/2;
        if(l>mid) return sumtree(root->right,l,r);
        if(r<=mid) return sumtree(root->left,l,r);
        
        return sumtree(root->left,l,mid)+sumtree(root->right,mid+1,r);
        
    }
    
    NumArray(vector<int>& v) {
        int n=v.size();
        root=buildtree(v,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return sumtree(root,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */