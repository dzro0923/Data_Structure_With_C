#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

// node를 루트로 하는 이진탐색트리에서 key값을 가진 노드를 순환적으로(재귀적으로) 탐색하는 함수
TreeNode* search(TreeNode* node, element key) {
	if (node == NULL) return NULL; // 트리가 공백이면 NULL 포인터를 반환
	
	if (key == node->key) // 키값이 노드와 같으면 해당 노드 반환
		return node;
	else if (key < node->key) // 키값이 노드보다 작으면 왼쪽 서브트리에서 탐색
		return search(node->left, key);
	else // 키값이 노드보다 크면 오른쪽 서브트리에서 탐색
		return search(node->right, key);
}

// 새로운 노드를 생성하는 함수. insert_node()에 사용됨
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// root를 루트로 하는 이진탐색트리에 key값을 가진 노드를 삽입하는 함수. 최종 root 노드를 반환함
TreeNode* insert_node(TreeNode* root, element key) {
	if (root == NULL) return new_node(key); // 트리가 공백이면 새로운 노드를 생성하여 반환
	
	if (key < root->key) // 키 값이 루트보다 작으면, 왼쪽 서브트리에 삽입
		root->left = insert_node(root->left, key);
	else if (key > root->key) // 키 값이 루트보다 크면, 오른쪽 서브트리에 삽입
		root->right = insert_node(root->right, key);
	else // 키 값이 존재하면, 에러 출력
		printf("\n 트리에 동일 키가 있습니다.!");
	return root;
}

// node를 루트로 하는 이진탐색트리에서 최소값을 가진 노드를 찾는 함수
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	
	// 맨 왼쪽 단말 노드를 찾으려 내려감
	while (current->left != NULL)
		current = current->left;
	
	return current;
}

// 이진탐색트리를 중위순회하면 키값 순서대로 정렬됨
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

// root를 루트로 하는 이진탐색트리에서 해당 키 값을 가진 노드를 삭제하는 함수. 최종 루트 노드를 반환
TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL) return NULL; // 트리가 공백이면 NULL 포인터를 반환
	
	if (key < root->key) // 키가 루트보다 작으면 왼쪽 서브 트리에서 삭제
		root->left = delete_node(root->left, key);
	else if (key > root->key) // 키가 루트보다 크면 오른쪽 서브 트리에서 삭제
		root->right = delete_node(root->right, key);
	else { // 키가 일치하는 경우 해당 노드 삭제
		if (root->left == NULL && root->right == NULL) { // 차수가 0인 경우
			free(root); // 노드 삭제 후
			return NULL; // NULL을 반환
		}
		else if (root->left == NULL || root->right == NULL) { // 차수가 1인 경우
			if (root->left == NULL) { // 오른쪽 자식이 있는 경우
				TreeNode* temp = root->right;
				free(root); // 노드 삭제 후
				return temp; // 오른쪽 자식을 반환
			}
			else { // 왼쪽 자식이 있는 경우
				TreeNode* temp = root->left;
				free(root); // 노드 삭제 후
				return temp; // 왼쪽 자식을 반환
			}
		}
		else { // 차수가 2인 경우
			TreeNode* temp = min_value_node(root->right); // 오른쪽 서브 트리에서 최소값 노드 찾기
			root->key = temp->key;
			root->right = delete_node(root->right, temp->key); // 오른쪽 서브 트리에서 최소값 노드 삭제
		}
	}
	return root;
}

int main() {
	TreeNode* root = NULL; // 최초에는 공백 트리
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	root = insert_node(root, 35);
	
	printf("이진탐색트리 중위 순회 결과\n");
	inorder(root);
	printf("\n\n");
	tmp = search(root, 30);
	if(tmp != NULL)
		printf("이진탐색트리에서 30을 발견함\n\n");
	else
		printf("이진탐색트리에서 30을 발견못함\n\n");
	tmp = search(root, 90);
	if(tmp != NULL)
		printf("이진탐색트리에서 90을 발견함\n\n");
	else
		printf("이진탐색트리에서 90을 발견못함\n\n");
	
	root = delete_node(root, 60);
	inorder(root); printf("\n\n");
	root = delete_node(root, 20);
	inorder(root); printf("\n\n");
	root = delete_node(root, 30);
	inorder(root); printf("\n\n");
}