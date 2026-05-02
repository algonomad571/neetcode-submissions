class Solution {
public:
    int robLinear(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> dp(n+2,0);

        for(int i=r;i>=l;i--){
            dp[i]=max(nums[i]+dp[i+2], dp[i+1]);
        }

        return dp[l];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int case1 = robLinear(nums, 0, n - 2);
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
