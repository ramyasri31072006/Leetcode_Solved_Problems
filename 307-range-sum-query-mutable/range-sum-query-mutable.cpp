
class NumArray {
public:
    vector<int> segtree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4 * n, 0);

        if (n > 0) {
            buildsegtree(0, 0, n - 1, nums);
        }
    }

    void buildsegtree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segtree[i] = nums[l];
            return;
        }

        int mid = (l + r) / 2;

        buildsegtree(2*i+1, l, mid, nums);
        buildsegtree(2*i+2, mid+1, r, nums);

        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }

    void updatesegtree(int i, int l, int r, int idx, int val) {
        if (l == r) {
            segtree[i] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            updatesegtree(2*i+1, l, mid, idx, val);
        } else {
            updatesegtree(2*i+2, mid+1, r, idx, val);
        }

        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }

    int rangesum(int i, int l, int r, int start, int end) {
       
        if (end < l || start > r) {
            return 0;
        }

       
        if (start <= l && r <= end) {
            return segtree[i];
        }

        
        int mid = (l + r) / 2;

        int left = rangesum(2*i+1, l, mid, start, end);
        int right = rangesum(2*i+2, mid+1, r, start, end);

        return left + right;
    }

    void update(int index, int val) {
        updatesegtree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return rangesum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int param_2 = obj->sumRange(left, right);
 */
