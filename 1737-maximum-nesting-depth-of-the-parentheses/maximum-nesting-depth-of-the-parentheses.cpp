class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        // st.push('(');
        int cnt=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                cnt++;
            }
            if(s[i]==')'){
                st.pop();
                ans=max(ans,cnt);
                cnt--;
            }
            
            
        }
        return ans;
    }
};