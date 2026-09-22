class Solution {
public:
    int solve(int i, int j, string& s, string& t,
              vector<vector<int>>& dp) {

        
        if (i < 0 && j < 0)
            return 1;

        
        if (i >= 0 && j < 0)
            return 0;

        
        if (i < 0) {
            while (j >= 0) {
                if (t[j] == '*') {
                    j -= 2;
                } else {
                    return 0;
                }
            }
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

       
        if (s[i] == t[j] || t[j] == '.') {
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp);
        }

        
        if (t[j] == '*') {

           
            if (j == 0)
                return dp[i][j] = 0;

           
            bool zero = solve(i, j - 2, s, t, dp);

           
            bool oneOrMore = false;

            if (s[i] == t[j - 1] || t[j - 1] == '.') {
                oneOrMore = solve(i - 1, j, s, t, dp);
            }

            return dp[i][j] = zero || oneOrMore;
        }

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, s, p, dp);
    }
};