#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

void BiTreeMenu(){
    char a[100];
	double result = 0;
	char ch;
	printf("请输入中缀表达式：\n");
	scanf("%s", a);
	while ((ch = getchar()) != '\n');//去除尾部的回车符
	Ptree express_tree = creat_Btree(a, 0, strlen(a) - 1);//创建二叉树
	printf("后缀表达式：");
	post_order_traverser(express_tree);//打印后缀表达式
	printf("\n");
	result = post_traverser_calc(express_tree);//计算表达式的值
	printf("表达式结果为：%.2f\n", result);
	system("pause");
	return;
}