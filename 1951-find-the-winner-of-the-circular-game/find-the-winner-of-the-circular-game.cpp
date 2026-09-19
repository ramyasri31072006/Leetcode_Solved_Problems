class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++)q.push(i);
        int cnt =0;
        while(q.size() != 1){
            int top = q.front();
            q.pop();
            if(cnt == k-1){
                cnt = 0;
            }
            else{
                cnt++;
                q.push(top);
            }
        }
        return q.front();
    }
};