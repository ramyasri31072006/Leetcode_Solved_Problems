class Solution {
public:
    // int solve(int i, int n,vector<int>&dp){
    //     if(i == n) return 1;
    //     if(i > n) return 0;

    //     int one_step = solve(i+1,n,dp);
    //     int two_step = solve(i+2,n,dp);

    //     return dp[i] = one_step+two_step;

    // }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
      //  return solve(0,n,dp);

        dp[n] = 1;
        for(int i = n-1; i >= 0; i--){

            int one = dp[i+1];

            int two = 0;
            if(i+2 <= n){
                two = dp[i+2];
            }

            dp[i] = one + two;
          
        }
        return dp[0];
    }
};