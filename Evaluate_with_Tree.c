#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct TreeNode{
	element data;
	struct TreeNode* left, * right;
} TreeNode;

// +
// * +
// 1 4 16 25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* exp = &n7;

// root가 가리키는 트리의 수식 계산 함수
// 입력: 계산할 트리의 root 노드, 출력: 수식 계산 결과
int evaluate(TreeNode* root) {
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL) // 단말 노드인 경우, 자신의 값 리턴
		return root->data;
	else {
		int op1 = evaluate(root->left); // 왼쪽 서브트리의 수식 계산
		int op2 = evaluate(root->right); // 오른쪽 서브트리의 수식 계산
		printf("%d %c %d를 계산합니다.\n", op1, root->data, op2);
		// 왼쪽 서브트리와 오른쪽 서브트리의 결과를 이용해서 최종 수식 계산
		switch (root->data) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
	return 0;
}
int main() {
	printf("수식의 값은 %d입니다. \n", evaluate(exp));
}
