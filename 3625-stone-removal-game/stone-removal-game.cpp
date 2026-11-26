class Solution {
public:
    bool canAliceWin(int n) {
        int player = 1;
        int to_remove = 10;

        while (n >= 0) {
            if (n < to_remove) {
                if (player) {
                    return false;
                }

                return true;
            }

            n -= to_remove;
            to_remove--;
            player=1-player;
        }

        return true;
    }
};