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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Base case: if list is empty, simply return
        if (head == nullptr) {
            return nullptr;
        }

        // Step 1: Check if there are at least k nodes left in the list
        int count = 0;
        ListNode* temp = head;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        // If less than k nodes are present, we cannot reverse → return head as is
        if (count < k) return head;

        // Step 2: Reverse exactly k nodes
        ListNode* prev = nullptr;     // previous pointer for reversal
        ListNode* curr = head;        // current pointer to iterate through list
        ListNode* next = nullptr;     // next pointer to temporarily hold next node
        count = 0;

        while (curr != nullptr && count < k) {
            next = curr->next;     // save next node
            curr->next = prev;     // reverse the link
            prev = curr;           // move prev forward
            curr = next;           // move curr forward
            count++;
        }

        // Step 3: Recursively call for the rest of the list
        // "head" is now the LAST node of the reversed block,
        // so connect it with the result of recursion
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // Step 4: prev is the NEW head of this k-group
        return prev;
    }
};
