
class Solution {
public:
    int digitsum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> aftersorted = nums;

        auto lamda = [this](int nums1, int nums2) {
            int dsum1 = digitsum(nums1);
            int dsum2 = digitsum(nums2);

            if (dsum1 != dsum2)
                return dsum1 < dsum2;

            return nums1 < nums2;
        };

        sort(aftersorted.begin(), aftersorted.end(), lamda);

        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            m[nums[i]] = i;
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (aftersorted[i] != nums[i]) {
                int idx = m[aftersorted[i]];

                m[nums[i]] = idx;
                m[aftersorted[i]] = i;

                swap(nums[i], nums[idx]);

                cnt++;
            }
        }

        return cnt;
    }
};
