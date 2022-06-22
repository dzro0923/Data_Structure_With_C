#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

DListNode* dinsert(DListNode* head, DListNode* pre, element value) {
	DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
	new_node->data = value;

	if (head == NULL) {
		head = new_node;
		new_node->rlink = NULL;
		new_node->llink = NULL;
	}
	else if (pre == NULL) {
		new_node->rlink = head;
		head = new_node;
		new_node->llink = NULL;
		new_node->rlink->llink = new_node;
	}
	else {
		new_node->rlink = pre->rlink;
		pre->rlink = new_node;
		new_node->llink = pre;
		if (new_node->rlink != NULL)
			new_node->rlink->llink = new_node;
	}
	return head;
}

DListNode* ddelete(DListNode* head, DListNode* removed) {
	if (head == NULL) {
		printf("ddelete() error\n");
	}
	else if (head == removed) {
		head = removed->rlink;
		if (removed->rlink != NULL)
			removed->rlink->llink = NULL;
		free(removed);
	}
	else {
		removed->llink->rlink = removed->rlink;
		if (removed->rlink != NULL)
			removed->rlink->llink = removed->llink;
		free(removed);
	}
	return head;
}

void print_dlist(DListNode* head) {
	DListNode* p;

	for (p = head; p != NULL; p = p->rlink)
		printf("<-|%d|->", p->data);
	printf("\n");
}

int main() {
	DListNode* head = NULL;
	DListNode* pre = NULL;
	DListNode* removed = NULL;
	printf("삽입 단계\n");
	for (int i = 0; i < 5; i++) {
		// 제일 앞에 노드 삽입
		head = dinsert(head, NULL, i);
		print_dlist(head);
	}

	// 2번째 노드 지정
	pre = head->rlink->rlink->llink;
	// 2번째 노드 뒤에 6 삽입
	head = dinsert(head, pre, 6);
	print_dlist(head);

	pre = head;
	// 마지막 노드 찾기
	while (pre->rlink != NULL)
		pre = pre->rlink;
	// 마지막 노드 뒤에 7 삽입
	head = dinsert(head, pre, 7);
	print_dlist(head);
	// 마지막 노드 지정
	pre = pre->rlink;
	printf("\n");

	// 역순으로 출력
	while (pre != NULL) {
		printf("<-| |%d| |->", pre->data);
		pre = pre->llink;
	}
	printf("\n\n삭제 단계\n");
	head = ddelete(head, head); // 1번째 노드 삭제
	print_dlist(head);

	head = ddelete(head, head->rlink); // 2번째 노드 삭제
	print_dlist(head);

	removed = head;
	while (removed->rlink != NULL) // 마지막 노드 찾기
		removed = removed->rlink;
	pre = removed->llink; // pre를 마지막 이전 노드로 지정
	head = ddelete(head, removed); // 마지막 노드 삭제
	print_dlist(head);

	printf("\n");
	while (pre != NULL) { // 역순으로 출력
		printf("<-| |%d| |->", pre->data);
		pre = pre->llink;
	}
}