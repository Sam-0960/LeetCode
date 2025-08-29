/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    struct ListNode* head = temp;
    if(l1 == NULL && l2 == NULL)return NULL;
    if(l1 == NULL && l2) return l2;
    if(l2 == NULL && l1) return l1;
    if(l1->val < l2->val){
        temp->val = l1->val;
        l1 = l1->next;
    }
    else{
        temp->val = l2->val;
        l2 = l2->next;
    }
    while(l1  && l2){
        if(l1->val < l2->val){
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }
    while(l1){
        temp->next = l1;
        temp = l1;
            l1 = l1->next;
    }
    while(l2){
        temp->next = l2;
        temp = l2;
            l2 = l2->next;
    }
    return head;
}