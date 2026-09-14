class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int x2 = rec1[2];
        int y1 = rec1[1];
        int y2 = rec1[3];

        int a1 = rec2[0];
        int a2 = rec2[2];
        int b1 = rec2[1];
        int b2 = rec2[3];

        if (((a2 <= x1) || (a1 >= x2)) || ((b2 <= y1) || (b1 >= y2))) {
            return false;
        }

        return true;
    }
};