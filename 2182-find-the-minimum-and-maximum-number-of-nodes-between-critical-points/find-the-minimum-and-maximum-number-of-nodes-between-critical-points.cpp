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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int last = -1;
        int latest = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        auto temp = head->next;
        int prev = head->val;
        int i = 1;
        int count = 0;
        while (temp->next != nullptr) {
            int next = temp->next->val;

            int curr = temp->val;

            if (curr > next && curr > prev) {
                count++;
                if (last == -1) {
                    last = i;
                    latest = i;
                } else {
                    mini = min(mini, i - latest + 1);
                    maxi = max(maxi, i - last + 1);

                    latest = i;
                }
            } else if (curr < next && curr < prev) {
                count++;
                if (last == -1) {
                    last = i;
                    latest = i;
                } else {
                    mini = min(mini, i - latest + 1);
                    maxi = max(maxi, i - last + 1);

                    latest = i;
                }
            }

            prev = curr;
            temp = temp->next;
            i++;
        }

        if (count < 2) {
            return {-1, -1};
        }

        return {mini-1, maxi-1};
    }
};