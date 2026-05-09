class Solution {
public:
    int n, k;
    vector<vector<int>> final_ans;

    void solve(vector<int>& temp) {
        if (temp.size() == k) {
            final_ans.push_back(temp);
            return;
        }
        int x = temp.size();
        int last_added;
        if (x == 0)
            last_added = 0;
        else
            last_added = temp[x - 1];

        for (int i = last_added + 1; i <= n; i++) {

            temp.push_back(i);
            solve(temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        this->n = n;

        vector<int> temp;
        solve(temp);
        return final_ans;
    }
};