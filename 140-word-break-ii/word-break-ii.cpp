class Solution {
public:
    unordered_set<string> st;
    int n;
    vector<string> temp;
    vector<string> final_ans;
    void compute(int i, string& s) {

        if (i == n) {
            string sentence = "";
            for (int k = 0; k < temp.size(); k++) {
                sentence += temp[k];
                if (k < temp.size() - 1) {
                    sentence += " ";
                }
            }
            final_ans.push_back(sentence);
            return;
        }

        for (int j = i; j < n; j++) {
            if (st.count(s.substr(i, j - i + 1))) {
                temp.push_back(s.substr(i, j - i + 1));
                compute(j + 1, s);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto& it : wordDict) {
            st.insert(it);
        }
        n = s.size();
        compute(0,s);
        return final_ans;
    }
};