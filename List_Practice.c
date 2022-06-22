#include <stdio.h>
int list[100];
int length = 0;

// 리스트의 pos 위치에 item을 삽입하는 함수
void insert(int pos, int item) {
	int i;
	if (length == 100 || pos < 0 || pos > length) {
		printf("삽입 에러\n");
		return;
	}
	for (i = length; i > pos; i--)
		list[i] = list[i - 1];

	list[pos] = item;
	length++;
}

//리스트를 출력하는 함수
void print_list() {
	int j;
	printf("(");
	for (j = 0; j < length; j++) {

		printf(" %d ", list[j]);

	}
	printf(")\n");
}
// pos 위치의 원소를 삭제하는 함수 
void delete(int pos) {
	int i;
	if (length == 0 || pos < 0 || pos >= length) {
		printf("삭제 에러\n");
		return;
	}
	// pos 다음부터 마지막까지 원소를 1칸씩 왼쪽으로 이동
	// length를 1 감소시킴
	for (i = pos; i < length - 1; i++)
		list[i] = list[i + 1];
	length--;
}

int main() {
	insert(0, 10);
	// 20, 30, 40을
	// 차례대로 삽입하여
	// (insert() 호출하여)
	// 아래와 같이 출력해야 함
	insert(0, 20);
	insert(1, 30);
	insert(2, 40);
	insert(10, 50);
	print_list();
	// 10, 20을 차례대로 삭제하여
	// (delete() 호출하여)
	// 아래와 같이 출력해야 함
	delete(3);
	delete(0);
	delete(length);
	print_list();
}
