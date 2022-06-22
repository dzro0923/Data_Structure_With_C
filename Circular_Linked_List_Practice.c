#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_list();

typedef struct node {
	int bomb; // ��ź(1:����, 0:����)
	struct node* link;
} Node;

Node* CL = NULL; // ��� ������

int main() {
	Node* p, * new, * mid;
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	// ��� �����Ϳ� 1��° ��� �����ϱ�
	CL = new;


	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	// 1��° ��� �ڿ� 2��° ��� �����ϱ�
	p = CL; // p�� 1��° ��带 ����Ű�� ��
	p->link = new;


	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;
	// 2��° ��� �ڿ� 3��° ��� �������� �����ϱ�
	p = p->link; // p�� 2��° ��带 ����Ű�� ��
	p->link = new;
	new->link = CL;
	print_list();

	// 4��° ��� �����ϱ�
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;

	// �������� 4��° ��� �����ϱ�
	p = p->link; // p�� ������(3��°) ��带 ����Ű�� ��
	new->link = CL;
	p->link = new;

	// 5��° ��� �����ϱ�
	new = (Node*)malloc(sizeof(Node));
	new->bomb = rand() % 2;
	new->link = NULL;

	// ����Ʈ ó���� 5��° ��� �����ϱ�
	p = p->link; // p�� ������(4��°) ��带 ����Ű�� ��
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

// ���� ���� ����Ʈ ����ϱ�
void print_list() {
	Node* p;
	p = CL;
	printf("( ");
	if (CL != NULL) { // ���� ����Ʈ�� �ƴϸ�
		do {
			printf("%d ", p->bomb); // ��ź ���� ���
			p = p->link; // ���� ���� �̵�
		} while (p != CL); // ù��° ��尡 �ƴ� ����
	}

	printf(")\n\n");
}