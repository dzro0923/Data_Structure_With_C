#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 //������ �ִ� ũ��

typedef int element; // �������� �ڷ���
element stack[MAX_STACK_SIZE]; //1���� �迭
int top = -1;

// ���� ���� ���� �Լ�
int is_empty() {
	return (top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		stack[++top] = item;
}

// ���� �Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return stack[top--];
}

// ��ũ �Լ�
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return stack[top];
}

// ������ ���Ҹ� ����ϴ� �Լ�
void printStack() {
	printf("STACK [ ");
	for (int i = 0; i <= top; i++)
		printf("%d ", stack[i]);

	printf("]\n");
}

int main() {
	push(1);
	push(2);
	push(3);
	printStack();
	printf("pop\t=> %d\t", pop());
	printStack();
	printf("peek\t=> %d\t", peek());
	printStack();
	printf("pop\t=> %d\t", pop());
	printStack();
	printf("pop\t=> %d\t", pop());
	printStack();
}
