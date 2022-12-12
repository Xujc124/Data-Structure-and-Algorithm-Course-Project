#ifndef H_polynomial
#define H_polynomial

#include <stdio.h>
#include <stdlib.h>

typedef struct tagPolynomial{
    double coeff;//多项式系数
    int nume;//多项式指数
    struct tagPolynomial* next; //指向前驱的指针域
    struct tagPolynomial* prior; //指向后驱的指针域
}Polynomial;

//多项式操作函数
//创建多项式
Polynomial* createPoly();

//删除多项式
void deletePoly(Polynomial* Head);

//打印多项式
void printPoly(Polynomial* Head);

//多项式加减法
Polynomial* addPoly(Polynomial* head1, Polynomial* head2);

//多项式乘法
Polynomial* multiPoly(Polynomial* head1, Polynomial* head2);

//多项式减法
Polynomial* minusPoly(Polynomial* head1, Polynomial* head2);

//多项式长度
int lens(Polynomial* head);

//动态多项式插入
Polynomial* insert(Polynomial* Head, Polynomial* newPoly);

//复制链表
Polynomial* copyPoly(Polynomial* Head);

//初始化结构体
void iniPoly(Polynomial* poly);

//链表取负
Polynomial* negPoly(Polynomial* head);

#endif