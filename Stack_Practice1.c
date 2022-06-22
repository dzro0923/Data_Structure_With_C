#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 // ������ �ִ� ũ��
typedef char element; // ���ڿ� ������ ���� �ڷ����� char�� ����
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
void init_stack(StackType* s) { // ���� �ʱ�ȭ �Լ�
	s->top = -1;
}
int is_empty(StackType* s) { // ���� ���� ���� �Լ�
	return (s->top == -1);
}
int is_full(StackType* s) { // ��ȭ ���� ���� �Լ�
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item) { // ���� �Լ�
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) { // ���� �Լ�
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return
		s->data[(s->top)--];
}
element peek(StackType* s) { // ��ũ �Լ�
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
void reverse(char a[], char b[]) { // ���ڿ��� �������� ��ȯ�ϴ� �Լ�
	int i;
	StackType s;
	init_stack(&s);
	// �ݺ����� �̿��Ͽ� a ���ڿ��� �� ���ڸ� ���ÿ� push
	// �ݺ����� �̿��Ͽ� ������ �� ������ �� ���ڸ� pop�Ͽ� b ���ڿ��� ����
	// �������� '\0' ���� �߰�
	for (i = 0; a[i] != '\0'; i++)
		push(&s, a[i]);

	for (i = 0; is_empty(&s) != 1; i++)
		b[i] = pop(&s);


	b[i] = '\0';
}


int main() {
	char str[100];
	char rev[100];
	while (1) {
		printf("���ڿ��� �Է��ϼ���: ");
		scanf("%s", str);
		reverse(str, rev); // str[]�� ���ڿ��� �������� ������ rev[]�� �����ϴ� �Լ� ȣ��
		printf("����: %s\t ����: %s\n\n", str, rev);
	}
}