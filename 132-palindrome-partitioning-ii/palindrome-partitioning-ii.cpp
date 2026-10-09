class Solution {
public:
    bool ispali(string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
    int solve(int i, int n, string& s, vector<int>& dp) {
        if (i > n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        string temp;
        int mini = 1e9;
        for (int j = i; j <= n; j++) {

            temp += s[j];
            if (ispali(temp)) {
                int cost = 1 + solve(j + 1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // return solve(0,n-1,s,dp)-1;
        for (int i = n - 1; i >= 0; i--) {
            string temp;
            int mini = 1e9;
            for (int j = i; j < n; j++) {
                temp += s[j];
                if (ispali(temp)) {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
             dp[i] = mini;
        }
        return dp[0]-1;
    }
};