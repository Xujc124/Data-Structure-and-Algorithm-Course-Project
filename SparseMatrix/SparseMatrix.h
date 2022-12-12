#ifndef H_sparseMatrix
#define H_sparseMatrix

#define MAXSIZE 100
#define ElemType double

#include <stdio.h>
#include <stdlib.h>

typedef struct TripleComposition {
	int i, j; // �÷���Ԫ�����±�����±�
	ElemType e; // �÷���Ԫ��ֵ
} Triple, *TP; // ��Ԫ������

typedef struct SparesMatrix {
	Triple data[MAXSIZE];
	int mu, nu, tu;
} TSMatrix, *TSP; // ϡ���������


//�����������ڼ���
void PushBackward(TSP TSM, Triple data, int num);

//��������
TSP CreateMatrix(TSP A);

//�������з���Ԫ��
void ArrangeMatrix(TSP A);

//���Ʋ������¾���
TSP copyMatrix(TSP Head);

//A+B
TSP AddMatrix(TSP TSM1, TSP TSM2);

//A-B
TSP MinusMatrix(TSP A, TSP B);

//A*B
TSP MutiplyMatrix(TSP A, TSP B);

//A^(T)
TSP TransposeMatrix(TSP A);

//��ӡ����Ԫ��
void PrintMatrix(TSP TSM);

//���ӻ���ӡ����
void PrintMatrixVisual(TSP TSM);

#endif