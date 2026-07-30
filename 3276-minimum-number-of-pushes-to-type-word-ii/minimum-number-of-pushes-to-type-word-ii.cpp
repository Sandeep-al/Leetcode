class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;

        for (char c : word)
            freq[c]++;
        vector<pair<char, int>> v;

        for (auto& it : freq)
            v.push_back(it);
        sort(v.begin(), v.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });
        
        int count = 0;
        int curr = 1;
        int assigned = 0;
        for (auto& jt : v) {
            auto it = jt.first;

            count += curr * jt.second;
            assigned++;

            if (assigned == 8) {
                curr++;
                assigned = 0;
            }
        }

        return count;
    }
};