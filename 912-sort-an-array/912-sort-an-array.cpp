class Solution {
public:
    void rand_shuf(vector<int>&v)
    {
        int n=v.size();
        for(int i=n-1;i>0;i--)
        {
            int j=rand()%(i+1);
            swap(v[i],v[j]);
        }
        
    }
    int partition(vector<int>&v,int l,int r)
    {
        int pivot=v[r];
        int pidx=l;
        for(int i=l;i<r;i++)
        {
            if(v[i]<=pivot)
            {
                swap(v[i],v[pidx]);
                pidx++;
            }
        }
        swap(v[pidx],v[r]);
        return pidx;
    }
    void quicksort(vector<int>&v,int l,int r)
    {
        if(l<r)
        {
            int pidx=partition(v,l,r);
            quicksort(v,l,pidx-1);
            quicksort(v,pidx+1,r);

        }
    }
    vector<int> sortArray(vector<int>& v) {
        rand_shuf(v);
        quicksort(v,0,v.size()-1);
        return v;
    }
};
