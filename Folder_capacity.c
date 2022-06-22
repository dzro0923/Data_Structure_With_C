#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
} TreeNode;

int calc_dir_size(TreeNode* root) { // 입력: 해당 트리의 root 노드, 출력: 트리의 용량
	int left_size, right_size;
	if (root == NULL) return 0;
	left_size = calc_dir_size(root->left); // 왼쪽 서브트리의 용량 계산
	right_size = calc_dir_size(root->right); // 오른쪽 서브트리의 용량 계산
	return (root->data + left_size + right_size); // 최종 서브트리의 용량 계산
}

int main() {
	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };
	printf("폴더의 용량: %d KB\n", calc_dir_size(&n1));
}
