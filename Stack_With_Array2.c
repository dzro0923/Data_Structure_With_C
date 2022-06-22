#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // 스택의 최대 크기

typedef int element; // 데이터의 자료형
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

// 피크 함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

// 스택의 원소를 출력하는 함수
void printStack(StackType* s) {
	printf("STACK [");
	for (int i = 0; i <= s->top; i++)
		printf("%d ", s->data[i]);

	printf("] \n");
}

int main() {
	StackType s;

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printStack(&s);
	printf("pop\t=> %d\t", pop(&s));
	printStack(&s);
	printf("peek\t=> %d\t", peek(&s));
	printStack(&s);
	printf("pop\t=> %d\t", pop(&s));
	printStack(&s);
	printf("pop\t=> %d\t", pop(&s));
	printStack(&s);
}