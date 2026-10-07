class Solution {
public:
    bool isValid(const string& s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void fun(string s, int start, int removalsLeft, vector<string>& ans) {

        // We have performed the minimum required removals
        if (removalsLeft == 0) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.size(); i++) {

            // We only remove parentheses
            if (s[i] != '(' && s[i] != ')')
                continue;

            // Skip duplicate removal at the same recursion level
            if (i > start && s[i] == s[i - 1])
                continue;

            string temp = s;

            // Remove character at index i
            temp.erase(i, 1);

            // Start again from i because characters shifted left
            fun(temp, i, removalsLeft - 1, ans);
        }
    }

    int solve(const string& s) {
        int open = 0;
        int removals = 0;

        for (char ch : s) {
            if (ch == '(') {
                open++;
            }
            else if (ch == ')') {
                if (open > 0)
                    open--;
                else
                    removals++;
            }
        }

        return removals + open;
    }

    vector<string> removeInvalidParentheses(string s) {
        int min_op = solve(s);

        vector<string> ans;

        fun(s, 0, min_op, ans);

        return ans;
    }
};