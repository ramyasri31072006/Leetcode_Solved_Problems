class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int n = s.size();
        int i = 0;
        stack<char> st;
        while (i < n - 1) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (!st.empty()) {
                    if (i < n - 1 && s[i + 1] == '(') {
                        cnt++;
                        st.pop();

                    } else if (i < n - 1 && s[i + 1] == ')') {
                        st.pop();
                        i++;
                    }

                } else {
                    if (s[i + 1] == ')') {
                        cnt++;
                        i++;
                    } else {
                        cnt += 2;
                    }
                }
            }
            i++;
        }
        if (i == n - 1) {
            if (s[i] == '(')
                st.push(s[i]);
            else
                if(st.empty()) cnt+=2;
                else{
                    cnt++;
                    st.pop();
                }
        }
        cnt += (st.size() * 2);
        return cnt;
    }
};