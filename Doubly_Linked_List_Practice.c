#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int bomb; // 폭탄(1:있음, 0:없음)
	struct node* llink;
	struct node* rlink;
} Node;


Node* DL = NULL; // 헤드 포인터

void print_list() {
	Node* p;
	p = DL;
	printf("( ");
	while (p != NULL) {
		printf("%d ", p->bomb);
		p = p->rlink;
	}
	printf(")\n\n");
}

int main() {
	Node* p, * new;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2; // 노드의 bomb 필드에 무작위로 0 또는 1을 넣음
	new->llink = NULL;
	new->rlink = NULL;
	// 헤드 포인터에 1번째 노드 연결하기
	DL = new;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	// 1번째 노드 뒤에 2번째 노드 연결하기
	p = DL; // p가 1번째 노드를 가리키게 함
	p->rlink = new;
	new->llink = p;

	// 1번째 노드 뒤에 3번째 노드 연결하기
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	p = DL; // p가 1번째 노드를 가리키게 함
	new->rlink = p->rlink;
	p->rlink = new;
	new->llink = p;
	new->rlink->llink = new;

	// 마지막에 4번째 노드 연결하기
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	p = p->rlink->rlink; // p가 3번째 노드를 가리키게 함
	p->rlink = new;
	new->rlink = NULL;
	new->llink = p;
	print_list();


	p = DL;

	while (p->rlink != NULL)
		p = p->rlink;

	int bombCount = 0;
	while (p != NULL) {
		bombCount += p->bomb;
		p = p->llink;
	}

	printf("Bomb Count is %d!!\n\n", bombCount);
}

