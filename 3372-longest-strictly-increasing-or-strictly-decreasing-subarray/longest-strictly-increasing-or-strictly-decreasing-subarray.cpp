class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
         int n = nums.size();
          int cnt = 1;
          int ans = 1;
         for(int i = 0; i < n-1; i++){
            if(nums[i+1] > nums[i]) cnt++;
            else{
                
                cnt = 1;
            }
            ans = max(ans,cnt);

         }
         cnt =1;
         for(int i = 0; i < n-1; i++){
            if(nums[i+1] < nums[i])cnt++;
            else{
                
                cnt =1;
            }
            ans = max(ans,cnt);
         }
         return ans;
    }
};