/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        stack<pair<int, int>> st;

        auto temp = head;
        int n = 0;
        while (temp != nullptr) {

            n++;
            temp = temp->next;
        }
        vector<int> ans(n,0);
        int i = 0;
        temp = head;
        while (temp != nullptr) {

            while (!st.empty() && st.top().first < temp->val) {
                ans[st.top().second] = temp->val;
                st.pop();
            }

            st.push({temp->val, i});
            i++;
            temp = temp->next;
        }

        return ans;
    }
};