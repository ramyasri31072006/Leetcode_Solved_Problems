class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int>fre(26,0);
        for(auto i:s){
            fre[i-'a']++;
        }
        stack<char>st;
        vector<bool>vis(26,false);
        for(int i =0;i<n;i++){
            fre[s[i]-'a']--;
            if(vis[s[i]-'a'] == true) continue;
            while(!st.empty() && st.top() > s[i] && fre[st.top()-'a'] > 0){
                vis[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a'] = true;
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};