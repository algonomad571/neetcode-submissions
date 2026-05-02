class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long target = 1LL * k * threshold;
        long long sum = 0;
        int cnt = 0;

        for (int i = 0; i < k; i++) sum += arr[i];
        if (sum >= target) cnt++;

        for (int i = k; i < (int)arr.size(); i++) {
            sum += arr[i];
            sum -= arr[i - k];
            if (sum >= target) cnt++;
        }

        return cnt;
    }
};