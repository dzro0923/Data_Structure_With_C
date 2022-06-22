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

	// 1번째 노드 생성 및 헤드 포인터에 연결하기
	head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 10;
	head->link = NULL;

	// 2번째 노드 생성 및 연결하기
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = 20;
	p->link = NULL;

	head->link = p;

	// 3번째 노드 생성 및 연결하기
	p = (ListNode*)malloc(sizeof(ListNode));
	p->data = 30;
	p->link = NULL;

	head->link->link = p;

	//head 포인터를 이용하여 A, B, C의 data 출력
	printf("A: %d\n", head->data);
	printf("B: %d\n", head->link->data);
	printf("C: %d\n", head->link->link->data);
}