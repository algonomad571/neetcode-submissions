class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto it: nums){
            freq[it]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &it : freq) {
            int num = it.first;
            int f = it.second;
            bucket[f].push_back(num);
        }

        vector<int> result;

        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
