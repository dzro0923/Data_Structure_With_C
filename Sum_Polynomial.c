#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // ��� Ÿ��
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

typedef struct ListType { // ����Ʈ ��� ��� Ÿ��
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ ��� ���� �Լ�
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist�� ���� ����Ʈ�� ����� ����Ű�� ������, coef�� ���, expon�� ����
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("�޸� �Ҵ� ����");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL) // ���ʷ� ����Ʈ�� ���� �߰��ϴ� ���
		plist->head = plist->tail = temp;
	else { // ������ ����Ʈ�� ���� �ִ� ���
		plist->tail->link = temp; // ������ �� �ڿ� ���ο� �� ����
		plist->tail = temp; // ��� ����� tail ����
	} // ������ ��带 ����Ű�� ��
	plist->size++;
}

void poly_print(ListType* plist) { // ���׽��� ȭ�鿡 ����ϴ� �Լ�
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx^%d", p->coef, p->expon);
		if (p->link != NULL)
			printf(" + ");
	}
	printf("\n");
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* p = plist1->head;
	ListNode* q = plist2->head;
	int sum;

	while (p && q) { // while (p != NULL && q != NULL)�� ������
		if (p->expon == q->expon) { // p�� ���� == q�� ����
			sum = p->coef + q->coef;
			if (sum != 0) insert_last(plist3, sum, p->expon);
			p = p->link; q = q->link;
		}
		else if (p->expon > q->expon) { // p�� ���� > q�� ����
			insert_last(plist3, p->coef, p->expon);
			p = p->link;
		}
		else { // p�� ���� < q�� ����
			insert_last(plist3, q->coef, q->expon);
			q = q->link;
		}
	}
	// p�� q���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ��� ��� ���׽����� ����
	for (; p != NULL; p = p->link)
		insert_last(plist3, p->coef, p->expon);
	for (; q != NULL; q = q->link)
		insert_last(plist3, q->coef, q->expon);
}

int main(void)
{
	ListType* A, * B, * C;
	// ���� ����Ʈ ��� ��� ����
	A = create();
	B = create();
	C = create();

	// ���׽� 1�� ����
	insert_last(A, 3, 12);
	insert_last(A, 2, 8);
	insert_last(A, 1, 0);

	// ���׽� 2�� ����
	insert_last(B, 8, 12);
	insert_last(B, -3, 10);
	insert_last(B, 10, 6);

	poly_print(A);
	poly_print(B);

	// ���׽� 3 = ���׽� 1 + ���׽� 2
	poly_add(A, B, C);
	poly_print(C);

	free(A); free(B); free(C);
}