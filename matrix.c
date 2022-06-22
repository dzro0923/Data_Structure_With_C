/*
	행렬의 개념
	- 행과 열로 구성된 자료구조
	- m*n 행렬 : 행 개수가 m개, 열 개수가 n개인 행렬
	- 정방행렬 : 행렬 중에서 m과 n이 같은 행렬
	- 전치행렬 : 행렬의 행과 열을 서로 바꿔 구성한 행렬
	- 희소행렬 : 대부분의 원소가 0으로 구성된 행렬
	  > 희소행렬은 실제로 사용하지 않는 공간이 많아 메모리 공간이 낭비된다.
*/

/*
	희소행렬에 대한 배열 표현
	1. 0이 아닌 원소만 추출하여 (행번호, 열번호, 원소) 쌍으로 변환
	2. 추출한 순서쌍을 구조체(의 배열)에 저장
	3. 원래 행렬에 대한 정보(행 개수, 열 개수, 총 원소의 수) 저장
*/

//희소행렬의 표현

typedef struct {
	int row;   // 행번호
	int col;   // 열번호
	int value; // 원소
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;   //행 개수
	int cols;   //열 개수
	int terms;  //총 원소의 개수
}SparseMatrix;

//A의 전치행렬 B를 구하는 함수
#define ROWS 3
#define COLS 4

void matrix_transpose(int A[ROWS][COLS], int B[COLS][ROWS]) {
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			B[c][r] = A[r][c];
}

// 희소행렬 표현에서 전치행렬 구하는 함수

SparseMatrix matrix_transpose2(SparseMatrix a) {
	SparseMatrix b;
	int bindex;		// 행렬 b에서 현재 저장 위치
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;
	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}