class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        
        int n = nums.size();
        int total = 1<<n;
        for(int mask=0;mask<total;mask++){
            vector<int>sub;
            for(int j=0; j < n;j++){
           if(mask & 1<<j){
            sub.push_back(nums[j]);
           }
            }
            v.push_back(sub);
        }
        return v;
    }
};  