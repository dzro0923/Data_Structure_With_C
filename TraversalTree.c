#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct TreeNode{
	element data;
	struct TreeNode* left, * right;
} TreeNode;

// 15
// 4 20
// 1 16 25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

void preorder(TreeNode* root) { // ���� ��ȸ
	if
		(root != NULL) {
		printf
		("%d ", root
			->data); // ��� �湮
		preorder(root
			->left); // ���� ����Ʈ�� ��ȸ
		preorder(root
			->right); // ������ ����Ʈ�� ��ȸ
	}
}

void inorder(TreeNode* root) { // ���� ��ȸ
	if(root != NULL) {
		inorder(root->left); // ���� ����Ʈ�� ��ȸ
		printf("%d ", root->data); // ��� �湮
		inorder(root->right); // ������ ����Ʈ�� ��ȸ
	}
}

void postorder(TreeNode* root) { // ���� ��ȸ
	if(root != NULL) {
		postorder(root->left); // ���� ����Ʈ�� ��ȸ
		postorder(root->right); // ������ ����Ʈ�� ��ȸ
		printf("%d ", root->data); // ��� �湮
	}
}

int main() {
	printf("���� ��ȸ: ");
	inorder(root);
	printf("\n");
	printf("���� ��ȸ: ");
	preorder(root);
	printf("\n");
	printf("���� ��ȸ: ");
	postorder(root);
	printf("\n");
}
