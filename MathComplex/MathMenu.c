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
            AddTwoComplex();//复数加法    
            break;
        case '2':
            system("cls");
            MinusTwoComplex();//复数减法           
            break;
        case '3':
            system("cls");
            MultiTwoComplex();//复数乘法    
            break;
        case '4':
            system("cls");
            DivTwoComplex();//复数除法    
            break;
        
        default:
            printf("\n请输入有效的序号！\n\n");
            system("pause");
            break;
        }
	} while (chKey != '0');

}

//打印复数计算菜单
void PrintMathMenu()
{
    system("cls");
	printf("===========复数计算器===========\n\n");
    printf("--1. 复数加法运算器\n");
    printf("--2. 复数减法运算器\n");
    printf("--3. 复数乘法运算器\n");
    printf("--4. 复数除法运算器\n");
    printf("--0. 退出\n\n");
	printf("=============================================\n\n");
    printf("请输入序号选择你想执行的复数计算: ");
}