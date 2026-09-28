class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<pair<char, int>> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push({s[i], i});
            } else {
                if (!st.empty()) {
                    if (st.top().first == '(') {
                        st.pop();
                    } else {
                        st.push({s[i], i});
                    }
                } else {
                    st.push({s[i], i});
                }
            }
        }
        vector<int> a;
        while (!st.empty()) {
            a.push_back(st.top().second);
            cout << st.top().second << " ";

            st.pop();
        }
        int m = a.size();
        if (m == 0)
            return n;
        sort(a.begin(),a.end());
        int ans = 0;
        for (int i = 1; i < m; i++) {
            ans = max(ans, a[i] - a[i - 1] - 1);
        }
        ans = max(ans, a[0]);
        ans = max(ans, n - a[m - 1] - 1);
        return ans;
    }
};