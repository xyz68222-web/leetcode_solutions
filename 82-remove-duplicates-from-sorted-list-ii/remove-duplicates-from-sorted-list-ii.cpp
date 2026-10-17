
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            bool duplicate = false;

            while (curr->next != nullptr &&
                   curr->val == curr->next->val) {
                duplicate = true;
                curr = curr->next;
            }

            if (duplicate) {
                if (prev == nullptr) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
            } else {
                prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};
