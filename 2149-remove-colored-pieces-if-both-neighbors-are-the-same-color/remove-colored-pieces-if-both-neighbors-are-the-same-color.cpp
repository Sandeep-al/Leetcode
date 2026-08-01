class Solution {
public:
    bool winnerOfGame(string colors) {
        int move1 = 0;
        int move2 = 0;
        int n = colors.size();
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] == 'A') {
                curr++;
            } else {
                if (curr >= 3) {
                    move1 += curr - 2;
                }
                curr = 0;
            }
        }
        if (curr >= 3) {
            move1 += curr - 2;
        }

        curr = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] == 'B') {
                curr++;
            } else {
                if (curr >= 3) {
                    move2 += curr - 2;
                }
                curr = 0;
            }
        }
        if (curr >= 3) {
            move2 += curr - 2;
        }

        return move1>move2;
    }
};