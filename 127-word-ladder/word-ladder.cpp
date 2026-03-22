class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int V = wordList.size();
        unordered_set<string> mpp;
        for (auto& it : wordList) {
            mpp.insert(it);
        }
        int k = beginWord.size();
        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            string word = it.first;
            int steps = it.second;

            if (word == endWord)
                return steps;

            for (int i = 0; i < k; i++) {
                char original_char = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch != original_char) {
                        word[i] = ch;

                        if (mpp.find(word) != mpp.end()) {
                            q.push({word, steps + 1});
                            mpp.erase(word);
                        }
                    }
                }
                word[i] = original_char;
            }
        }

        return 0;
    }
};