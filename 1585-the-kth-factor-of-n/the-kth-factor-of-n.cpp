class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int> small, large;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                small.push_back(i);

                if (i != n / i)
                    large.push_back(n / i);
            }
        }
        reverse(large.begin(), large.end());
        vector<int> final_ans;
        for (auto& it : small) {
            final_ans.push_back(it);
        }
        for (auto& it : large) {
            final_ans.push_back(it);
        }
        if(k>final_ans.size()) return -1;
        return final_ans[k - 1];
    }
};