#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

// node�� ��Ʈ�� �ϴ� ����Ž��Ʈ������ key���� ���� ��带 ��ȯ������(���������) Ž���ϴ� �Լ�
TreeNode* search(TreeNode* node, element key) {
	if (node == NULL) return NULL; // Ʈ���� �����̸� NULL �����͸� ��ȯ
	
	if (key == node->key) // Ű���� ���� ������ �ش� ��� ��ȯ
		return node;
	else if (key < node->key) // Ű���� ��庸�� ������ ���� ����Ʈ������ Ž��
		return search(node->left, key);
	else // Ű���� ��庸�� ũ�� ������ ����Ʈ������ Ž��
		return search(node->right, key);
}

// ���ο� ��带 �����ϴ� �Լ�. insert_node()�� ����
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// root�� ��Ʈ�� �ϴ� ����Ž��Ʈ���� key���� ���� ��带 �����ϴ� �Լ�. ���� root ��带 ��ȯ��
TreeNode* insert_node(TreeNode* root, element key) {
	if (root == NULL) return new_node(key); // Ʈ���� �����̸� ���ο� ��带 �����Ͽ� ��ȯ
	
	if (key < root->key) // Ű ���� ��Ʈ���� ������, ���� ����Ʈ���� ����
		root->left = insert_node(root->left, key);
	else if (key > root->key) // Ű ���� ��Ʈ���� ũ��, ������ ����Ʈ���� ����
		root->right = insert_node(root->right, key);
	else // Ű ���� �����ϸ�, ���� ���
		printf("\n Ʈ���� ���� Ű�� �ֽ��ϴ�.!");
	return root;
}

// node�� ��Ʈ�� �ϴ� ����Ž��Ʈ������ �ּҰ��� ���� ��带 ã�� �Լ�
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	
	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	
	return current;
}

// ����Ž��Ʈ���� ������ȸ�ϸ� Ű�� ������� ���ĵ�
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

// root�� ��Ʈ�� �ϴ� ����Ž��Ʈ������ �ش� Ű ���� ���� ��带 �����ϴ� �Լ�. ���� ��Ʈ ��带 ��ȯ
TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL) return NULL; // Ʈ���� �����̸� NULL �����͸� ��ȯ
	
	if (key < root->key) // Ű�� ��Ʈ���� ������ ���� ���� Ʈ������ ����
		root->left = delete_node(root->left, key);
	else if (key > root->key) // Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ������ ����
		root->right = delete_node(root->right, key);
	else { // Ű�� ��ġ�ϴ� ��� �ش� ��� ����
		if (root->left == NULL && root->right == NULL) { // ������ 0�� ���
			free(root); // ��� ���� ��
			return NULL; // NULL�� ��ȯ
		}
		else if (root->left == NULL || root->right == NULL) { // ������ 1�� ���
			if (root->left == NULL) { // ������ �ڽ��� �ִ� ���
				TreeNode* temp = root->right;
				free(root); // ��� ���� ��
				return temp; // ������ �ڽ��� ��ȯ
			}
			else { // ���� �ڽ��� �ִ� ���
				TreeNode* temp = root->left;
				free(root); // ��� ���� ��
				return temp; // ���� �ڽ��� ��ȯ
			}
		}
		else { // ������ 2�� ���
			TreeNode* temp = min_value_node(root->right); // ������ ���� Ʈ������ �ּҰ� ��� ã��
			root->key = temp->key;
			root->right = delete_node(root->right, temp->key); // ������ ���� Ʈ������ �ּҰ� ��� ����
		}
	}
	return root;
}

int main() {
	TreeNode* root = NULL; // ���ʿ��� ���� Ʈ��
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	root = insert_node(root, 35);
	
	printf("����Ž��Ʈ�� ���� ��ȸ ���\n");
	inorder(root);
	printf("\n\n");
	tmp = search(root, 30);
	if(tmp != NULL)
		printf("����Ž��Ʈ������ 30�� �߰���\n\n");
	else
		printf("����Ž��Ʈ������ 30�� �߰߸���\n\n");
	tmp = search(root, 90);
	if(tmp != NULL)
		printf("����Ž��Ʈ������ 90�� �߰���\n\n");
	else
		printf("����Ž��Ʈ������ 90�� �߰߸���\n\n");
	
	root = delete_node(root, 60);
	inorder(root); printf("\n\n");
	root = delete_node(root, 20);
	inorder(root); printf("\n\n");
	root = delete_node(root, 30);
	inorder(root); printf("\n\n");
}