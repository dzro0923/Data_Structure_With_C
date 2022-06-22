#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int bomb; // ��ź(1:����, 0:����)
	struct node* llink;
	struct node* rlink;
} Node;


Node* DL = NULL; // ��� ������

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
	new->bomb = rand() % 2; // ����� bomb �ʵ忡 �������� 0 �Ǵ� 1�� ����
	new->llink = NULL;
	new->rlink = NULL;
	// ��� �����Ϳ� 1��° ��� �����ϱ�
	DL = new;

	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	// 1��° ��� �ڿ� 2��° ��� �����ϱ�
	p = DL; // p�� 1��° ��带 ����Ű�� ��
	p->rlink = new;
	new->llink = p;

	// 1��° ��� �ڿ� 3��° ��� �����ϱ�
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	p = DL; // p�� 1��° ��带 ����Ű�� ��
	new->rlink = p->rlink;
	p->rlink = new;
	new->llink = p;
	new->rlink->llink = new;

	// �������� 4��° ��� �����ϱ�
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->llink = NULL;
	new->rlink = NULL;
	p = p->rlink->rlink; // p�� 3��° ��带 ����Ű�� ��
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

