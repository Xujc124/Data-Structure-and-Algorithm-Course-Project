#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"

void SparseMenu() {

	TSP A = (TSP)malloc(sizeof(struct SparesMatrix));
	TSP B = (TSP)malloc(sizeof(struct SparesMatrix));

	A = CreateMatrix(A);
    if(A == NULL){
        printf("���󴴽�ʧ��.......\n");
        system("pause");
        return;
    }

	B = CreateMatrix(B);
	if(B == NULL){
        printf("���󴴽�ʧ��.......\n");
        system("pause");
        return;
    }

	//debug
	// TSP A = (TSP)malloc(sizeof(struct SparesMatrix));
	// TSP B = (TSP)malloc(sizeof(struct SparesMatrix));
	// A->mu = 3;
	// A->nu = 3;
	// A->tu = 4;
	// A->data[0].i = 1;
	// A->data[0].j = 1;
	// A->data[0].e = 1;

	// A->data[1].i = 2;
	// A->data[1].j = 2;
	// A->data[1].e = 2;

	// A->data[2].i = 3;
	// A->data[2].j = 3;
	// A->data[2].e = 3;

	// A->data[3].i = 1;
	// A->data[3].j = 3;
	// A->data[3].e = 3;

	// B->mu = 3;
	// B->nu = 3;
	// B->tu = 4;
	// B->data[0].i = 1;
	// B->data[0].j = 1;
	// B->data[0].e = 1;

	// B->data[1].i = 2;
	// B->data[1].j = 1;
	// B->data[1].e = 3;

	// B->data[2].i = 1;
	// B->data[2].j = 3;
	// B->data[2].e = 2;
	
	// B->data[3].i = 3;
	// B->data[3].j = 2;
	// B->data[3].e = 5;
	

	//�������
	ArrangeMatrix(A);
	ArrangeMatrix(B);
	printf("����A�ķ���ԪΪ��\n");
	PrintMatrix(A);
	PrintMatrixVisual(A);
	printf("\n����B�ķ���ԪΪ��\n");
	PrintMatrix(B);
	PrintMatrixVisual(B);

	printf("\n����ӷ����Ϊ��\n");
	TSP C = (TSP)malloc(sizeof(struct SparesMatrix));
	C = AddMatrix(A, B);
	PrintMatrix(C);
	PrintMatrixVisual(C);

	printf("\n����������Ϊ��\n");
	TSP D = (TSP)malloc(sizeof(struct SparesMatrix));
	D = MinusMatrix(A, B);
	PrintMatrix(D);
	PrintMatrixVisual(D);

	printf("\n����Aת�ý��Ϊ��\n");
	TSP E = (TSP)malloc(sizeof(struct SparesMatrix));
	E = TransposeMatrix(A);
	PrintMatrix(E);
	PrintMatrixVisual(E);

	printf("\n����˷����Ϊ��\n");
	TSP F = (TSP)malloc(sizeof(struct SparesMatrix));
	F = MutiplyMatrix(A,B);
	PrintMatrix(F);
	PrintMatrixVisual(F);


	system("pause");
	return;
}