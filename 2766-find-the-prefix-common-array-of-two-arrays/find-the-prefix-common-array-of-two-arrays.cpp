class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mpp;
        int n = A.size();
        vector<int> ans(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            int a1 = A[i];
            int b1 = B[i];
            if (mpp.find(a1) != mpp.end()) {
                if (mpp[a1] == 1) {
                    count += 1;
                }
                mpp[a1]++;
            }
            else {
                mpp[a1] = 1;
            }
            if (mpp.find(b1) != mpp.end()) {
                if (mpp[b1] == 1) {
                    count += 1;
                }
                mpp[b1]++;
            } else {
                mpp[b1] = 1;
            }

            ans[i] = count;
        }
        return ans;
    }
};