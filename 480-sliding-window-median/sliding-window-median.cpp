class Solution {
public:
    multiset<int> small, large;

    void insertNum(int val) {
        if (small.empty() || val <= *small.rbegin())
            small.insert(val);
        else
            large.insert(val);
        rebalance();
    }

    void eraseNum(int val) {
        if (val <= *small.rbegin())
            small.erase(small.find(val));
        else
            large.erase(large.find(val));
        rebalance();
    }

    void rebalance() {
        if (small.size() > large.size() + 1) {
            large.insert(*small.rbegin());
            small.erase(prev(small.end()));
        } else if (small.size() < large.size()) {
            small.insert(*large.begin());
            large.erase(large.begin());
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            insertNum(nums[i]);

            if (i >= k) {
                eraseNum(nums[i - k]);
            }

            if (i >= k - 1) {

                if (k % 2 == 1) {
                    ans.push_back(*small.rbegin());
                } else {
                    ans.push_back(
                        ((double)*small.rbegin() + (double)*large.begin()) /
                        2.0);
                }
            }
        }

        return ans;
    }
};