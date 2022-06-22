#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5 // 큐의 최대 크기

typedef int element; // 큐 원소의 자료형을 int로 정의
typedef struct { // 큐 구조체
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(QueueType* q) {
	return (q->front ==
		(q->rear + 1) % MAX_QUEUE_SIZE);
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
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void queue_print(QueueType* q) {
	printf("\nQUEUE(front=%d rear=%d) = ",
		q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
		} while (i != q->rear);
	}
	printf("\n");
}

int main() {
	element item;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	printf("삭제데이터: %d\n", item);
		item = dequeue(&q); queue_print(&q);
	printf("삭제데이터: %d\n", item);
		item = dequeue(&q); queue_print(&q);
	printf("삭제데이터: %d\n", item);
		
	enqueue(&q, 40); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	printf("삭제데이터: %d\n", item);
	enqueue(&q, 50); queue_print(&q);
	enqueue(&q, 60); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	printf("삭제데이터: %d\n", item);

	enqueue(&q, 70); queue_print(&q);
	enqueue(&q, 80); queue_print(&q);
	enqueue(&q, 90); queue_print(&q);
	enqueue(&q, 100); queue_print(&q);
}
