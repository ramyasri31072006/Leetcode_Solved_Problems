class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) return "";

        string ans = "";

        while (sum >= 9) {
            ans += '9';
            sum -= 9;
        }

        if (sum > 0) {
            ans += char(sum + '0');
        }

        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};