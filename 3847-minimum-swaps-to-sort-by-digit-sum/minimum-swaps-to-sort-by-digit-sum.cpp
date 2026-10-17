class Solution {
public:
    int digi_sum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += (x % 10);
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end(),
             [this](const pair<int, int>& a, const pair<int, int>& b) {
                 int sumA = digi_sum(a.first);
                 int sumB = digi_sum(b.first);
                 if (sumA == sumB) {
                     return a.first < b.first;
                 }
                 return sumA < sumB;
             });

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i] || arr[i].second == i) {
                continue;
            }

            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};
