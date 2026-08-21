class Solution {
public:
    // lagataar 2 zero nhi rakh sakte lala
    vector<string> final_ans;
    int n;
    void solve(int i, string& curr) {

        if (i == n) {
            final_ans.push_back(curr);
            return;
        }
        curr.push_back('1');
        solve(i + 1, curr);
        curr.pop_back();

        if (curr.empty() || curr.back() != '0') {
            curr.push_back('0');
            solve(i + 1, curr);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        this->n=n;
        string x="";
        solve(0,x);
        return final_ans;
    }
};