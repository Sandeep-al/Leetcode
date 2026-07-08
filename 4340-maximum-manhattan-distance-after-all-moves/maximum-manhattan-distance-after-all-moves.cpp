class Solution {
public:
    
    int count_=0;
    int x=0;
    int y=0;
    int maxDistance(string moves) {
        int maxi=0;
        for(auto &it:moves){
            if(it=='R') x++;
            if(it=='L') x--;
            if(it=='D') y--;
            if(it=='U') y++;
            if(it=='_') count_+=1;

            
        }

        return abs(x)+abs(y)+count_;
    }
};