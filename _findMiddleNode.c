/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//   [1]->[2]->[3]>[4]>[5]>[6]->NULL
//    ^
//   |
//1:s,f
//   [1]->[2]->[3]>[4]>[5]>[6]->NULL
//        ^     ^
//       |     |
//2:     s     f
//   [1]->[2]->[3]>[4]>[5]>[6]->NULL
//              ^       ^
//             |        |
//3:           s        f
// the third time , fast->next->next ==NULL , slow came to middle 

struct ListNode* findmidNode(struct ListNode* head){
	if(head == NULL || head->next == NULL) return head;
	ListNode* fast,*slow ;
	fast = slow = head;
	//each time slow move front one node. fast move two node ;
	//if length is even, fast->next->next first came to NULL ,slow came to front half'end 
	//if it's odd , fast->next came to NULL,the slow->next come to the middle
	//whatever slow->next point to the second half's head 
	while(fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->next;
}
