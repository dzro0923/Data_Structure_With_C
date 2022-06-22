#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

int main() {
	ListNode* head = NULL;
	ListNode* p;

	// 1��° ��� ���� �� ��� �����Ϳ� �����ϱ�
	head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 10;
	head->link = NULL;

	// 2��° ��� ���� �� �����ϱ�
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = 20;
	p->link = NULL;

	head->link = p;

	// 3��° ��� ���� �� �����ϱ�
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = 30;
	p->link = NULL;

	head->link->link = p;

	//head �����͸� �̿��Ͽ� A, B, C�� data ���
	printf("A: %d\n", head->data);
	printf("B: %d\n", head->link->data);
	printf("C: %d\n", head->link->link->data);
}