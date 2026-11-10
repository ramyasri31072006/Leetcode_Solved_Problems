class Solution {
public:
    int solve(int i,int n , vector<int>&cost, vector<int>&dp){
        if(i == n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int  mini = INT_MAX;
        for(int j = 1; j <= 3 && j+i <= n; j++){
            int ans = cost[j + i-1] +j*j + solve(j+i,n,cost,dp);
            mini =  min(mini,ans);
        }

        return dp[i] = mini;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return solve(0,n,costs,dp);
    }
};