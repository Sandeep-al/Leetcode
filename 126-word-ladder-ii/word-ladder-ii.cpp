class Solution {
public:
    vector<vector<string>> final_ans;
    string b;
    void dfs(string word, vector<string> curr_string,
             unordered_map<string, int>& mpp) {
        string curr = word;
        for (int i = 0; i < word.size(); i++) {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == original)
                    continue;

                word[i] = ch;

                if (mpp.find(word) != mpp.end() && mpp[curr] - 1 == mpp[word]) {
                    curr_string.push_back(word);
                    if (word == b) {
                        reverse(curr_string.begin(),curr_string.end());
                        final_ans.push_back(curr_string);
                        return;
                    }
                    dfs(word, curr_string, mpp);
                    curr_string.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        b = beginWord;
        if (st.find(endWord) == st.end())
            return {};

        queue<pair<string, int>> q;
        unordered_map<string, int> mpp;
        q.push({beginWord, 1});

        if (st.find(beginWord) != st.end())
            st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            mpp[word] = steps;
            if (word == endWord)
                break;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original)
                        continue;

                    word[i] = ch;

                    if (st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        dfs(endWord, {endWord}, mpp);
        return final_ans;
    }
};