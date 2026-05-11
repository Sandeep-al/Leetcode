class Solution {
public:
    unordered_set<int> st;
    int get_min(int x) {

        // generate factors
        int ans=x;
        for (int i = 1; i * i <= x; i++) {
            
            if (x % i == 0) {

                if (st.count(i))
                    return i;

                if (st.count(x / i))
                    ans = min(ans, x / i);
            }
        }

        return ans;
    }
    long long minArraySum(vector<int>& nums) {
        for (auto& it : nums) {
            st.insert(it);
        }

        long long sum = 0;
        for (auto& it : nums) {
            sum += get_min(it);
        }

        return sum;
    }
};