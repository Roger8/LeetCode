/**problem
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct  ListNode* st = head,
    * ed = head;
    //assign the Node st is n steps ahead of ed node 
	//  head->node 1-> node 2-> st -> [...n ]->ed -> node sth ... 
	
    if(head == NULL){
        return NULL;
    }
    
	//set ed behind n steps of st node 
    for(int i=0;i<n;i++){
        ed = ed->next;
    }
	//if the first node is rightly the nth node from the end of list
    if(ed == NULL){
        head = head->next;
        return head;
    }
    //move st and ed until find the end ,when ed->next is null , the st is 
	//rightly the nth node from the end of list 
    while(ed->next != NULL){
        st = st->next;
        ed = ed->next;
    }
	// remove it ,and return head 
    st->next = st->next->next;
    return head;
}