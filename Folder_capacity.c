#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
} TreeNode;

int calc_dir_size(TreeNode* root) { // �Է�: �ش� Ʈ���� root ���, ���: Ʈ���� �뷮
	int left_size, right_size;
	if (root == NULL) return 0;
	left_size = calc_dir_size(root->left); // ���� ����Ʈ���� �뷮 ���
	right_size = calc_dir_size(root->right); // ������ ����Ʈ���� �뷮 ���
	return (root->data + left_size + right_size); // ���� ����Ʈ���� �뷮 ���
}

int main() {
	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };
	printf("������ �뷮: %d KB\n", calc_dir_size(&n1));
}
