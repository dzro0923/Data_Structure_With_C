#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct name_card {
	char name[20];
	int id;
	struct name_card* link;
} Namecard;

Namecard* head = NULL; // ��� ������
// pos ��ġ�� ���(�� ���� ������)�� ã�� �Լ�
// ��ȯ���� NULL�̸�, pos ��ġ�� ��带 ã�� ���� ����
// ��ȯ���� NULL�� �ƴϸ�, pos ��ġ�� ��带 ã�� ����

Namecard* getNode(int pos) {
	Namecard* p;
	p = head;
	for (int i = 0; i < pos; i++) {
		if (p == NULL) // ��ġ ����(�ش� �Ǵ� ��ġ�� ��尡 ����)
			return NULL; // ȣ���Լ��� ���� ��ġ�̹Ƿ�, ���� ó���Ͽ��� ��
		p = p->link;
	}
	return p;
}

Namecard make_Namecard(char name[], int id) { // Namecard ���� �Լ�
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
		printf("���� ��ġ ����\n");
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
		printf("���� ��ġ ����\n");
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
		printf("��ü ��ġ ����\n");
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

	insert(0, make_Namecard("������", 20191530)); // ���� �̸�, �й� �ֱ�
	insert(0, make_Namecard("���翬", 2011521));
	insert(1, make_Namecard("������", 20211516));
	insert(size(), make_Namecard("������", 20211506));
	insert(3, make_Namecard("�ż���", 20211501));
	insert(size(), make_Namecard("������", 20211530));
	insert(10, make_Namecard("������", 20211522));
	print_list("Insert");

	replace(size() - 1, make_Namecard("����", 20211504));
	replace(4, make_Namecard("ä����", 20211498));
	replace(20, make_Namecard("������", 20211490));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");

	printf("%s is found at %d\n", "������", find(make_Namecard("������", 20211516)));
	printf("%s is found at %d\n", "������", find(make_Namecard("������", 20211526)));
	printf("%s is found at %d\n", "ä����", find(make_Namecard("ä����", 20211234)));

	Namecard temp = get_entry(1);

	if (temp.id != -1)
		printf("\nEntry 1: (%s, %d)\n", temp.name, temp.id);
}
