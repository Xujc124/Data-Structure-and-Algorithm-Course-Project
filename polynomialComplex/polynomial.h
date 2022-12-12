#ifndef H_polynomial
#define H_polynomial

#include <stdio.h>
#include <stdlib.h>

typedef struct tagPolynomial{
    double coeff;//����ʽϵ��
    int nume;//����ʽָ��
    struct tagPolynomial* next; //ָ��ǰ����ָ����
    struct tagPolynomial* prior; //ָ�������ָ����
}Polynomial;

//����ʽ��������
//��������ʽ
Polynomial* createPoly();

//ɾ������ʽ
void deletePoly(Polynomial* Head);

//��ӡ����ʽ
void printPoly(Polynomial* Head);

//����ʽ�Ӽ���
Polynomial* addPoly(Polynomial* head1, Polynomial* head2);

//����ʽ�˷�
Polynomial* multiPoly(Polynomial* head1, Polynomial* head2);

//����ʽ����
Polynomial* minusPoly(Polynomial* head1, Polynomial* head2);

//����ʽ����
int lens(Polynomial* head);

//��̬����ʽ����
Polynomial* insert(Polynomial* Head, Polynomial* newPoly);

//��������
Polynomial* copyPoly(Polynomial* Head);

//��ʼ���ṹ��
void iniPoly(Polynomial* poly);

//����ȡ��
Polynomial* negPoly(Polynomial* head);

#endif