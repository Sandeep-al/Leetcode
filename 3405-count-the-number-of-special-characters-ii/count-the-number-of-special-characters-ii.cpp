class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int, int>> low(26);
        vector<pair<int, int>> up(26);

        for (int i = 0; i < word.size(); i++) {

            char it = word[i];
            if (islower(it)) {
                low[it - 'a'].first += 1;
                low[it - 'a'].second = i;
            } else {
                up[it - 'A'].first += 1;
                if (up[it - 'A'].first == 1) {
                    up[it - 'A'].second = i;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (low[i].first > 0 && up[i].first > 0 &&
                low[i].second < up[i].second)
                count++;
        }

        return count;
    }
};