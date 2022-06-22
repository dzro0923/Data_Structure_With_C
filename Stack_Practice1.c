#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 // 스택의 최대 크기
typedef char element; // 문자열 저장을 위해 자료형을 char로 저장
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
void init_stack(StackType* s) { // 스택 초기화 함수
	s->top = -1;
}
int is_empty(StackType* s) { // 공백 상태 검출 함수
	return (s->top == -1);
}
int is_full(StackType* s) { // 포화 상태 검출 함수
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item) { // 삽입 함수
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) { // 삭제 함수
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return
		s->data[(s->top)--];
}
element peek(StackType* s) { // 피크 함수
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
void reverse(char a[], char b[]) { // 문자열을 역순으로 변환하는 함수
	int i;
	StackType s;
	init_stack(&s);
	// 반복문을 이용하여 a 문자열의 각 문자를 스택에 push
	// 반복문을 이용하여 스택이 빌 때까지 각 문자를 pop하여 b 문자열에 저장
	// 마지막에 '\0' 문자 추가
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
		printf("문자열을 입력하세요: ");
		scanf("%s", str);
		reverse(str, rev); // str[]의 문자열을 역순으로 변경해 rev[]에 저장하는 함수 호출
		printf("원본: %s\t 역순: %s\n\n", str, rev);
	}
}