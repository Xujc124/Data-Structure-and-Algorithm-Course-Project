#ifndef H_sparseMatrix
#define H_sparseMatrix

#define MAXSIZE 100
#define ElemType double

#include <stdio.h>
#include <stdlib.h>

typedef struct TripleComposition {
	int i, j; // 该非零元的行下标和列下标
	ElemType e; // 该非零元的值
} Triple, *TP; // 三元组类型

typedef struct SparesMatrix {
	Triple data[MAXSIZE];
	int mu, nu, tu;
} TSMatrix, *TSP; // 稀疏矩阵类型


//插入排序，用于计算
void PushBackward(TSP TSM, Triple data, int num);

//创建矩阵
TSP CreateMatrix(TSP A);

//升序排列非零元素
void ArrangeMatrix(TSP A);

//复制并创建新矩阵
TSP copyMatrix(TSP Head);

//A+B
TSP AddMatrix(TSP TSM1, TSP TSM2);

//A-B
TSP MinusMatrix(TSP A, TSP B);

//A*B
TSP MutiplyMatrix(TSP A, TSP B);

//A^(T)
TSP TransposeMatrix(TSP A);

//打印非零元素
void PrintMatrix(TSP TSM);

//可视化打印矩阵
void PrintMatrixVisual(TSP TSM);

#endif