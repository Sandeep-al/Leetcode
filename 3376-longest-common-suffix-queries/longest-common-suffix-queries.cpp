class TrieNode {
public:
    TrieNode* child[26];
    int idx;

    TrieNode() {
        for(int i = 0; i < 26; i++)
            child[i] = nullptr;

        idx = -1;
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(child[i])
                delete child[i];
        }
    }
};

class Solution {
public:

    void updateNode(TrieNode* node,
                    vector<string>& wordsContainer,
                    int i) {

        if(node->idx == -1) {
            node->idx = i;
            return;
        }

        int prev = node->idx;

        if(wordsContainer[i].size() <
           wordsContainer[prev].size()) {

            node->idx = i;
        }
        else if(wordsContainer[i].size() ==
                wordsContainer[prev].size() &&
                i < prev) {

            node->idx = i;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        TrieNode* root = new TrieNode();

        int n = wordsContainer.size();

        // build trie
        for(int i = 0; i < n; i++) {

            TrieNode* node = root;

            updateNode(node, wordsContainer, i);

            string &s = wordsContainer[i];

            for(int j = s.size() - 1; j >= 0; j--) {

                int c = s[j] - 'a';

                if(node->child[c] == nullptr) {
                    node->child[c] = new TrieNode();
                }

                node = node->child[c];

                updateNode(node, wordsContainer, i);
            }
        }

        vector<int> ans;

        // queries
        for(string &q : wordsQuery) {

            TrieNode* node = root;

            int res = node->idx;

            for(int j = q.size() - 1; j >= 0; j--) {

                int c = q[j] - 'a';

                if(node->child[c] == nullptr)
                    break;

                node = node->child[c];

                res = node->idx;
            }

            ans.push_back(res);
        }

        delete root;

        return ans;
    }
};