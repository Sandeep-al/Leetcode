class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        vector<tuple<int, int, char, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(v.begin(), v.end());

        stack<tuple<int, char, int>> st;

        for (int i = 0; i < n; i++) {
            auto [pos, curr_health, curr_dir, curr_idx] = v[i];

            bool alive = true;

            while (!st.empty() && get<1>(st.top()) == 'R' && curr_dir == 'L') {
                auto &[top_health, top_dir, top_idx] = st.top();

                if (top_health == curr_health) {
                    st.pop();
                    alive = false;
                    break;
                } 
                else if (top_health < curr_health) {
                    st.pop();
                    curr_health--;
                } 
                else {
                    top_health--;
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push({curr_health, curr_dir, curr_idx});
            }
        }

        vector<int> ans(n, -1);

        while (!st.empty()) {
            auto [health, dir, idx] = st.top();
            st.pop();
            ans[idx] = health;
        }

        vector<int> final_ans;
        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) {
                final_ans.push_back(ans[i]);
            }
        }

        return final_ans;
    }
};