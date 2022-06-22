#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100 // ������ �ִ� ũ��
#define MAZE_SIZE 7 // �̷��� ũ��
typedef struct { // ��ġ ����ü�� ���ÿ� ����
	int row;
	int col;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

element here = { 1, 0 }; // ���� ��ġ�� ��Ÿ��. (1, 0)���� ����

char maze[MAZE_SIZE][MAZE_SIZE] = { // �̷�. �̷��� ��ġ�� ��� ���� ��Ÿ��
{'1', '1', '1', '1', '1', '1', '1'}, // maze[��][��]�� �ش� ��ġ�� �̷��� ����
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
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

void pushLocation(StackType* s, int row, int col) {
	//Ž���� ��ġ�� row�� 0~MAX_SIZE - 1, col�� 0~MAX_SIZE - 1�̾����
	//Ž���� ��ġ�� �̷� ���� ��ġ�̸� ���ÿ� ���� �ʰ�, return ��
	if (row<0 || row>(MAZE_SIZE - 1) || col<0 || col>(MAZE_SIZE - 1))
		return;
	//���� �ƴϰ�, �湮���� �ʾ����� Ž���� ��ġ�� element ����ü�� ������ ���ÿ� push
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
	maze[here.row][here.col] = 'e'; // ���� ��ġ�� 'e'�� ǥ��
	printMaze(); // ���� �̷� ���
	getchar(); // ���͸� ������ �������� �Ѿ
	while (maze[here.row][here.col] != 'x') { // ���� ��ġ�� �ⱸ�� �ƴϸ�
		r = here.row;
		c = here.col;
		maze[r][c] = 'm'; // ���� ��ġ�� 'm'���� ǥ��
		printMaze(); // ���� �̷� ���
		getchar(); // ���͸� ������ �������� �Ѿ
		maze[r][c] = '.';// ���� ��ġ�� �湮�� ������ ǥ��
		pushLocation(&s, r - 1, c); // ���� ��ġ ����
		pushLocation(&s, r + 1, c); // �Ʒ��� ��ġ ����
		pushLocation(&s, r, c - 1); // ���� ��ġ ����
		pushLocation(&s, r, c + 1); // ������ ��ġ ����
		if (is_empty(&s)) { // ���� Ž���� ��ġ�� ���ÿ��� ������
			printf("����\n");
			return 0;
		}
		else
			here = pop(&s);// ���ÿ��� ��ġ 1���� ������ ������ ��ġ(here)�� ����
	}
	//�ⱸ�� ã�� ���
	maze[here.row][here.col] = 'm';
	printMaze();
	printf("����\n");


}