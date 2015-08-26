/*Merge Two Sorted Lists 
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/
#include <stdio.h>
typedef struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoList(struct ListNode* l1,struct ListNode *l2){
		struct ListNode * head;
		struct ListNode *cur ;

		if(l1==NULL) return l2;
		if(l2==NULL) return l1;

		if(l1->val < l2->val){
				cur = l1;
				l1 = l1->next;
			}
			else{
				cur = l2;
				l2 = l2->next;
			}

 		head = cur;
		while(l1&&l2){
			if(l1->val < l2->val){
				cur->next = l1;
				l1 = l1->next;
			}
			else{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1:l2;
		return head;
	}

int main()
{
	ListNode p1={2,NULL};
	ListNode p2={1,NULL};

	ListNode * l1 = &p1;
	ListNode *l2 = &p2;

	mergeTwoList(l1,l2);
	return 0;

}
