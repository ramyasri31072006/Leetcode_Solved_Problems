class Solution {
public:
    void update(int idx, int l, int r,int i,vector<long long>&segtree){

        if(l == r){
            segtree[i] = 1;
            return;
        }

        int mid = l+(r-l)/2;
        if(idx <= mid){
            update(idx,l,mid,2*i+1,segtree);
        }
        else{
            update(idx,mid+1,r,2*i+2,segtree);
        }
        segtree[i] = segtree[2*i+1]+segtree[2*i+2];
    }

    int query (int i, int ql,int qr, int l, int r, vector<long long>&segtree){

        if(r < ql || l > qr) return 0;

        if(l >= ql && r <= qr) return segtree[i];

        int mid = l+(r-l)/2;

        int left = query(2*i+1, ql, qr, l,mid, segtree);
        int right = query(2*i+2, ql,qr,mid+1, r,segtree);

        return left+right;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int>m;
        int n = nums1.size();
        vector<long long> segtree(4*n,0);
        for(int i = 0; i < n; i++){
            m[nums2[i]] = i;
        }
        long long result = 0;

        for(int i = 0; i < n; i++){

            int idx = m[nums1[i]];

            long long leftCommonCount = query(0,0,idx,0,n-1,segtree);
            long long leftUncommonCount = i - leftCommonCount;
            long long ElementsAfterIdx = n-1-idx;
            long long rightCommoncount = ElementsAfterIdx - leftUncommonCount;

            result += leftCommonCount*rightCommoncount;
            update(idx,0,n-1,0,segtree);
        }
        return result;
    }
};