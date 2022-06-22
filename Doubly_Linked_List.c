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
	printf("���� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		// ���� �տ� ��� ����
		head = dinsert(head, NULL, i);
		print_dlist(head);
	}

	// 2��° ��� ����
	pre = head->rlink->rlink->llink;
	// 2��° ��� �ڿ� 6 ����
	head = dinsert(head, pre, 6);
	print_dlist(head);

	pre = head;
	// ������ ��� ã��
	while (pre->rlink != NULL)
		pre = pre->rlink;
	// ������ ��� �ڿ� 7 ����
	head = dinsert(head, pre, 7);
	print_dlist(head);
	// ������ ��� ����
	pre = pre->rlink;
	printf("\n");

	// �������� ���
	while (pre != NULL) {
		printf("<-| |%d| |->", pre->data);
		pre = pre->llink;
	}
	printf("\n\n���� �ܰ�\n");
	head = ddelete(head, head); // 1��° ��� ����
	print_dlist(head);

	head = ddelete(head, head->rlink); // 2��° ��� ����
	print_dlist(head);

	removed = head;
	while (removed->rlink != NULL) // ������ ��� ã��
		removed = removed->rlink;
	pre = removed->llink; // pre�� ������ ���� ���� ����
	head = ddelete(head, removed); // ������ ��� ����
	print_dlist(head);

	printf("\n");
	while (pre != NULL) { // �������� ���
		printf("<-| |%d| |->", pre->data);
		pre = pre->llink;
	}
}