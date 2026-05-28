class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> st;

        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {

                int j = i;
                int x = k;
                while (x >= 0 && j >= 0) {
                    st.insert(j);
                    j--;
                    x--;
                }

                j = i;
                x = k;

                while (x >= 0 && j < n) {
                    st.insert(j);
                    j++;
                    x--;
                }
            }
        }

        for(auto &it:st){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};