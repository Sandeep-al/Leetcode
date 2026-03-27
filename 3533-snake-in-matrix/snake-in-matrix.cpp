class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row=0;
        int col=0;
        for(auto &it:commands){
            if(it=="RIGHT"){
                col++;
            }
            else if(it=="LEFT"){
                col--;
            }
            else if(it=="DOWN"){
                row++;
            }
            else{
                row--;
            }
        }
        return (row*n )+col;
    }
};