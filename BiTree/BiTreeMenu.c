#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

void BiTreeMenu(){
    char a[100];
	double result = 0;
	char ch;
	printf("��������׺���ʽ��\n");
	scanf("%s", a);
	while ((ch = getchar()) != '\n');//ȥ��β���Ļس���
	Ptree express_tree = creat_Btree(a, 0, strlen(a) - 1);//����������
	printf("��׺���ʽ��");
	post_order_traverser(express_tree);//��ӡ��׺���ʽ
	printf("\n");
	result = post_traverser_calc(express_tree);//������ʽ��ֵ
	printf("���ʽ���Ϊ��%.2f\n", result);
	system("pause");
	return;
}