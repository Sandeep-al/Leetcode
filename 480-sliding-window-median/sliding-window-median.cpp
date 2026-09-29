class Solution {
public:
    void balance(multiset<int>& lower, multiset<int>& higher) {

        if (higher.size() > lower.size()) {
            int smallest = *(higher.begin());
            higher.erase(higher.begin());
            lower.insert(smallest);
        }

        if (lower.size() - 1 > higher.size()) {
            int greatest = *(lower.rbegin());
            lower.erase(lower.find(greatest));
            higher.insert(greatest);
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;
        multiset<int> lower, higher;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            if (lower.empty() || nums[i] <= *(lower.rbegin())) {
                lower.insert(nums[i]);
            } else {
                higher.insert(nums[i]);
            }

            balance(lower, higher);

            if (i >= k) {

                int to_remove = nums[i - k];
                if (nums[i - k] <= *(lower.rbegin())) {
                    lower.erase(lower.find(nums[i - k]));
                } else {
                    higher.erase(higher.find(nums[i - k]));
                }

                balance(lower, higher);
            }

            if (i >= k - 1) {

                if (k % 2 == 1) {
                    ans.push_back(*lower.rbegin());
                } else {
                    long double curr = (long double)*lower.rbegin() + (long double)*higher.begin();
                    ans.push_back(curr/2.0);
                }
            }
        }

        return ans;
    }
};