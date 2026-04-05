class Solution {
public:
    bool judgeCircle(string moves) {
        int left=0;
        int right=0;
        int up=0;
        int down=0;

        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') up++;
            else if(moves[i]=='L') left++;
            else if(moves[i]=='R') right++;
            else down++;
        }

        return left==right && up==down;
    }
};