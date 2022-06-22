#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
	int row;   // 행번호
	int col;   // 열번호
	int value; // 원소
}element;

typedef struct {
	element data[MAX_TERMS];
	int rows;   // 행 개수
	int cols;   // 열 개수
	int terms;  // 총 원소의 개수
}SparseMatrix;


void toSparseMatrix(int src[][5], SparseMatrix* dst, int row, int col) {
	// 희소 행렬의 크기를 설정하고, 원소 개수를 0으로 초기화
	dst->rows = row;
	dst->cols = col;
	dst->terms = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (src[i][j] != 0) {
				dst->data[dst->terms].row = i;
				dst->data[dst->terms].col = j;
				dst->data[dst->terms].value = src[i][j];
				dst->terms++; // 희소행렬 내 원소 개수 증가
			}
}

void printMatrix(int a[][5], int row, int col) {
	// 행렬 출력하는 함수 작성
	// loop 2번 사용
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			printf(" %d ", a[r][c]);
		}
		printf("\n");
	}
}

int main() {
	int Mat[5][5] = { {0, 0, 0, 2, 0},
					  {0, 0, 5, 0, 0},
					  {4, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0},
					  {0, 0, 0, 0, 1} };

	SparseMatrix A;
	toSparseMatrix(Mat, &A, 5, 5);
	printMatrix(Mat, 5, 5);
}
