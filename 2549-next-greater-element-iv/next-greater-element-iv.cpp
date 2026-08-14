class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> st1, st2;

        for (int i = 0; i < n; i++) {

            // Current element is the SECOND greater
            // for elements already waiting in st2
            while (!st2.empty() && nums[st2.top()] < nums[i]) {
                ans[st2.top()] = nums[i];
                st2.pop();
            }

            vector<int> temp;

            // Current element is the FIRST greater
            // for elements in st1
            while (!st1.empty() && nums[st1.top()] < nums[i]) {
                temp.push_back(st1.top());
                st1.pop();
            }

            // Move them to second-greater waiting stack
            for (int j = temp.size() - 1; j >= 0; j--) {
                st2.push(temp[j]);
            }

            // Current element now waits for its first greater
            st1.push(i);
        }

        return ans;
    }
};