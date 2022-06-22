#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 50
#define MAZE_SIZE 7

typedef struct { // 가용한 경로의 위치를 나타내는 구조체(행, 열)
	int row;
	int col;
} element;

typedef struct { // 경로 위치를 저장하는 큐
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

element here = { 1, 0 }; // 현재 위치. (1, 0)에서 시작

char maze[MAZE_SIZE][MAZE_SIZE] = {
{'1', '1', '1', '1', '1', '1', '1'},
{'0', '0', '1', '0', '0', '0', '0'},
{'1', '0', '0', '0', '1', '0', '1'},
{'1', '0', '1', '0', '1', '0', '1'},
{'0', '0', '1', '1', '0', '0', '1'},
{'1', '0', '1', '0', '0', '1', 'x'},
{'1', '0', '1', '1', '0', '0', '0'},
};

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}
void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}
int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
void pushLocation(QueueType* q, int row, int col) { // 탐색할 위치를 큐에 넣는 함수
	//스택 코드 참조
	//(row, col)을 스택에 push()하는 대신, 원형 큐 q에 enqueue() 시키면 됨

	if (row<0 || row>(MAZE_SIZE - 1) || col<0 || col>(MAZE_SIZE - 1))
		return;

	if (maze[row][col] != '1' && maze[row][col] != '.') {
		element temp;
		temp.row = row;
		temp.col = col;
		enqueue(q, temp);
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
	QueueType q; // 큐 생성
	init_queue(&q); // 큐 초기화
	//스택 관련 연산을 큐 연산으로 변경.그 외 동일함

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
		pushLocation(&q, r - 1, c); // 위쪽 위치 삽입
		pushLocation(&q, r + 1, c); // 아래쪽 위치 삽입
		pushLocation(&q, r, c - 1); // 왼쪽 위치 삽입
		pushLocation(&q, r, c + 1); // 오른쪽 위치 삽입

		if (is_empty(&q)) { // 다음 탐색할 위치를 스택에서 꺼내기
			printf("실패\n");
			return 0;
		}
		else
			here = dequeue(&q);// 스택에서 위치 1개를 꺼내어 현재의 위치(here)로 설정
	}
	//출구를 찾은 경우

	maze[here.row][here.col] = 'm';
	printMaze();
	printf("성공\n");
}
