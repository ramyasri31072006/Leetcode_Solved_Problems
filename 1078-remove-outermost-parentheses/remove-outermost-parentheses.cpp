class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string str;
        for(int i=0;i<size(s);i++){
            if(s[i]=='('){
            if(!st.empty()){
                str+=s[i];
            }
            st.push(s[i]);
            }
            else if(s[i]==')'){
                st.pop();
                if(!st.empty()){
                    str+=s[i];
                }
                
            }
        }
        return str;
    }
};