class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> st1;
        stack<int> st2;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int curr = nums[i];

            while (!st2.empty() && nums[st2.top()] < curr) {
                ans[st2.top()] = nums[i];
                st2.pop();
            }
            vector<int> temp;
            while (!st1.empty() && nums[st1.top()] < curr) {
                temp.push_back(st1.top());
                st1.pop();
            }

            reverse(temp.begin(), temp.end());

            for (int x = 0; x < temp.size(); x++) {
                st2.push(temp[x]);
            }

            st1.push(i);
        }

        return ans;
    }
};