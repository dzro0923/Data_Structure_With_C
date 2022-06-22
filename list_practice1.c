#include <stdio.h>
int list[100];
int length = 0;

// ����Ʈ�� pos ��ġ�� item�� �����ϴ� �Լ�
void insert(int pos, int item) {
	int i;
	if (length == 100 || pos < 0 || pos > length) {
		printf("���� ����\n");
		return;
	}
	for (i = length; i > pos; i--)
		list[i] = list[i - 1];

	list[pos] = item;
	length++;
}

//����Ʈ�� ����ϴ� �Լ�
void print_list() {
	int j;
	printf("(");
	for (j = 0; j < length; j++) {

		printf(" %d ", list[j]);

	}
	printf(")\n");
}
// pos ��ġ�� ���Ҹ� �����ϴ� �Լ� 
void delete(int pos) {
	int i;
	if (length == 0 || pos < 0 || pos >= length) {
		printf("���� ����\n");
		return;
	}
	// pos �������� ���������� ���Ҹ� 1ĭ�� �������� �̵�
	// length�� 1 ���ҽ�Ŵ
	for (i = pos; i < length - 1; i++)
		list[i] = list[i + 1];
	length--;
}

int main() {
	insert(0, 10);
	// 20, 30, 40��
	// ���ʴ�� �����Ͽ�
	// (insert() ȣ���Ͽ�)
	// �Ʒ��� ���� ����ؾ� ��
	insert(0, 20);
	insert(1, 30);
	insert(2, 40);
	insert(10, 50);
	print_list();
	// 10, 20�� ���ʴ�� �����Ͽ�
	// (delete() ȣ���Ͽ�)
	// �Ʒ��� ���� ����ؾ� ��
	delete(3);
	delete(0);
	delete(length);
	print_list();
}