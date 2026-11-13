
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while(true) {
            ListNode* kth = groupPrev;

            for(int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            if(kth == nullptr)
                break;
                
            ListNode* groupNext = kth->next;

            // Step 3: Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            ListNode* groupStart = curr;

            for(int i = 0; i < k; i++) {

                ListNode* next = curr->next;

                curr->next = prev;

                prev = curr;
                curr = next;
            }

            // Step 4: Connect reversed group
            groupPrev->next = prev;

            // Step 5: Move to next group
            groupPrev = groupStart;
        }

        return dummy->next;
    }
};
