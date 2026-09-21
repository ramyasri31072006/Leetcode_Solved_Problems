class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        
        for(int i=0;i<=n;i++){
            dp[1][i] = true;
        }
        int maxlen = 1;
        int idx =0;
        for(int len =2;len<=n;len++){
            for(int j =1;j<=n;j++){
                int c = j-len;
                if(c < 0) continue;
                if(s[c] == s[j-1] && len ==2){
                    dp[len][j] = true;
                    if(maxlen < len){
                        maxlen = len;
                        idx = c;
                    }
                }
                else if(s[c] == s[j-1]){
                    if(dp[len-2][j-1]){
                        dp[len][j] = true;
                        if(maxlen < len){
                        maxlen = len;
                        idx = c;
                    }
                    }
                }
            }
        }

      return s.substr(idx,maxlen);
    }
};