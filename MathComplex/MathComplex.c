#include "stdio.h"
#include "stdlib.h"
#include "Complex.h"

int AddTwoComplex() 
{
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psSum = NULL;

	// 为指针psSum分配内存空间
	//psSum = (LPComplex)malloc(sizeof(Complex));
	psSum = CreateComplex();
	if (psSum == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========复数四则运算器===========\n\n");
	printf("注意：输入省略时，默认为0\n\n");
	printf("\n");
	// 接收用户输入，构建第一个复数
	printf("请输入第一个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("你输入的第一个复数是：");
    PrintComplex(sCpx1);
    printf("\n\n");

	// 实部、虚部置零
	fReal = 0;
	fImage = 0;

	// 接收用户输入，构建第二个复数
	printf("请输入第二个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	AssignComplex(&sCpx2, fReal, fImage);

    printf("你输入的第二个复数是：");
    PrintComplex(sCpx2);
    printf("\n\n");

	// 计算两个复数的和
	AddComplex(sCpx1, sCpx2, psSum);

    printf("两个复数的和是：");
    PrintComplex(*psSum);
    printf("\n\n");
	
	// 释放psSum指向的内存空间
	//free(psSum);
	DestroyComplex(&psSum);

	system("pause");

	return 0;
}

int MinusTwoComplex() 
{
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psSum = NULL;

	// 为指针psSum分配内存空间
	//psSum = (LPComplex)malloc(sizeof(Complex));
	psSum = CreateComplex();
	if (psSum == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========复数四则运算器===========\n\n");
	printf("注意：输入省略时，默认为0\n\n");
	printf("\n");
	// 接收用户输入，构建第一个复数
	printf("请输入第一个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("你输入的第一个复数是：");
    PrintComplex(sCpx1);
    printf("\n\n");

	// 实部与虚部置零
	fReal = 0;
	fImage = 0;

	// 接收用户输入，构建第二个复数
	printf("请输入第二个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	AssignComplex(&sCpx2, fReal, fImage);

    printf("你输入的第二个复数是：");
    PrintComplex(sCpx2);
    printf("\n\n");

	// 计算两个复数的差
	MinusComplex(sCpx1, sCpx2, psSum);

    printf("两个复数的差是：");
    PrintComplex(*psSum);
    printf("\n\n");
	
	// 释放psSum指向的内存空间
	//free(psSum);
	DestroyComplex(&psSum);

	system("pause");

	return 0;
}

int MultiTwoComplex(){
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psSum = NULL;

	// 为指针psSum分配内存空间
	//psSum = (LPComplex)malloc(sizeof(Complex));
	psSum = CreateComplex();
	if (psSum == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========复数四则运算器===========\n\n");
	printf("注意：输入省略时，默认为0\n\n");
	printf("\n");
	// 接收用户输入，构建第一个复数
	printf("请输入第一个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("你输入的第一个复数是：");
    PrintComplex(sCpx1);
    printf("\n\n");

	// 实部与虚部置零
	fReal = 0;
	fImage = 0;

	// 接收用户输入，构建第二个复数
	printf("请输入第二个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	AssignComplex(&sCpx2, fReal, fImage);

    printf("你输入的第二个复数是：");
    PrintComplex(sCpx2);
    printf("\n\n");

	// 计算两个复数的乘积
	MultiComplex(sCpx1, sCpx2, psSum);

    printf("两个复数的乘积是：");
    PrintComplex(*psSum);
    printf("\n\n");
	
	// 释放psSum指向的内存空间
	//free(psSum);
	DestroyComplex(&psSum);

	system("pause");

	return 0;
}

int DivTwoComplex(){
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psSum = NULL;

	// 为指针psSum分配内存空间
	//psSum = (LPComplex)malloc(sizeof(Complex));
	psSum = CreateComplex();
	if (psSum == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========复数四则运算器===========\n\n");
	printf("注意：输入省略时，默认为0\n\n");
	printf("=========默认第一个数为分子===========\n");
	printf("\n");
	// 接收用户输入，构建第一个复数
	printf("请输入第一个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("你输入的第一个复数是：");
    PrintComplex(sCpx1);
    printf("\n\n");

	// 实部与虚部置零
	fReal = 0;
	fImage = 0;

	// 接收用户输入，构建第二个复数
	printf("请输入第二个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	AssignComplex(&sCpx2, fReal, fImage);

	//若第二个复数为0，则重新输入
	if((sCpx2.fImage == 0)&&(sCpx2.fReal == 0)){
		printf("\n除数不能为0，请重新输入\n");
		DestroyComplex(&psSum);
		system("pause");
		return 0;
	}
	

    printf("你输入的第二个复数是：");
    PrintComplex(sCpx2);
    printf("\n\n");

	// 计算两个复数的商
	DivComplex(sCpx1, sCpx2, psSum);

    printf("两个复数的商是：");
    PrintComplex(*psSum);
    printf("\n\n");
	
	// 释放psSum指向的内存空间
	//free(psSum);
	DestroyComplex(&psSum);

	system("pause");

	return 0;
}