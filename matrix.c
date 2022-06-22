/*
	����� ����
	- ��� ���� ������ �ڷᱸ��
	- m*n ��� : �� ������ m��, �� ������ n���� ���
	- ������� : ��� �߿��� m�� n�� ���� ���
	- ��ġ��� : ����� ��� ���� ���� �ٲ� ������ ���
	- ������ : ��κ��� ���Ұ� 0���� ������ ���
	  > �������� ������ ������� �ʴ� ������ ���� �޸� ������ ����ȴ�.
*/

/*
	�����Ŀ� ���� �迭 ǥ��
	1. 0�� �ƴ� ���Ҹ� �����Ͽ� (���ȣ, ����ȣ, ����) ������ ��ȯ
	2. ������ �������� ����ü(�� �迭)�� ����
	3. ���� ��Ŀ� ���� ����(�� ����, �� ����, �� ������ ��) ����
*/

//�������� ǥ��

typedef struct {
	int row;   // ���ȣ
	int col;   // ����ȣ
	int value; // ����
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;   //�� ����
	int cols;   //�� ����
	int terms;  //�� ������ ����
}SparseMatrix;

//A�� ��ġ��� B�� ���ϴ� �Լ�
#define ROWS 3
#define COLS 4

void matrix_transpose(int A[ROWS][COLS], int B[COLS][ROWS]) {
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			B[c][r] = A[r][c];
}

// ������ ǥ������ ��ġ��� ���ϴ� �Լ�

SparseMatrix matrix_transpose2(SparseMatrix a) {
	SparseMatrix b;
	int bindex;		// ��� b���� ���� ���� ��ġ
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