#ifndef _BiTree_
#define _BiTree_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Btree//定义二叉树
{
	struct _Btree* left;
	struct _Btree* right;
	int flag;//节点内容的标识符：0->sig,1->data
	union elem{//节点内容
	    char sig;//运算符(同级的根节点)
	    double data;//数据
    }x;
}Btree,*Ptree;

void post_order_traverser(Ptree T);//打印后缀表达式
int find_split(char* express, int start, int end);//找根节点位置
Ptree creat_Btree(char *express, int start, int end);//创建二叉树
double post_traverser_calc(Ptree pTree);//计算表达式的值
int find_sig(char* p, int start, int end);//找符号"."的位置
int no_operators(char* p, int start, int end);//判断有无运算符
int string_to_int(char* p, int start, int end);//string->int
double string_to_double(char* p, int start, int end);//string->double

#endif