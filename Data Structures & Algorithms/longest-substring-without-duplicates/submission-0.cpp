class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);   
        int l = 0, ans = 0;

        for (int r = 0; r < (int)s.size(); r++) {
            char ch = s[r];

            if (last[ch] >= l) {
                l = last[ch] + 1;
            }

            last[ch] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
