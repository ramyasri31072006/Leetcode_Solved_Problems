class Solution {
private:
void fun(vector<int>&ds,vector<vector<int>>&ans,int n, vector<int>&vis,vector<int>&nums){
    if(ds.size()==n) {
        ans.push_back(ds);
        return;
    }
    
    for(int i = 0;i<n;i++){
        if(vis[i]!=1){
            ds.push_back(nums[i]);
            vis[i]=1;
            fun(ds,ans,n,vis,nums);
            vis[i]=0;
            ds.pop_back();
        } 
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>vis(n,0);
       fun(ds,ans,n,vis,nums);
       return ans;
    }
};