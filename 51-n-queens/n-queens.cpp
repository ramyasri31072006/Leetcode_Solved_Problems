class Solution {
private:
void solve(int col,vector<int>&left,vector<int>&up_dia,vector<int>&low_dia,vector<string>&board,
vector<vector<string>>&ans,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0;row<n;row++){
        if(left[row]==0 && up_dia[n-1+col-row]==0&&low_dia[col+row]==0){
            board[row][col]='Q';
            left[row]=1;
            up_dia[n-1+col-row]=1;
            low_dia[col+row]=1;
            solve(col+1,left,up_dia,low_dia,board,ans,n);
            board[row][col]='.';
            left[row]=0;
            up_dia[n-1+col-row]=0;
            low_dia[col+row]=0;


        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>left(n,0);
        vector<int>up_dia(2*n-1,0);
        vector<int>low_dia(2*n-1,0);
        solve(0,left,up_dia,low_dia,board,ans,n);
        return ans;

    }
};