class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<int,int>mp;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            dp[i][0] = matrix[i][0];
            mp[matrix[i][0]]++;
        }
        for(int j = 1; j < m;j++){
            dp[0][j] = matrix[0][j];
            mp[matrix[0][j]]++;
        }
        for(int i = 1; i<n;i++){
            for(int j = 1; j< m;j++){
               
                int left = dp[i][j-1];
                int top = dp[i-1][j];
                int top_left = dp[i-1][j-1];
                if(matrix[i][j] == 1){
                    dp[i][j] = min({left,top,top_left})+1;
                    if(matrix[i][j] != dp[i][j]){
                        mp[matrix[i][j]]++;
                        mp[dp[i][j]]++;
                    }
                    else{
                         mp[matrix[i][j]]++;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
                
            }
        }
        int ans = 0;
        int mini = min(n,m);
        ans += mp[1];
        ans += mp[2];
        for(int i = 3;i<=mini;i++){
            ans +=((i-1)*mp[i]);
        }
        return ans;
    }
};