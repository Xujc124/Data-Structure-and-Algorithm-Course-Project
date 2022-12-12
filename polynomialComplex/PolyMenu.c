#include "stdlib.h"
#include "stdio.h"
#include "polynomial.h"

#define MAX_BUFF_SIZE (256)

void PrintPolyMenu();

void PolyMenuControl()
{
    char chBuffer[MAX_BUFF_SIZE];
    char chKey = '0';
    
    //�������ʽ
    Polynomial* head1 = createPoly();//��������ʽ1
    Polynomial* head2 = createPoly();//��������ʽ2
    Polynomial* add = addPoly(head1, head2);//�������ʽ�ӷ�
    Polynomial* multi = multiPoly(head1, head2);//�������ʽ����
    Polynomial* minus = minusPoly(head1, head2);//�������ʽ�˷�

    printf("\nԭ����ʽ:\n");
    printPoly(head1);
    printPoly(head2);
    printf("\n����ʽ�ӷ����Ϊ:  ");
    printPoly(add);
    printf("����ʽ�������Ϊ:  ");
    printPoly(minus);
    printf("����ʽ�˷����Ϊ:  ");
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
        //     printf("ԭ����ʽ��\n");
        //     printPoly(head1);
        //     printPoly(head2);
        //     printf("\n\n");
        //     printf("����ʽ�ӷ��Ľ��Ϊ:\n");
        //     printPoly(add);
        //     system("pause");    
        //     break;
        // case '2':
        //     system("cls");
        //     printf("ԭ����ʽ��\n");
        //     printPoly(head1);
        //     printPoly(head2);
        //     printf("\n\n");
        //     printf("����ʽ�����Ľ��Ϊ:\n");
        //     printPoly(minus); 
        //     system("pause");            
        //     break;
        // case '3':
        //     system("cls");
        //     printf("ԭ����ʽ��\n");
        //     printPoly(head1);
        //     printPoly(head2);
        //     printf("\n\n");
        //     printf("����ʽ�ĳ˷����Ϊ:\n");
        //     printPoly(multi); 
        //     system("pause");            
        //     break;
        default:
            printf("\n����0�ص���һ����\n\n");
            system("pause");
            break;
        }
	} while (chKey != '0');

}

//��ӡ��������˵�
// void PrintPolyMenu()
// {
//     system("cls");
// 	printf("===========����ʽ������===========\n\n");
//     printf("--1. �ӷ�����\n");
//     printf("--2. ��������\n");
//     printf("--3. �˷�����\n");
//     printf("--0. �˳�\n\n");
// 	printf("=============================================\n\n");
//     printf("���������ѡ������ִ�еĶ���ʽ����: ");
// }