class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<char>st;
       int cnt =0;
       int n= s.size();
       for(int i=0;i<n;i++){
         if(s[i] == '(') st.push(s[i]);
         else{
            if(st.empty())cnt++;
            else st.pop();
         }
       }
       return cnt+st.size();
    }
};