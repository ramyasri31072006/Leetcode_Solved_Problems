class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>d;
        int n = nums.size();
        for(int i=0;i<n;i++){
            d.push_back(abs(nums[i]));
        }
        sort(d.begin(),d.end());
        long long f=0;
        for(int i=0;i<n;i++){
            if(i < n/2){
                f+=(1LL*d[i]*d[i]);
            }
            else{
                f-=(1LL*d[i]*d[i]);
            }
        }
        return abs(f);
    }
};