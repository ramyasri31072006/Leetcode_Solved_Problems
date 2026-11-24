class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            long long pro = 1;
            long long g = 0;
            long long l = 1;

            for(int j = i; j < n; j++){
                pro *= nums[j];
                if(pro > 25200) break;

                g = gcd(g, (long long)nums[j]);
                l = l / gcd(l, (long long)nums[j]) * nums[j];

                if(pro == g * l){
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};