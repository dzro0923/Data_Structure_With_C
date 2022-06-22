#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct name_card {
	char name[20];
	int id;
	struct name_card* link;
} Namecard;

Namecard* head = NULL; // 헤드 포인터
// pos 위치의 노드(에 대한 포인터)를 찾는 함수
// 반환값이 NULL이면, pos 위치의 노드를 찾지 못한 것임
// 반환값이 NULL이 아니면, pos 위치의 노드를 찾은 것임

Namecard* getNode(int pos) {
	Namecard* p;
	p = head;
	for (int i = 0; i < pos; i++) {
		if (p == NULL) // 위치 오류(해당 되는 위치의 노드가 없음)
			return NULL; // 호출함수는 없는 위치이므로, 에러 처리하여야 함
		p = p->link;
	}
	return p;
}

Namecard make_Namecard(char name[], int id) { // Namecard 생성 함수
	Namecard newCard;
	strcpy(newCard.name, name);
	newCard.id = id;
	newCard.link = NULL;
	return newCard;
}

void init() {
	Namecard* p, * removed;
	for (p = head; p != NULL;) {
		removed = p;
		p = p->link;
		free(removed);
	}
	head = NULL;
}

int is_empty(void) {
	if (head == NULL)
		return 1;
	else
		return 0;
}

void insert(int pos, Namecard item) {
	if (pos<0 || pos> size()) {
		printf("삽입 위치 오류\n");
		return;
	}
	Namecard* p = (Namecard*)malloc(sizeof(Namecard));
	if (p == NULL)
		return;
	strcpy(p->name, item.name);
	p->id = item.id;
	p->link = NULL;
	if (head == NULL || pos == 0) {
		p->link = head;
		head = p;
	}
	else {
		Namecard* pre;
		pre = head;
		int i = 1;
		while (i < pos) {
			pre = pre->link;
			i++;
		}
		p->link = pre->link;
		pre->link = p;
	}
}

void delete(int pos) {
	if (pos<0 || pos>size() || head == NULL) {
		printf("삭제 위치 오류\n");
		return;
	}
	Namecard* remove;
	if (pos == 0) {
		remove = head;
		head = remove->link;
		free(remove);
	}
	else {
		Namecard* real;
		int i = 1;
		remove = head;
		while (i < pos) {
			remove = remove->link;
			i++;
		}
		real = remove->link;
		remove->link = real->link;
		free(real);
	}
}

Namecard get_entry(int pos) {
	Namecard* p;
	Namecard re;
	if (pos > size() || pos < 0) {
		re.id = -1;
		return re;
	}
	p = head;
	for (int i = 0; i < pos; i++) {
		p = p->link;
	}

	strcpy(re.name, p->name);
	re.id = p->id;
	return re;
}

int find(Namecard item) {
	Namecard* p;
	for (p = head; p != NULL; p = p->link) {
		if (strcmp(p->name, item.name) == 0 && p->id == item.id) {
			return 0;
		}
	}
	return -1;
}


void replace(int pos, Namecard item) {
	if (pos < 0 || pos > size()) {
		printf("교체 위치 오류\n");
		return;
	}
	Namecard* p;
	p = head;
	int i = 1;
	while (i <= pos) {
		p = p->link;
		i++;
	}
	strcpy(p->name, item.name);
	p->id = item.id;
}

int size(void) {
	Namecard* p;
	int i = 0;
	p = head;
	while (p != NULL) {
		p = p->link;
		i++;
	}
	return i;
}

void print_list(char* msg) {
	Namecard* p = (Namecard*)malloc(sizeof(Namecard));
	if (msg) {
		printf("%s: ", msg);
		if (msg == "Init") printf("\n");
	}
	for (p = head; p != NULL; p = p->link) {
		printf(" (%s , %d) ", p->name, p->id);
		if (p->link == NULL) {
			printf("\n");
		}
	}
	printf("\n");
}

int main() {
	init();
	print_list("Init");

	insert(0, make_Namecard("성도영", 20191530)); // 본인 이름, 학번 넣기
	insert(0, make_Namecard("서재연", 2011521));
	insert(1, make_Namecard("김준형", 20211516));
	insert(size(), make_Namecard("서승진", 20211506));
	insert(3, make_Namecard("신서연", 20211501));
	insert(size(), make_Namecard("김지연", 20211530));
	insert(10, make_Namecard("김현수", 20211522));
	print_list("Insert");

	replace(size() - 1, make_Namecard("정현", 20211504));
	replace(4, make_Namecard("채경훈", 20211498));
	replace(20, make_Namecard("허정인", 20211490));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");

	printf("%s is found at %d\n", "김준형", find(make_Namecard("김준형", 20211516)));
	printf("%s is found at %d\n", "김정우", find(make_Namecard("김정우", 20211526)));
	printf("%s is found at %d\n", "채경훈", find(make_Namecard("채경훈", 20211234)));

	Namecard temp = get_entry(1);

	if (temp.id != -1)
		printf("\nEntry 1: (%s, %d)\n", temp.name, temp.id);
}
