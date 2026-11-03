class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+= (maxi-nums[i]);
        }
        return ans;
    }
};