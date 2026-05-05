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
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* curr = head;
        ListNode* temp = head->next;
        while (temp != nullptr) {
            ListNode* nexttemp = temp->next;
            temp->next = curr;
            curr = temp;
            temp = nexttemp;
        }
        head->next = nullptr;

        return curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*temp=head;
        int x=0;
        while(temp!=nullptr){
            temp=temp->next;
            x++;
        }
        if(x==0) return head;
        k=k%x;
        cout<<k<<endl;
        
        int c=1;
        temp=head;
        while(c!=x-k){
            temp=temp->next;
            c++;
        }

        ListNode*nextnode=temp->next;
        temp->next=nullptr;
        reverse(head);
        
        
        head->next=reverse(nextnode);
        head=temp;

        return reverse(head);
        


    }
};