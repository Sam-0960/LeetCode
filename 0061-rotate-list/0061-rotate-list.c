/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getLen(struct ListNode* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;  // edge cases

    int len = getLen(head);
    k %= len;  // effective rotations
    if (k == 0) return head; // no change

    int stepsToNewHead = len - k - 1;  // go to node just before new head
    struct ListNode* temp = head;

    while (stepsToNewHead--) {
        temp = temp->next;
    }

    struct ListNode* newHead = temp->next;
    temp->next = NULL;

    struct ListNode* tail = newHead;
    while (tail->next) tail = tail->next;
    tail->next = head;

    return newHead;
}
