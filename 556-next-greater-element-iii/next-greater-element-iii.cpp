class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int x = s.size();

        int pivot = -1;

        for(int i = x - 2; i >= 0; i--) {
            if(s[i] < s[i + 1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) return -1;

        for(int i = x - 1; i > pivot; i--) {
            if(s[i] > s[pivot]) {
                swap(s[i], s[pivot]);
                break;
            }
        }

        reverse(s.begin() + pivot + 1, s.end());

        long long ans = stoll(s);

        if(ans > INT_MAX) return -1;
        return ans;
    }
};