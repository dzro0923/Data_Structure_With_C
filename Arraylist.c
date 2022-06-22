#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996) 
#define MAX_IOT_LIST_SIZE 45

typedef struct {
	char name[20]; //이름
	int id;		   //학번
} Namecard;

Namecard iot_list[MAX_IOT_LIST_SIZE];  //학생 정보를 저장할 배열
int length;							   //리스트의 길이

Namecard make_Namecard(char name[], int id) {	//Namecard 생성 함수
	Namecard newCard;

	strcpy(newCard.name, name);
	newCard.id = id;

	return newCard;
}

//리스트 초기화
void init(void) {
	length = 0;
}

//pos 위치에 새로운 요소 item을 삽입하는 연산
void insert(int pos, Namecard item) {
	int i;

	if (is_full() == 0 && pos >= 0 && pos <= length) {
		for (i = length; i > pos; i--)
			iot_list[i] = iot_list[i - 1];
		iot_list[pos] = item;
		length++;
	}
	else
		printf("포화상태 오류 또는 삽입 위치 오류\n");
}

// pos 위치에 있는 요소를 삭제하는 연산
void delete(int pos) {
	int i;
	if (is_empty() == 0 && pos >= 0 && pos < length) {
		for (i = pos; i < length - 1; i++) {
			iot_list[i] = iot_list[i + 1];
		}
		length--;
	}
	else {
		printf("공백상태 오류 또는 삭제 위치 오류\n");
	}
}

// pos 위치에 있는 요소를 반환하는 연산
Namecard get_entry(int pos) {
	if (pos <= length && pos > 0) {
		return iot_list[pos];
	}
	else {
		printf("에러\n");
	}
}

// 리스트 공백확인 연산
int is_empty(void) {
	if (length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// 리스트 포화확인 연산
int is_full(void) {
	if (length == MAX_IOT_LIST_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

// 리스트에 요소 item이 있는지 살피는 연산
int find(Namecard item) {
	for (int i = 0; i < length; i++) {
		if (iot_list[i].id == item.id && strcmp(iot_list[i].name, item.name) == 0) {
			return i;
		}
	}
	return -1;
}

// pos 위치를 새로운 요소 item을 바꾸는 연산
void replace(int pos, Namecard item) {
	if (pos >= 0 && pos < length) {
		iot_list[pos] = item;
	}
	else {
		printf("교체 위치 오류\n");
	}
}

// 리스트 안의 요소의 개수를 파악하는 연산
int size(void) {
	return length;
}

// 리스트 안의 모든 요소를 출력하는 연산
void print_list(char* msg) {
	if (msg) {
		printf("%s: ", msg);
		if (msg == "init") {
			printf("\n");
		}
	}

	for (int i = 0; i < length; i++) {
		printf(" (%s, %d) ", iot_list[i].name, iot_list[i].id);
		if (i == (length - 1)) {
			printf("\n");
		}
	}
	printf("\n");
}

// 리스트를 거꾸로 출력하는 연산
void sort_list(void) {
	Namecard temp;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (iot_list[i].id < iot_list[j].id) {
				temp = iot_list[i];
				iot_list[i] = iot_list[j];
				iot_list[j] = temp;
			}
		}
	}
}

int main() {
	init();
	print_list("Init");

	insert(0, make_Namecard("성도영", 20191530));
	insert(0, make_Namecard("서재연", 2011521));
	insert(1, make_Namecard("김준형", 20211516));
	insert(size(), make_Namecard("서승진", 20211506));
	insert(3, make_Namecard("신서연", 20211501));
	insert(size(), make_Namecard("김지연", 20211530));
	insert(10, make_Namecard("김현수", 20211522));
	print_list("Insert");

	replace(size() - 1, make_Namecard("정현", 20211504));
	replace(4, make_Namecard("채경훈", 20211498));
	replace(20, make_Namecard("허정인", 20211490));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");


	sort_list();
	print_list("Sort");

	printf("%s is found at %d\n", "김준형", find(make_Namecard("김준형", 20211516)));
	printf("%s is found at %d\n", "김정우", find(make_Namecard("김정우", 20211526)));
	printf("%s is found at %d\n", "채경훈", find(make_Namecard("채경훈", 20211234)));
}

