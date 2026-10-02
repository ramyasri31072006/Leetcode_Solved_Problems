class Solution {
public:
    int larg_hist(vector<int>& height) {

        stack<int> st;
        int n = height.size();
        int maxarea = 0, nse, pse;
       
        for (int i = 0; i < n; i++) {

            while (!st.empty() && height[st.top()] >= height[i]) {
                int ele = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxarea = max(maxarea, height[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxarea = max(maxarea, height[ele] * (nse - pse - 1));
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

          if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> psum(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {

                if (matrix[i][j] == '0')
                    sum = 0;
                else
                    sum += 1;
                psum[i][j] = sum ;
            }
        }
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            maxarea = max(maxarea, larg_hist(psum[i]));
        }
        return maxarea;
    }
};