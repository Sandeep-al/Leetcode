class Robot {
public:
    int x, y;
    int width, height;
    int dir;
    vector<string> dirs = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        x = 0;
        y = 0;
        dir = 0;
    }

    void step(int num) {
        int perimeter = 2 * (width + height - 2);
        num %= perimeter;

        if (num == 0 && x == 0 && y == 0) {
            dir = 3;
            return;
        }

        while (num > 0) {
            if (dir == 0) {
                int move = min(num, width - 1 - x);
                x += move;
                num -= move;
                if (x == width - 1 && num > 0) dir = 1;
            } 
            else if (dir == 1) {
                int move = min(num, height - 1 - y);
                y += move;
                num -= move;
                if (y == height - 1 && num > 0) dir = 2;
            } 
            else if (dir == 2) {
                int move = min(num, x);
                x -= move;
                num -= move;
                if (x == 0 && num > 0) dir = 3;
            } 
            else {
                int move = min(num, y);
                y -= move;
                num -= move;
                if (y == 0 && num > 0) dir = 0;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};