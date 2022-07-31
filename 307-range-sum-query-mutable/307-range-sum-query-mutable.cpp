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
    
    
    int updatetree(segmentnode* root,int idx,int data)
    {
        if(root==NULL) return 0;
        int diff;
        if(root->start==idx and root->end==idx)
        {
            diff=data-root->val;
            root->val=data;
            return diff;
                
        }
        
        int mid=(root->start+root->end)/2;
        
        if(idx>mid)
        {
            diff=updatetree(root->right,idx,data);
        }
        else{
            diff=updatetree(root->left,idx,data);
            
        }
        
        root->val=root->val+diff;
        return diff;
        
    }
    
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
    
    void update(int index, int val) {
        int g=updatetree(root,index,val);
    }
    
    int sumRange(int left, int right) {
                return sumtree(root,left,right);

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */