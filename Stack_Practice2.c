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

// �Լ����� ����
int checkPalindrome(char str[]) {
	int i;
	StackType s;
	init_stack(&s);
	// str�� ��� ���ڸ� ���ÿ� push (�ݺ���)
	// str�� �� ���ڿ� ���ÿ��� pop��
	// ���ڸ� �� (�ݺ���, ������ �� ������)
	// �ٸ���, ȸ���� �ƴϹǷ� 0 ����
	// ��� ��ġ�ϸ�, ȸ���̹Ƿ� 1 ����
	for (i = 0; str[i] != '\0'; i++) {
		push(&s, str[i]);
	}
	for (i = 0; is_empty(&s) != 1; i++) {
		if (str[i] == pop(&s))
			return 1;
		else
			return 0;
	}


}

int main() {
	char str[100];
	int ret;
	while (1) {
		printf("���ڿ��� �Է��ϼ���: ");
		scanf("%s", str);
		ret = checkPalindrome(str);// ȸ�� �˻� �Լ� ȣ��

		if (ret == 1)
			printf("ȸ���Դϴ�.\n\n");
		else
			printf("ȸ���� �ƴմϴ�.\n\n");
	}
}
