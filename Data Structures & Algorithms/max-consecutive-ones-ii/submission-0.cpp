class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, zeroCount = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) zeroCount++;

            while (zeroCount > 1) {
                if (nums[l] == 0) zeroCount--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
