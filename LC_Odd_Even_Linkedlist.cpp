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
    ListNode* oddEvenList(ListNode* head) {

        
        ListNode* dummy1 = new ListNode(-1);
        ListNode* odd=dummy1;
        ListNode* dummy2 = new ListNode(-1);
        ListNode* even=dummy2;
        ListNode* temp=head;
        int count=1;
        while(temp)
        {
            if(count%2!=0)
            {
                odd->next=new ListNode(temp->val);
                odd=odd->next;
                temp=temp->next;
            }
            else
            {   
                even->next=new ListNode(temp->val);
                even=even->next;
                temp=temp->next;
            }
            count++;
        }

        odd->next=dummy2->next;       
        return dummy1->next;
        
    }
};

/**
 * LeetCode 328. Odd Even Linked List
 *
 * Question:
 * Given the head of a singly linked list, group all the nodes with odd indices together
 * followed by the nodes with even indices, and return the reordered list.
 *
 * - Odd and even refer to the node's position (1-based index), not the value.
 * - The relative order inside the odd group and even group should remain the same.
 *
 * Example:
 * Input:  head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 *
 * Constraints:
 * - The number of nodes in the list is in the range [0, 10^4].
 * - -10^6 <= Node.val <= 10^6
 *
 * Approach (your implementation):
 * - Create two dummy lists:
 *   - One for odd indexed nodes
 *   - One for even indexed nodes
 * - Traverse the list while keeping a counter for positions
 * - Attach nodes to the corresponding list
 * - Finally, connect the odd list to the even list
 * - Return the new head
 */

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
    ListNode* oddEvenList(ListNode* head) {

        // Dummy nodes for odd and even lists
        ListNode* dummy1 = new ListNode(-1);
        ListNode* odd = dummy1;
        ListNode* dummy2 = new ListNode(-1);
        ListNode* even = dummy2;

        ListNode* temp = head;
        int count = 1; // position counter (1-based)

        // Traverse the original list
        while (temp) {
            if (count % 2 != 0) {
                // Current node is at odd position
                odd->next = new ListNode(temp->val);
                odd = odd->next;
            } else {
                // Current node is at even position
                even->next = new ListNode(temp->val);
                even = even->next;
            }
            temp = temp->next;
            count++;
        }

        // Connect odd list with even list
        odd->next = dummy2->next;

        // Return new head (skipping dummy node)
        return dummy1->next;
    }
};
