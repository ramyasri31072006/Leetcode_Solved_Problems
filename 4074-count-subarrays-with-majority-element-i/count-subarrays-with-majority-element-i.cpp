
class Solution {
public:
    int buildtree(int l, int r, vector<int>& nums,
                  int target, int &cnt) {
        if (l == r) {
            if (nums[l] == target)
                cnt++;
            return cnt;
        }

        int mid = (l + r) / 2;

        buildtree(l, mid, nums, target, cnt);
        buildtree(mid + 1, r, nums, target, cnt);

        // Count crossing subarrays
        int leftFreq = 0;

        for (int i = mid; i >= l; i--) {
            if (nums[i] == target)
                leftFreq++;

            int freq = leftFreq;

            for (int j = mid + 1; j <= r; j++) {
                if (nums[j] == target)
                    freq++;

                int len = j - i + 1;

                if (freq > len / 2)
                    cnt++;
            }
        }

        return cnt;
    }

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        if (nums.empty()) return 0;

        return buildtree(0, nums.size() - 1,
                         nums, target, cnt);
    }
};
