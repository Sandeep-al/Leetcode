class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> yo;
        int k = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                yo.push_back({nums[i][j], i});
            }
        }
        int n=yo.size();
        sort(yo.begin(), yo.end());

        int mini1 = 0;
        int mini2 = INT_MAX;

        int l = 0;
        unordered_map<int,int> mpp;
        for (int r = 0; r < n; r++) {
            mpp[yo[r].second]++;

            while (mpp.size() == k) {
                if (mini2 - mini1 > (yo[r].first - yo[l].first)) {

                    mini1 = yo[l].first;
                    mini2 = yo[r].first;
                } else if (mini2 - mini1 == (yo[r].first - yo[l].first)) {
                    if (yo[l].first < mini1) {
                        mini1 = yo[l].first;
                        mini2 = yo[r].first;
                    }
                }

                mpp[yo[l].second]--;
                if (mpp[yo[l].second] == 0) {
                    mpp.erase(yo[l].second);
                }
                l++;
            }
        }

        return {mini1, mini2};
    }
};