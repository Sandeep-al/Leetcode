class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        int n = beginWord.size();
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        int steps = 0;
        string curr_word;
        
        while (!q.empty()) {

            auto node = q.front();q.pop();
            curr_word = node.first;
            int curr_step = node.second;
            
            steps = max(steps, curr_step);

            if(curr_word==endWord) break;

            for (int i = 0; i < n; i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    string possible =
                        curr_word.substr(0, i) + ch + curr_word.substr(i + 1);
                    if (st.find(possible) != st.end()) {
                        q.push({possible, curr_step + 1});
                        st.erase(possible);
                    }
                }
            }
        }
        if(curr_word!=endWord) return 0;
        if(steps==0) return 0;
        return steps+1;
    }
};