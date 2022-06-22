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

// 함수까지 복사
int checkPalindrome(char str[]) {
	int i;
	StackType s;
	init_stack(&s);
	// str의 모든 문자를 스택에 push (반복문)
	// str의 각 문자와 스택에서 pop한
	// 문자를 비교 (반복문, 스택이 빌 때까지)
	// 다르면, 회문이 아니므로 0 리턴
	// 모두 일치하면, 회문이므로 1 리턴
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
		printf("문자열을 입력하세요: ");
		scanf("%s", str);
		ret = checkPalindrome(str);// 회문 검사 함수 호출

		if (ret == 1)
			printf("회문입니다.\n\n");
		else
			printf("회문이 아닙니다.\n\n");
	}
}
