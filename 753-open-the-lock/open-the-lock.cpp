class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        string src = "0000";
        if(dead.count(src)) return -1;

        queue<pair<string,int>> q;
        q.push({src, 0});
        vis.insert(src);

        while(!q.empty()){
            auto [node, steps] = q.front();
            q.pop();

            if(node == target) return steps;

            for(int i = 0; i < 4; i++){
                string temp = node;

                // +1 move
                temp[i] = (node[i] == '9') ? '0' : node[i] + 1;
                if(!dead.count(temp) && !vis.count(temp)){
                    q.push({temp, steps + 1});
                    vis.insert(temp);
                }

                // -1 move
                temp = node;
                temp[i] = (node[i] == '0') ? '9' : node[i] - 1;
                if(!dead.count(temp) && !vis.count(temp)){
                    q.push({temp, steps + 1});
                    vis.insert(temp);
                }
            }
        }
        return -1;
    }
};