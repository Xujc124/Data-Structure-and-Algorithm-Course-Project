#include "stdio.h"
#include "stdlib.h"
#include "complex.h"

#define MAX_BUFF_SIZE (256)

void PrintMathMenu();

void MathMenuControl()
{
    char chBuffer[MAX_BUFF_SIZE];
    char chKey = '0';
    
	do {
        PrintMathMenu();

		fgets(chBuffer, MAX_BUFF_SIZE, stdin);
		sscanf(chBuffer, "%c", &chKey, 1);

        switch (chKey)
        {
        case '0':
            break;

        case '1':
            system("cls");
            AddTwoComplex();//�����ӷ�    
            break;
        case '2':
            system("cls");
            MinusTwoComplex();//��������           
            break;
        case '3':
            system("cls");
            MultiTwoComplex();//�����˷�    
            break;
        case '4':
            system("cls");
            DivTwoComplex();//��������    
            break;
        
        default:
            printf("\n��������Ч����ţ�\n\n");
            system("pause");
            break;
        }
	} while (chKey != '0');

}

//��ӡ��������˵�
void PrintMathMenu()
{
    system("cls");
	printf("===========����������===========\n\n");
    printf("--1. �����ӷ�������\n");
    printf("--2. ��������������\n");
    printf("--3. �����˷�������\n");
    printf("--4. ��������������\n");
    printf("--0. �˳�\n\n");
	printf("=============================================\n\n");
    printf("���������ѡ������ִ�еĸ�������: ");
}