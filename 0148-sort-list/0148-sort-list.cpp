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
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left)
            return right;
        if (!right)
            return left;
        ListNode* head;
        
        if (left->val > right->val) {
            head = right;
            right = right->next;
        } else {
            head = left;
            left = left->next;
        }
        ListNode* start = head;
        while (left && right) {
            if (left->val > right->val) {
                head->next = right;
                head = head->next;
                right = right->next;
            } else {
                head->next = left;
                head = head->next;
                left = left->next;
            }
        }
        while(left){
            head->next = left;
            left = left->next;
            head = head->next;
        }
        while(right){
            head->next = right;
            right = right->next;
            head = head->next;
        }
        head = nullptr;
        return start;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head, *fast = head, *prev = slow;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left, right);
    }
};