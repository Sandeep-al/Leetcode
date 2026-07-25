class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mapped_nums;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int new_num = 0;
            int multiplier = 1;

            if (curr == 0) {
                new_num = mapping[0];
            } else {
                while (curr > 0) {
                    new_num = mapping[curr % 10] * multiplier + new_num;
                    multiplier *= 10;
                    curr /= 10;
                }
            }

            mapped_nums.push_back({new_num, i});
        }

        sort(mapped_nums.begin(), mapped_nums.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first == b.first) {
                     return a.second < b.second;
                 }
                 return a.first < b.first;
             });

        vector<int> ans;
        for (auto& p : mapped_nums) {
            ans.push_back(nums[p.second]);
        }

        return ans;
    }
};