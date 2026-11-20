class Solution {
public:
    long long solve(int i, int n, int k, vector<int>& nums, vector<int>& dp) {
        if (i == n)
            return nums[i];
        if (dp[i] != INT_MIN)
            return dp[i];

        long long maxi = INT_MIN;

        for (int start = i + 1; start <= min(i + k, n); start++) {

            maxi = max(maxi, solve(start, n, k, nums, dp));
        }

        return dp[i] = maxi + nums[i];
    }
    int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> dp(n);
    deque<int> q;

    dp[n - 1] = nums[n - 1];
    q.push_back(n - 1);

    for (int i = n - 2; i >= 0; i--) {
        while (!q.empty() && q.front() > i + k) {
            q.pop_front();
        }

        dp[i] = nums[i] + dp[q.front()];

        while (!q.empty() && dp[q.back()] <= dp[i]) {
            q.pop_back();
        }

        q.push_back(i);
    }

    return dp[0];
}
};