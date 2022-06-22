#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
#pragma warning(disable:4996)

typedef char element[100];
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current; // 현재 재생중인 노래를 가리키는 포인터

DListNode* dinsert(DListNode* head, DListNode* pre, element value) {
	DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
	strcpy(new_node->data, value);

	if (head == NULL) {
		head = new_node;
		new_node->rlink = NULL;
		new_node->llink = NULL;
	}
	else if (pre == NULL) {
		new_node->rlink = head;
		head = new_node;
		new_node->llink = NULL;
		new_node->rlink->llink = new_node;
	}
	else {
		new_node->rlink = pre->rlink;
		pre->rlink = new_node;
		new_node->llink = pre;
		if (new_node->rlink != NULL)
			new_node->rlink->llink = new_node;
	}
	return head;
}

DListNode* ddelete(DListNode* head, DListNode* removed) {
	if (head == NULL)
		printf("ddelete() error\n");
	else if (head == removed) {
		head = removed->rlink;
		if (removed->rlink != NULL)
			removed->rlink->llink = NULL;
		free(removed);
	}
	else {
		removed->llink->rlink = removed->rlink;
		if (removed->rlink != NULL)
			removed->rlink->llink = removed->llink;
		free(removed);
	}
	return head;
}

void print_dlist(DListNode* head) {
	DListNode* p;

	for (p = head; p != NULL; p = p->rlink) {
		if (p == current)
			printf("<-| #%s# |->", p->data);
		else
			printf("<-| %s |->", p->data);
	}
	printf("\n");
}

int main() {
	DListNode* head = NULL;
	char filename[100];
	char ch;

	// 이중 연결 리스트에 노래 삽입
	head = dinsert(head, NULL, "The Next Right Thing");
	head = dinsert(head, NULL, "Show Yourself");
	head = dinsert(head, NULL, "Into The Unknown-1");
	head = dinsert(head, NULL, "All Is Found");

	//첫 번째 노래를 재생
	current = head;
	print_dlist(head);

	strcpy(filename, current->data);
	strcat(filename, ".wav");
	PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC); // filename에 해당하는 노래를 재생하는 함수

	do {
		printf("\n명령어를 입력하시오(<,>,q): ");
		ch = getch();	// 1개의 문자를 입력받는 함수, 엔터를 입력하지 않아도 됨
		printf("\n\n\n");

		if (ch == '<') {
			if (current->llink != NULL) {	//왼쪽 노드가 존재하는 경우, 왼쪽으로 이동 후, 해당 노래를 재생
				current = current->llink;
				print_dlist(head);

				strcpy(filename, current->data);
				strcat(filename, ".wav");
				PlaySoundA(NULL, NULL, NULL); // 현재 재생 중인 노래를 종료
				PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC);
			}
			else {
				printf(" 첫 번째 노래입니다.\n"); //왼쪽 노드가 없는 경우, 메시지 출력
			}
		}
		else if (ch == '>') {
			if (current->rlink != NULL) {	//오른쪽 노드가 존재하는 경우, 오른쪽으로 이동 후, 해당 노래 재생
				current = current->rlink;
				print_dlist(head);

				strcpy(filename, current->data);
				strcat(filename, ".wav");
				PlaySoundA(NULL, NULL, NULL); // 현재 재생 중인 노래를 종료
				PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC);
			}
			else {
				printf(" 마지막 노래입니다. \n");
			}
		}
	} while (ch != 'q');
}

