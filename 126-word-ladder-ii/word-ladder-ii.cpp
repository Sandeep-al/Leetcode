class Solution {
public:
    vector<vector<string>> final_ans;
    string beginWord_global;

    void dfs(string word, vector<string>& curr_string, unordered_map<string, int>& mpp) {
        if (word == beginWord_global) {
            vector<string> temp = curr_string;
            reverse(temp.begin(), temp.end());
            final_ans.push_back(temp);
            return;
        }

        int target_steps = mpp[word] - 1;

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == original) continue;
                
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] == target_steps) {
                    curr_string.push_back(word);
                    dfs(word, curr_string, mpp);
                    curr_string.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return {};

        beginWord_global = beginWord;
        queue<string> q;
        q.push(beginWord);
        
        unordered_map<string, int> mpp;
        mpp[beginWord] = 1;
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];

            if (mpp.count(endWord) && steps >= mpp[endWord]) break;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;
                    
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if (mpp.find(endWord) != mpp.end()) {
            vector<string> path = {endWord};
            dfs(endWord, path, mpp);
        }
        
        return final_ans;
    }
};