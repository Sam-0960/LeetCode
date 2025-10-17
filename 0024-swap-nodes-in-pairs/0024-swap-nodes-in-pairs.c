/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head) {
    if( head== NULL) return NULL;
    if( head->next == NULL) return head;
    
    struct ListNode* first = head;
    struct ListNode* second = head->next;

    while(first && second){
        int a = first->val;
        int b = second->val;
        int temp = a;
        a=b;
        b = temp ;
        
        first->val = a;
        second->val = b;
        
        first = first->next->next;
        
        if(second->next){
            second = second->next->next;
        }

    }
    return head;

}