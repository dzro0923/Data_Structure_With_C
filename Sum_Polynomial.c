#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // 노드 타입
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

typedef struct ListType { // 리스트 헤더 노드 타입
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 헤더 생성 함수
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon는 지수
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL) // 최초로 리스트에 항을 추가하는 경우
		plist->head = plist->tail = temp;
	else { // 기존에 리스트에 항이 있는 경우
		plist->tail->link = temp; // 마지막 항 뒤에 새로운 항 연결
		plist->tail = temp; // 헤더 노드의 tail 값이
	} // 마지막 노드를 가리키게 함
	plist->size++;
}

void poly_print(ListType* plist) { // 다항식을 화면에 출력하는 함수
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

	while (p && q) { // while (p != NULL && q != NULL)과 동일함
		if (p->expon == q->expon) { // p의 차수 == q의 차수
			sum = p->coef + q->coef;
			if (sum != 0) insert_last(plist3, sum, p->expon);
			p = p->link; q = q->link;
		}
		else if (p->expon > q->expon) { // p의 차수 > q의 차수
			insert_last(plist3, p->coef, p->expon);
			p = p->link;
		}
		else { // p의 차수 < q의 차수
			insert_last(plist3, q->coef, q->expon);
			q = q->link;
		}
	}
	// p나 q중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 결과 다항식으로 복사
	for (; p != NULL; p = p->link)
		insert_last(plist3, p->coef, p->expon);
	for (; q != NULL; q = q->link)
		insert_last(plist3, q->coef, q->expon);
}

int main(void)
{
	ListType* A, * B, * C;
	// 연결 리스트 헤더 노드 생성
	A = create();
	B = create();
	C = create();

	// 다항식 1을 생성
	insert_last(A, 3, 12);
	insert_last(A, 2, 8);
	insert_last(A, 1, 0);

	// 다항식 2를 생성
	insert_last(B, 8, 12);
	insert_last(B, -3, 10);
	insert_last(B, 10, 6);

	poly_print(A);
	poly_print(B);

	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(A, B, C);
	poly_print(C);

	free(A); free(B); free(C);
}