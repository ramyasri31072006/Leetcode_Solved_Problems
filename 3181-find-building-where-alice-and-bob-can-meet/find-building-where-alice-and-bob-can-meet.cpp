class Solution {
public:
    vector<int> segtree;
    void buildsegtree(int i, int l, int r, vector<int>& heights) {
        if (l == r) {
            segtree[i] = l;
            return;
        }

        int mid = (l + r) / 2;
        buildsegtree(2 * i + 1, l, mid, heights);
        buildsegtree(2 * i + 2, mid + 1, r, heights);

        int leftMaxIdx = segtree[2 * i + 1];
        int rightMaxIdx = segtree[2 * i + 2];

        if (heights[leftMaxIdx] >= heights[rightMaxIdx]) {
            segtree[i] = leftMaxIdx;
        } else {
            segtree[i] = rightMaxIdx;
        }
    }

    int query(int i,int l, int r, int start, int end ,vector<int>& heights){

        if(l > end || start > r) return -1;

        if(l >= start && r <= end) return segtree[i];
        
        int mid = l+(r-l)/2;

        int leftMaxIdx = query(2*i+1,l,mid,start,end,heights);
        int rightMaxIdx = query(2*i+2,mid+1,r,start,end,heights);

        if(leftMaxIdx == -1) return rightMaxIdx;
        if(rightMaxIdx == -1) return leftMaxIdx;

        if(heights[leftMaxIdx] >= heights[rightMaxIdx]){
            return leftMaxIdx;
        }
        else{
            return rightMaxIdx;
        }
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
                                        
        int n = heights.size();
        segtree.resize(4 * n, 0);
        vector<int>ansVec;

        buildsegtree(0, 0, n - 1, heights);

        int m = queries.size();
        for (int i = 0; i < m; i++) {

            int alice = queries[i][0];
            int bob = queries[i][1];

            if (alice > bob)
            swap(alice, bob);

        if (alice == bob ||
            heights[alice] < heights[bob]) {

            ansVec.push_back(bob);
            continue;
        }
            int l = bob+1;
            int r = n-1;
            int ans = -1;

            while (l <= r) {

                int mid = l + (r - l) / 2;

                int idx = query(0,0, n-1, bob + 1, mid,heights);

                if (idx != -1 && heights[idx] > heights[alice] &&
                    heights[idx] > heights[bob]) {

                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ansVec.push_back(ans);
        }
        return ansVec;
    }
};