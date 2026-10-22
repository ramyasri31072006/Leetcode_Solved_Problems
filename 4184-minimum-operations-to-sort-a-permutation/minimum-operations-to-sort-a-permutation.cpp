class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc_cnt =0;
        int dsc_cnt =0;
        for(int i=1;i<n;i++){
            if(nums[i] == (nums[i-1]+1)%n) asc_cnt++;
            if(nums[i-1] == (nums[i]+1)%n) dsc_cnt++;
        }
        if(asc_cnt == n-1 && nums[0] == 0) return 0;
        if(asc_cnt == n-1){
            int left_rotation = n-nums[0];
            int right_rotation = 1+nums[n-1]+1+1;
            return min(left_rotation,right_rotation);
        }
        if(dsc_cnt ==n-1){
            int left_rotation = n-nums.back()+1;
            int right_rotation = (nums[0]+1)%n +1;
            return min(left_rotation,right_rotation);
        }
        return -1;
    }
};