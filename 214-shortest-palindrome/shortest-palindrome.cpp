class StringHash {
    using ll = long long;

private:
    int len;

    const ll MOD1 = 1e9 + 7;
    const ll MOD2 = 1e9 + 9;
    const ll BASE1 = 313;
    const ll BASE2 = 317;

    vector<ll> prefHash1, prefHash2;
    vector<ll> basePow1, basePow2;

public:
    StringHash(const string& s) {
        len = s.length();
        prefHash1.assign(len + 1, 0);
        prefHash2.assign(len + 1, 0);
        basePow1.assign(len + 1, 1);
        basePow2.assign(len + 1, 1);

        for (int i = 0; i < len; i++) {

            prefHash1[i + 1] = (prefHash1[i] * BASE1 + s[i]) % MOD1;
            prefHash2[i + 1] = (prefHash2[i] * BASE2 + s[i]) % MOD2;

            basePow1[i + 1] = (basePow1[i] * BASE1) % MOD1;
            basePow2[i + 1] = (basePow2[i] * BASE2) % MOD2;
        }
    }

    pair<ll, ll> getHash(int left, int right) {
        ll val1 =
            (prefHash1[right + 1] -
             (prefHash1[left] * basePow1[right - left + 1]) % MOD1 + MOD1) %
            MOD1;
        ll val2 =
            (prefHash2[right + 1] -
             (prefHash2[left] * basePow2[right - left + 1]) % MOD2 + MOD2) %
            MOD2;
        return {val1, val2};
    }
    bool isPalindrome(int left, int right, StringHash& backwardHash) {
        int subLen = right - left + 1;
        int half = subLen / 2;

        if (half == 0)
            return true;

        auto leftHash = this->getHash(left, left + half - 1);

        int revLeft = len - 1 - right;
        int revRight = len - 1 - (right - half + 1);
        auto rightHash = backwardHash.getHash(revLeft, revRight);

        return leftHash == rightHash;
    }
};
class Solution {
public:
    string shortestPalindrome(string s) {

        int n = s.size();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        StringHash forwardHash(s);
        StringHash backwardHash(rev_s);
        int target = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (forwardHash.isPalindrome(0, i, backwardHash)) {
                target = i;
                break;
            }
        }

        if (target == n - 1)
            return s;

        string curr = s.substr(target + 1, n);
        reverse(curr.begin(), curr.end());
        return curr + s;
    }
};