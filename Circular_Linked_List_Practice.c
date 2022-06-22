#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_list();

typedef struct node {
	int bomb; // 폭탄(1:있음, 0:없음)
	struct node* link;
} Node;

Node* CL = NULL; // 헤드 포인터

int main() {
	Node* p, * new, * mid;
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	// 헤드 포인터에 1번째 노드 연결하기
	CL = new;


	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	// 1번째 노드 뒤에 2번째 노드 연결하기
	p = CL; // p가 1번째 노드를 가리키게 함
	p->link = new;


	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	// 2번째 노드 뒤에 3번째 노드 원형으로 연결하기
	p = p->link; // p가 2번째 노드를 가리키게 함
	p->link = new;
	new->link = CL;
	print_list();

	// 4번째 노드 생성하기
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;

	// 마지막에 4번째 노드 연결하기
	p = p->link; // p가 마지막(3번째) 노드를 가리키게 함
	new->link = CL;
	p->link = new;

	// 5번째 노드 생성하기
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;

	// 리스트 처음에 5번째 노드 연결하기
	p = p->link; // p가 마지막(4번째) 노드를 가리키게 함
	new->link = CL;
	p->link = new;
	CL = new;

	print_list();

	mid = p;

	int bombCount = 0;
	do {
		bombCount += p->bomb;
		p = p->link;
	} while (p != mid);

	printf("Bomb Count is %d!!!\n\n", bombCount);

	Node* del;
	p = CL;
	while (p->link != CL)
		p = p->link;

	del = p->link;
	p->link = del->link;
	CL = del->link;
	free(del);
	print_list();
}

// 원형 연결 리스트 출력하기
void print_list() {
	Node* p;
	p = CL;
	printf("( ");
	if (CL != NULL) { // 공백 리스트가 아니면
		do {
			printf("%d ", p->bomb); // 폭탄 여부 출력
			p = p->link; // 다음 노드로 이동
		} while (p != CL); // 첫번째 노드가 아닌 동안
	}

	printf(")\n\n");
}