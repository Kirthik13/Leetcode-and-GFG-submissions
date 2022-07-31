class segmentnode
{
    public:
    segmentnode* left=NULL;
    segmentnode* right=NULL;
    int val, start, end;
    
    segmentnode(int st,int en)
    {
        this->start=st;
        this->end=en;
        val=0;
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
        
        int mid=l+((r-l)/2);
        node->left=buildtree(v,l,mid);
        node->right=buildtree(v,mid+1,r);
        
        node->val=node->left->val+node->right->val;
        
        return node;
        
        
    }
    
    int modifytree(int idx,int data,segmentnode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int diff;
        if(root->start==idx and root->end==idx)
        {
            diff=data-root->val;
            root->val=data;
            return diff;
        }
        
        
        int mid=root->start+((root->end-root->start)/2);
        
        if(idx>mid)
        {
            diff=modifytree(idx,data,root->right);
        }
        else{
            diff=modifytree(idx,data,root->left);

        }
        
        
        root->val = root->val + diff;
        return diff;
    }
  
    
    int sumtree(segmentnode* root,int l,int r)
    {
        if(root==NULL) return 0;
        
        if(root->start==l and root->end==r) return root->val;
        
        int mid=root->start+((root->end-root->start)/2);
        
        if(l>mid) return sumtree(root->right,l,r);
        if(r<=mid) return sumtree(root->left,l,r);
        
        return sumtree(root->left,l,mid)+sumtree(root->right,mid+1,r);
        

    }
    NumArray(vector<int>& v) {
        int n=v.size();
        root=buildtree(v,0,n-1);
    }
    
    void update(int index, int data) {
        
        int g=modifytree(index,data,root);
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