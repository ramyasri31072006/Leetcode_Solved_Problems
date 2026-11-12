class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int psum =0;
         map<int,int>m;
         m[0] = 1;
        for(int i = 0; i < n; i++){
           psum += nums[i];

           int remove = psum - k;

           ans += m[remove];

           m[psum]++;

        }
        return ans;
    }
};