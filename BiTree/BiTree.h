#ifndef _BiTree_
#define _BiTree_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Btree//���������
{
	struct _Btree* left;
	struct _Btree* right;
	int flag;//�ڵ����ݵı�ʶ����0->sig,1->data
	union elem{//�ڵ�����
	    char sig;//�����(ͬ���ĸ��ڵ�)
	    double data;//����
    }x;
}Btree,*Ptree;

void post_order_traverser(Ptree T);//��ӡ��׺���ʽ
int find_split(char* express, int start, int end);//�Ҹ��ڵ�λ��
Ptree creat_Btree(char *express, int start, int end);//����������
double post_traverser_calc(Ptree pTree);//������ʽ��ֵ
int find_sig(char* p, int start, int end);//�ҷ���"."��λ��
int no_operators(char* p, int start, int end);//�ж����������
int string_to_int(char* p, int start, int end);//string->int
double string_to_double(char* p, int start, int end);//string->double

#endif