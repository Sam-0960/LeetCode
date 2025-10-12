/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){
    struct ListNode* prev= NULL;
    struct ListNode* curr= head;
    struct ListNode* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return true;

    struct ListNode* head1 = head;
    struct ListNode* head2;

    struct ListNode* slow=head;
    struct ListNode* fast=head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast){
        slow = slow->next;
    }
    head2 = reverse(slow);

    while(head2){
        if(head2->val != head1->val){return false;}
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}