class Solution {
public:
    int minInsertions(string s) {
        int score = 0;
        int total = 0;
        int i = 0;
        int n = s.size();
        while (i < s.size()) {

            if (s[i] == '(') {
                score += 2;
            } else {
                score--;

                if (score < 0) {
                    if (i != n - 1 && s[i + 1] == ')') {
                        total += 1;
                        i++;
                        score = 0;
                    } else {
                        total += 2;
                        score = 0;
                    }
                } else {

                    if (i != n - 1 && s[i + 1] == ')') {
                        score--;
                        i++;
                    } else {
                        total++;
                        score--;
                    }
                }
            }
            i++;
        }

        return total + score;
    }
};