#include "stdio.h"
#include "stdlib.h"
#include "Complex.h"

int AddTwoComplex() 
{
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psSum = NULL;

	// Ϊָ��psSum�����ڴ�ռ�
	//psSum = (LPComplex)malloc(sizeof(Complex));
	psSum = CreateComplex();
	if (psSum == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========��������������===========\n\n");
	printf("ע�⣺����ʡ��ʱ��Ĭ��Ϊ0\n\n");
	printf("\n");
	// �����û����룬������һ������
	printf("�������һ��������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("������ĵ�һ�������ǣ�");
    PrintComplex(sCpx1);
    printf("\n\n");

	// ʵ�����鲿����
	fReal = 0;
	fImage = 0;

	// �����û����룬�����ڶ�������
	printf("������ڶ���������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	AssignComplex(&sCpx2, fReal, fImage);

    printf("������ĵڶ��������ǣ�");
    PrintComplex(sCpx2);
    printf("\n\n");

	// �������������ĺ�
	AddComplex(sCpx1, sCpx2, psSum);

    printf("���������ĺ��ǣ�");
    PrintComplex(*psSum);
    printf("\n\n");
	
	// �ͷ�psSumָ����ڴ�ռ�
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

	// Ϊָ��psSum�����ڴ�ռ�
	//psSum = (LPComplex)malloc(sizeof(Complex));
	psSum = CreateComplex();
	if (psSum == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========��������������===========\n\n");
	printf("ע�⣺����ʡ��ʱ��Ĭ��Ϊ0\n\n");
	printf("\n");
	// �����û����룬������һ������
	printf("�������һ��������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("������ĵ�һ�������ǣ�");
    PrintComplex(sCpx1);
    printf("\n\n");

	// ʵ�����鲿����
	fReal = 0;
	fImage = 0;

	// �����û����룬�����ڶ�������
	printf("������ڶ���������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	AssignComplex(&sCpx2, fReal, fImage);

    printf("������ĵڶ��������ǣ�");
    PrintComplex(sCpx2);
    printf("\n\n");

	// �������������Ĳ�
	MinusComplex(sCpx1, sCpx2, psSum);

    printf("���������Ĳ��ǣ�");
    PrintComplex(*psSum);
    printf("\n\n");
	
	// �ͷ�psSumָ����ڴ�ռ�
	//free(psSum);
	DestroyComplex(&psSum);

	system("pause");

	return 0;
}

int MultiTwoComplex(){
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psSum = NULL;

	// Ϊָ��psSum�����ڴ�ռ�
	//psSum = (LPComplex)malloc(sizeof(Complex));
	psSum = CreateComplex();
	if (psSum == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========��������������===========\n\n");
	printf("ע�⣺����ʡ��ʱ��Ĭ��Ϊ0\n\n");
	printf("\n");
	// �����û����룬������һ������
	printf("�������һ��������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("������ĵ�һ�������ǣ�");
    PrintComplex(sCpx1);
    printf("\n\n");

	// ʵ�����鲿����
	fReal = 0;
	fImage = 0;

	// �����û����룬�����ڶ�������
	printf("������ڶ���������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	AssignComplex(&sCpx2, fReal, fImage);

    printf("������ĵڶ��������ǣ�");
    PrintComplex(sCpx2);
    printf("\n\n");

	// �������������ĳ˻�
	MultiComplex(sCpx1, sCpx2, psSum);

    printf("���������ĳ˻��ǣ�");
    PrintComplex(*psSum);
    printf("\n\n");
	
	// �ͷ�psSumָ����ڴ�ռ�
	//free(psSum);
	DestroyComplex(&psSum);

	system("pause");

	return 0;
}

int DivTwoComplex(){
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psSum = NULL;

	// Ϊָ��psSum�����ڴ�ռ�
	//psSum = (LPComplex)malloc(sizeof(Complex));
	psSum = CreateComplex();
	if (psSum == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========��������������===========\n\n");
	printf("ע�⣺����ʡ��ʱ��Ĭ��Ϊ0\n\n");
	printf("=========Ĭ�ϵ�һ����Ϊ����===========\n");
	printf("\n");
	// �����û����룬������һ������
	printf("�������һ��������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("������ĵ�һ�������ǣ�");
    PrintComplex(sCpx1);
    printf("\n\n");

	// ʵ�����鲿����
	fReal = 0;
	fImage = 0;

	// �����û����룬�����ڶ�������
	printf("������ڶ���������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	AssignComplex(&sCpx2, fReal, fImage);

	//���ڶ�������Ϊ0������������
	if((sCpx2.fImage == 0)&&(sCpx2.fReal == 0)){
		printf("\n��������Ϊ0������������\n");
		DestroyComplex(&psSum);
		system("pause");
		return 0;
	}
	

    printf("������ĵڶ��������ǣ�");
    PrintComplex(sCpx2);
    printf("\n\n");

	// ����������������
	DivComplex(sCpx1, sCpx2, psSum);

    printf("�������������ǣ�");
    PrintComplex(*psSum);
    printf("\n\n");
	
	// �ͷ�psSumָ����ڴ�ռ�
	//free(psSum);
	DestroyComplex(&psSum);

	system("pause");

	return 0;
}