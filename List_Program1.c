#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	ListNode* head = NULL;
	ListNode* pre = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	pre = head->link; // pre에 2번째 노드 지정
	head = insert(head, pre, 6); // pre(2번째 노드) 다음에 삽입
	print_list(head);
	pre = head;

	while (pre->link != NULL) // 마지막 노드 찾기
		pre = pre->link;
	head = insert(head, pre, 7); // 마지막(노드 뒤)에 삽입
	print_list(head);
}
