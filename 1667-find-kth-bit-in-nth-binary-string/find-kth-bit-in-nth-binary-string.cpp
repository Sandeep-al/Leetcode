class Solution {
public:
    string reverse(string x) {
        int yo = x.size() - 1;
        int go = 0;

        while (go < yo) {
            swap(x[yo], x[go]);
            go++;
            yo--;
        }

        return x;
    }
    string inverse(string x) {
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '1')
                x[i] = '0';
            else
                x[i] = '1';
        }

        return x;
    }

    string solve(int i) {

        if (i == 1)
            return "0";

        return solve(i - 1) + "1" + reverse(inverse(solve(i - 1)));
    }
    char findKthBit(int n, int k) {

        string ans=solve(n);
        return ans[k-1];
    }
};