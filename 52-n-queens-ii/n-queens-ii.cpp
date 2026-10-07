class Solution {
private:
void fun(int &cnt,vector<string>board,int n,int col,vector<int>&left,vector<int>&low,vector<int>&up){
    if(col == n){
        cnt++;
        return;
    }
    for(int row = 0;row<n;row++){
        if(left[row]==0 && low[row+col]==0 && up[n-1+col-row]==0){
            board[row][col]='Q';
            left[row]=1;
            low[row+col]=1;
            up[n-1+col-row]=1;

            fun(cnt,board,n,col+1,left,low,up);

            board[row][col]='.';
            left[row]=0;
            low[row+col]=0;
            up[n-1+col-row]=0;
        }
       
    }

}
public:
    int totalNQueens(int n) {
        int cnt=0;
        vector<string>board(n);
        string s(n,'.');
        for(int i =0;i<n;i++){
            board[i]=s;
        }
        vector<int>left(n,0);
        vector<int>low(2*n-1,0);
        vector<int>up(2*n-1,0);
        fun(cnt,board,n,0,left,low,up);
        return cnt;
    }
};