class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            map<int,bool>m;
            for(int j=i;j<n;j++){
                m[nums[j]] = true;
                int s = m.size();
                sum+=(s*s);
            }
        }
        return sum;
    }
};