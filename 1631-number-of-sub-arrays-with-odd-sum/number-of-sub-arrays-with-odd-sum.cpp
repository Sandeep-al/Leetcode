class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // (prefix[r]-prefix[l-1])%2==1;
        // prefix[r] % 2 = 1 + (prefix[l-1])%2;
        int mod = 1e9 + 7;
        int prefix_sum = 0;
        int mpp[2] = {0};
        int count = 0;
        mpp[1] = 1;
        for (int i = 0; i < arr.size(); i++) {
            prefix_sum += arr[i];

            int curr = prefix_sum % 2;

            count = (count + mpp[curr]) % mod;

            mpp[(curr + 1) % 2]++;
        }

        return count;
    }
};