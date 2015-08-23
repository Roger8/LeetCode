//problem :Reverse a singly linked list.

#include <stdio.h>

typedef struct Node{
	char data;
	struct Node * next;
}Node;


void printlist(Node* list){
	while(list){
		printf("%c",list->data);
		list=list->next;
	}
	printf("\n");
}
//nonrecursive
Node * reverse(struct Node * root){
// Step 1:
//
// prev head  next
//   |    |    |
//   v    v    v
// NULL  [0]->[1]->[2]->NULL
//
// Step 2:
//
//      prev head  next
//        |    |    |
//        v    v    v
// NULL<-[0]  [1]->[2]->NULL

	Node * pre=NULL;

	while(root){
		Node* next=root->next;
		root->next = pre;
		pre=root;
		root=next;
	}
	return pre;
}

Node * reverse2(struct Node* root){

	//step 1: store root into temp
	//step 2: advance root to its next
	//step 3: put pre into temp's next , now temp is new root of reversed
	//step 4: store temp into pre;
	Node * pre=NULL;
	while(root){
		Node * temp=root;
		root = root->next;
		temp->next = pre;
		pre = temp;
	}
	return pre;
}

int main()
{
	Node a={'1',0};
	Node b={'2',&a};
	Node c={'3',&b};
	Node d={'4',&c};
	Node * head = &d;

	printlist(head);
	//head=reverse(head);
	printlist(reverse2(head));

	return 0;

}
