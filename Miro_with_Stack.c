#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100 // 스택의 최대 크기
#define MAZE_SIZE 7 // 미로의 크기
typedef struct { // 위치 구조체를 스택에 저장
	int row;
	int col;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

element here = { 1, 0 }; // 현재 위치를 나타냄. (1, 0)에서 시작

char maze[MAZE_SIZE][MAZE_SIZE] = { // 미로. 미로의 위치는 행과 열로 나타냄
{'1', '1', '1', '1', '1', '1', '1'}, // maze[행][열]이 해당 위치의 미로의 상태
{'0', '0', '1', '0', '0', '0', '0'},
{'1', '0', '0', '0', '1', '0', '1'},
{'1', '0', '1', '0', '1', '0', '1'},
{'0', '0', '1', '1', '0', '0', '1'},
{'1', '0', '1', '0', '0', '1', 'x'},
{'1', '0', '1', '1', '0', '0', '0'},
};

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

void pushLocation(StackType* s, int row, int col) {
	//탐색할 위치는 row가 0~MAX_SIZE - 1, col이 0~MAX_SIZE - 1이어야함
	//탐색할 위치가 미로 밖의 위치이면 스택에 넣지 않고, return 함
	if (row<0 || row>(MAZE_SIZE - 1) || col<0 || col>(MAZE_SIZE - 1))
		return;
	//벽이 아니고, 방문하지 않았으면 탐색할 위치를 element 구조체에 저장한 스택에 push
	if (maze[row][col] != '1' && maze[row][col] != '.') {
		element temp;
		temp.row = row;
		temp.col = col;
		push(s, temp);
	}
}

void printMaze() {
	system("cls");
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++)
			printf("%c ", maze[i][j]);
		printf("\n");
	}
}

int main() {
	int r, c;
	StackType s;
	init_stack(&s);
	maze[here.row][here.col] = 'e'; // 시작 위치를 'e'로 표시
	printMaze(); // 현재 미로 출력
	getchar(); // 엔터를 누르면 다음으로 넘어감
	while (maze[here.row][here.col] != 'x') { // 현재 위치가 출구가 아니면
		r = here.row;
		c = here.col;
		maze[r][c] = 'm'; // 현재 위치를 'm'으로 표시
		printMaze(); // 현재 미로 출력
		getchar(); // 엔터를 누르면 다음으로 넘어감
		maze[r][c] = '.';// 현재 위치를 방문한 것으로 표시
		pushLocation(&s, r - 1, c); // 위쪽 위치 삽입
		pushLocation(&s, r + 1, c); // 아래쪽 위치 삽입
		pushLocation(&s, r, c - 1); // 왼쪽 위치 삽입
		pushLocation(&s, r, c + 1); // 오른쪽 위치 삽입
		if (is_empty(&s)) { // 다음 탐색할 위치를 스택에서 꺼내기
			printf("실패\n");
			return 0;
		}
		else
			here = pop(&s);// 스택에서 위치 1개를 꺼내어 현재의 위치(here)로 설정
	}
	//출구를 찾은 경우
	maze[here.row][here.col] = 'm';
	printMaze();
	printf("성공\n");


}