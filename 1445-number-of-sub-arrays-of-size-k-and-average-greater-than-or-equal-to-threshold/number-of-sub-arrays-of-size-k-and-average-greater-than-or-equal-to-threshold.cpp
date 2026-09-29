class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        double sum = 0;
        double t = threshold;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (i >= k) {
                sum -=arr[i - k];
            }

            if (i >= k - 1) {
                if ((sum / k) >= t) {
                    count++;
                }
            }
        }

        return count;
    }
};