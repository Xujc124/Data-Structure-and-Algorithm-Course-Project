#include "stdlib.h"
#include "stdio.h"
#include "polynomial.h"

#define MAX_BUFF_SIZE (256)

void PrintPolyMenu();

void PolyMenuControl()
{
    char chBuffer[MAX_BUFF_SIZE];
    char chKey = '0';
    
    //输入多项式
    Polynomial* head1 = createPoly();//创建多项式1
    Polynomial* head2 = createPoly();//创建多项式2
    Polynomial* add = addPoly(head1, head2);//计算多项式加法
    Polynomial* multi = multiPoly(head1, head2);//计算多项式减法
    Polynomial* minus = minusPoly(head1, head2);//计算多项式乘法

    printf("\n原多项式:\n");
    printPoly(head1);
    printPoly(head2);
    printf("\n多项式加法结果为:  ");
    printPoly(add);
    printf("多项式减法结果为:  ");
    printPoly(minus);
    printf("多项式乘法结果为:  ");
    printPoly(multi);
	do {
        // PrintPolyMenu();
		fgets(chBuffer, MAX_BUFF_SIZE, stdin);
		sscanf(chBuffer, "%c", &chKey, 1);

        switch (chKey)
        {
        case '0':
            break;

        // case '1':
        //     system("cls");
        //     printf("原多项式：\n");
        //     printPoly(head1);
        //     printPoly(head2);
        //     printf("\n\n");
        //     printf("多项式加法的结果为:\n");
        //     printPoly(add);
        //     system("pause");    
        //     break;
        // case '2':
        //     system("cls");
        //     printf("原多项式：\n");
        //     printPoly(head1);
        //     printPoly(head2);
        //     printf("\n\n");
        //     printf("多项式减法的结果为:\n");
        //     printPoly(minus); 
        //     system("pause");            
        //     break;
        // case '3':
        //     system("cls");
        //     printf("原多项式：\n");
        //     printPoly(head1);
        //     printPoly(head2);
        //     printf("\n\n");
        //     printf("多项式的乘法结果为:\n");
        //     printPoly(multi); 
        //     system("pause");            
        //     break;
        default:
            printf("\n输入0回到上一界面\n\n");
            system("pause");
            break;
        }
	} while (chKey != '0');

}

//打印复数计算菜单
// void PrintPolyMenu()
// {
//     system("cls");
// 	printf("===========多项式计算器===========\n\n");
//     printf("--1. 加法运算\n");
//     printf("--2. 减法运算\n");
//     printf("--3. 乘法运算\n");
//     printf("--0. 退出\n\n");
// 	printf("=============================================\n\n");
//     printf("请输入序号选择你想执行的多项式计算: ");
// }