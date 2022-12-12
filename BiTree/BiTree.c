#include "BiTree.h"

/*��ӡ��׺���ʽ*/
void post_order_traverser(Ptree T) {
	if (T) {
		post_order_traverser(T->left);//��������
		post_order_traverser(T->right);//�����Һ���
		if(T->flag == 0) printf("%c ",T->x.sig);//���ò���������ݵĺ�������
		else if (T->flag == 1)printf("%.2f  ", T->x.data);
	}
	//������Ϊ�գ�������һ��
	return;
}

/*�Ҹ��ڵ�λ��*/
int find_split(char* express, int start, int end)
{
	int tag = -1;

	while (express[start] == '(' && express[end] == ')')
	{
		++start;
		--end;
	}

	int is_in_braket = 0;
	int more_grade = 0;
	for (int i = start; i <= end; i++)
	{
		if (express[i] == '(')
			++is_in_braket;
		else if (express[i] == ')')
			--is_in_braket;

		if ((express[i] == '+' || express[i] == '-')
			&& is_in_braket == 0)
		{
			more_grade = 1;
			tag = i; //��break, �����һ�����������������, ȡ������+��-
		}
		else if ((express[i] == '*' || express[i] == '/')
			&& more_grade == 0
			&& is_in_braket == 0)
		{
			tag = i; //��break, �����һ�����������������
		}
	}
	return tag;
}

/*����������*/
Ptree creat_Btree(char *express, int start, int end)
{
	Ptree pTree = NULL;
	if (((express[start]>='0')&&(express[start]<='9')&& (express[end] >= '0') && (express[end] <= '9'))&&(no_operators(express,start,end)))
	{//������
		if (start == end) {//��λ����
			pTree = (Ptree)malloc(sizeof(Btree));
			pTree->x.data = express[start] - '0';//�ڵ�Ϊ����
			pTree->flag = 1;
			pTree->left = NULL;
			pTree->right = NULL;
		}
		else {
			if (find_sig(express, start, end) == -1) {//��λ����
				pTree = (Ptree)malloc(sizeof(Btree));
				pTree->x.data = string_to_int(express, start, end);
				pTree->flag = 1;
				pTree->left = NULL;
				pTree->right = NULL;
			}
			else {//��С��λ
				pTree = (Ptree)malloc(sizeof(Btree));
				pTree->x.data = string_to_double(express, start, end);
				pTree->flag = 1;
				pTree->left = NULL;
				pTree->right = NULL;
			}
		}
	}
	else
	{   //�ݹ����, ���Դ������ҵı��ʽ�Ķ�Ӧ������
		int tag = find_split(express, start, end);
		if (tag < 0)
		{
			printf("1.invalid express, exit.\n");
			exit(-1);
		}
		else
		{
			pTree = (Ptree)malloc(sizeof(Btree));
			pTree->x.sig = express[tag];
			pTree->flag = 0;
		}
		if (express[start] == '(' && express[end] == ')')
		{
			++start;
			--end;
		}
		pTree->left = creat_Btree(express, start, tag - 1);
		pTree->right = creat_Btree(express, tag + 1, end);
	}
	return pTree;
}

/*������ʽ��ֵ*/
double post_traverser_calc(Ptree pTree)
{
	if (pTree == NULL)
		return -1;
	else if (pTree->flag == 1)return pTree->x.data;
	else if (pTree->flag == 0) {
		if (pTree->x.sig == '+') {
			//printf("%.2f + %.2f = %.2f\n", post_traverser_calc(pTree->left), post_traverser_calc(pTree->right), post_traverser_calc(pTree->left) + post_traverser_calc(pTree->right));
			return post_traverser_calc(pTree->left) + post_traverser_calc(pTree->right);
		}
		else if (pTree->x.sig == '-') {
			//printf("%.2f - %.2f = %.2f\n", post_traverser_calc(pTree->left), post_traverser_calc(pTree->right), post_traverser_calc(pTree->left) - post_traverser_calc(pTree->right));
			return post_traverser_calc(pTree->left) - post_traverser_calc(pTree->right);
		}
		else if (pTree->x.sig == '*') {
			//printf("%.2f * %.2f = %.2f\n", post_traverser_calc(pTree->left), post_traverser_calc(pTree->right), post_traverser_calc(pTree->left) * post_traverser_calc(pTree->right));
			return post_traverser_calc(pTree->left) * 1.0 * post_traverser_calc(pTree->right);
		}
		else if (pTree->x.sig == '/') {
			//printf("%.2f / %.2f = %.2f\n", post_traverser_calc(pTree->left), post_traverser_calc(pTree->right), post_traverser_calc(pTree->left) * 1.0 / post_traverser_calc(pTree->right));
			return post_traverser_calc(pTree->left) * 1.0 / post_traverser_calc(pTree->right);
		}
	}
}

/*�ҷ���"."��λ��*/
int find_sig(char* p,int start, int end) 
{
	for (int i = start; i <= end; i++) {
		if (p[i] == '.')return i;
	}
	return -1;//û�ҵ�С����
}

/*�ж����������*/
int no_operators(char* p, int start, int end)
{
	for (int i = start; i <= end; i++) {
		if (((p[i] < '0') | (p[i] > '9')) && (p[i] != '(') && (p[i] != ')') && (p[i] != '.'))return 0;
	}
	return 1;
}

/*string->int*/
int string_to_int(char* p, int start, int end)
{
	int num = end - start;
	int sum = 0;
	int j = start;
	for (int i = num; i >= 0; i--) {
		sum += (p[j]-'0') * pow(10, i);
		j++;
	}
	return sum;
}

/*string->double*/
double string_to_double(char* p, int start, int end)
{
	int spot_pos = find_sig(p, start, end);
	int num = spot_pos - start;//�������ֵ�λ��
	if (spot_pos == -1)return -1;

	double sum = 0;
	int j = start;
	for (int i = (num - 1); i >= (spot_pos - end);) {
		if((p[j]>='0')&&(p[j]<='9'))sum += ((p[j] - '0') * 1.0 * pow(10, i--));
		j++;
	}
	return sum;
}





