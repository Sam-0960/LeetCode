/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getLength(struct ListNode* head){
    int len =0;
    struct ListNode* temp = head;
    while(temp){
        temp = temp->next;
        len++;
    }
    return len;
}
struct ListNode* middleNode(struct ListNode* head) {
    int len = getLength(head);
    int mid = len/2 +1;
    int i=0;
    struct ListNode* temp = head;
    while(i<mid-1 && temp){
        temp = temp->next;
        i++;
    }
    return temp;
}