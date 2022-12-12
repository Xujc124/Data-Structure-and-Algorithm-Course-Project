#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"

//�������з���Ԫ��
void ArrangeMatrix(TSP A){
    int ii = 0;
    int flag = 0;
    //ð���������ʱ����
    int temp_i = 0;
    int temp_j = 0;
    int temp_e = 0;
    while(1){
        flag = 0;
        for(ii = 0;ii < (A->tu - 1);ii++){
            if((A->data[ii+1].i) < (A->data[ii].i)){
                temp_i = A->data[ii+1].i;
                temp_j = A->data[ii+1].j;
                temp_e = A->data[ii+1].e;
                A->data[ii+1].i = A->data[ii].i;
                A->data[ii+1].j = A->data[ii].j;
                A->data[ii+1].e = A->data[ii].e;
                A->data[ii].i = temp_i;
                A->data[ii].j = temp_j;
                A->data[ii].e = temp_e;
                flag = 1;
            }
            else if((A->data[ii+1].i) == (A->data[ii].i)){
                if((A->data[ii+1].j) < (A->data[ii].j)){
                    temp_i = A->data[ii+1].i;
                    temp_j = A->data[ii+1].j;
                    temp_e = A->data[ii+1].e;
                    A->data[ii+1].i = A->data[ii].i;
                    A->data[ii+1].j = A->data[ii].j;
                    A->data[ii+1].e = A->data[ii].e;
                    A->data[ii].i = temp_i;
                    A->data[ii].j = temp_j;
                    A->data[ii].e = temp_e;
                    flag = 1;
                }
            }
            else{}
        }
        if(flag == 0)break;
    }
}

//��������
TSP CreateMatrix(TSP A) {
	printf("������þ����������");
	scanf("%d", &(A->mu));
	printf("������þ����������");
	scanf("%d", &(A->nu));
	printf("������þ���ķ���Ԫ�ĸ�����");
	scanf("%d", &(A->tu));

    int flag = 0;
	for (int k = 0; k < A->tu; k++) {
		printf("�������%d������Ԫ��\n", k + 1);
		printf("����Ԫ�����У�");
		scanf("%d", &(A->data[k].i));
        if(A->data[k].i > A->mu){
            flag = 1;
            break;
        }

		printf("����Ԫ�����У�");
		scanf("%d", &(A->data[k].j));
        if(A->data[k].j > A->nu){
            flag = 1;
            break;
        }

		printf("����Ԫ��ֵ��");
		scanf("%lf", &(A->data[k].e));
        if(A->data[k].e == 0){
            flag = 2;
            break;
        }
	}
    if(flag == 1){
        printf("����Ԫ�ص����г���.....\n");
        printf("����������.............\n");
        return NULL;
    }
    if(flag == 2){
        printf("����Ԫ�غ���.....\n");
        printf("����������.......\n");
        return NULL;
    }
    ArrangeMatrix(A);
	return A;
}

//���Ʋ������¾���
TSP copyMatrix(TSP Head) {
	TSP TSM1 = (TSP)malloc(sizeof(struct SparesMatrix));
	TSM1->mu = Head->mu;
	TSM1->nu = Head->nu;
	TSM1->tu = Head->tu;
	for (int k = 0; k < Head->tu; k++) {
		TSM1->data[k].i = Head->data[k].i;
		TSM1->data[k].j = Head->data[k].j;
		TSM1->data[k].e = Head->data[k].e;
	}
	return TSM1;
}

//A+B
TSP AddMatrix(TSP A, TSP B) {

	TSP AA = copyMatrix(A);

	if ((AA->mu != B->mu) | (AA->nu != B->nu)) {
		printf("�����������д�С��ͬ����������������......\n");
		return NULL;
	}

	int k = 0;
	TP prev = (TP)malloc(sizeof(struct TripleComposition));
	TP curr = (TP)malloc(sizeof(struct TripleComposition));
	//TSP output = copyMatrix(AA);//������ʼ����output
	int kkk = 0;

	for (int kk = 0; kk < B->tu; kk++) {//B��ѭ��
		kkk = 0;
		while ((B->data[kk].i > AA->data[kkk].i) && (kkk < AA->tu))kkk++;
		if (kkk == AA->tu) {//B��AA�����һ��
			AA->data[AA->tu].i = B->data[kk].i;
			AA->data[AA->tu].j = B->data[kk].j;
			AA->data[AA->tu].e = B->data[kk].e;
		}
		else if (B->data[kk].i == AA->data[kkk].i) {//��AA���ҵ���Ӧ��,AA�е�kkk������ͬ�е���ʼԪ��
			int kkkk = kkk;
			while ((B->data[kk].j > AA->data[kkkk].j) && (AA->data[kkkk].i == B->data[kk].i))kkkk++;
			if ((AA->data[kkkk].i != B->data[kk].i) | (B->data[kk].j < AA->data[kkkk].j)) {//��������AA��ͬ�������һ��
				//pushforward��ʼ��
				/*prev->i = B->data[kk].i;
				prev->j = B->data[kk].j;
				prev->e = B->data[kk].e;
				curr->i = A->data[kkk].i;
				curr->j = A->data[kkk].j;
				curr->e = A->data[kkk].e;*/
				PushBackward(AA, B->data[kk], kkkk);
				// kkk++;
			}
			else AA->data[kkkk].e += B->data[kk].e;//�ҵ���Ӧ��
		}
		else PushBackward(AA, B->data[kk], kkk);//��A�в��Ƕ�Ӧ��
	}
    ArrangeMatrix(AA);
	return AA;
}

//A-B
TSP MinusMatrix(TSP A, TSP B) {
	TSP AA = copyMatrix(A);

	for (int k = 0; k < B->tu; k++) B->data[k].e = -(B->data[k].e);


	if ((AA->mu != B->mu) | (AA->nu != B->nu)) {
		printf("�����������д�С��ͬ����������������......\n");
		return NULL;
	}

	int k = 0;
	TP prev = (TP)malloc(sizeof(struct TripleComposition));
	TP curr = (TP)malloc(sizeof(struct TripleComposition));
	//TSP output = copyMatrix(AA);//������ʼ����output
	int kkk = 0;

	for (int kk = 0; kk < B->tu; kk++) {//B��ѭ��
		kkk = 0;
		while ((B->data[kk].i > AA->data[kkk].i) && (kkk < AA->tu))kkk++;
		if (kkk == AA->tu) {//B��AA�����һ��
			AA->data[AA->tu].i = B->data[kk].i;
			AA->data[AA->tu].j = B->data[kk].j;
			AA->data[AA->tu].e = B->data[kk].e;
		}
		else if (B->data[kk].i == AA->data[kkk].i) {//��AA���ҵ���Ӧ��,AA�е�kkk������ͬ�е���ʼԪ��
			int kkkk = kkk;
			while ((B->data[kk].j > AA->data[kkkk].j) && (AA->data[kkkk].i == B->data[kk].i))kkkk++;
			if ((AA->data[kkkk].i != B->data[kk].i) | (B->data[kk].j < AA->data[kkkk].j)) {//��������AA��ͬ�������һ��
				//pushforward��ʼ��
				/*prev->i = B->data[kk].i;
				prev->j = B->data[kk].j;
				prev->e = B->data[kk].e;
				curr->i = A->data[kkk].i;
				curr->j = A->data[kkk].j;
				curr->e = A->data[kkk].e;*/
				PushBackward(AA, B->data[kk], kkkk);
			}
			else AA->data[kkkk].e += B->data[kk].e;//�ҵ���Ӧ��
		}
		else PushBackward(AA, B->data[kk], kkk);//��A�в��Ƕ�Ӧ��
	}
	for (int k = 0; k < B->tu; k++) B->data[k].e = -(B->data[k].e);
    ArrangeMatrix(AA);
	return AA;
}

//A*B
TSP MutiplyMatrix(TSP A, TSP B) {
	if (A->nu != B->mu) {
		printf("�����ʽ��������������.....\n");
		return NULL;
	}

	TSP AA = (TSP)malloc(sizeof(struct SparesMatrix));
	AA->mu = A->mu;
	AA->nu = B->nu;
	int count = 0;//AA->tu
	for (int k = 0; k < A->tu; k++) {
		for (int kk = 0; kk < B->tu; kk++) {
			if (A->data[k].j != B->data[kk].i)continue;
			if (count == 0) {//��ʼ
				AA->data[count].i = A->data[k].i;
				AA->data[count].j = B->data[kk].j;
				AA->data[count].e = A->data[k].e * B->data[kk].e;
				count++;
			}
			else {
				int kkk = 0;
				for (kkk = 0; kkk < count; kkk++) {
					if ((AA->data[kkk].i == A->data[k].i) && (AA->data[kkk].j == B->data[kk].j)) {//�Ѿ����ڸ�λ�õ�Ԫ��
						AA->data[kkk].e += A->data[k].e * B->data[kk].e;
						break;
					}
				}
				if (kkk == count) {//�����ڸ�λ�õ�Ԫ��
					AA->data[count].i = A->data[k].i;
					AA->data[count].j = B->data[kk].j;
					AA->data[count].e = A->data[k].e * B->data[kk].e;
					count++;
				}
			}
		}
	}
	AA->tu = count;
    ArrangeMatrix(AA);
	return AA;
}

//A^T
TSP TransposeMatrix(TSP A) {
	TSP AA = (TSP)malloc(sizeof(struct SparesMatrix));
	AA->mu = A->nu;
	AA->nu = A->mu;
	AA->tu = A->tu;

	int min = A->nu + 1;
	int min_d = A->mu + 1;
	int min_last = 0;
	int min_dlast = 0;
	int md;
	int count = 0;
	for (int k = 0; k < A->tu;) {
		min = A->nu + 1;
		min_d = A->mu + 1;
		count = 0;
		min_dlast = 0;
		for (int kk = 0; kk < A->tu; kk++) {
			if ((A->data[kk].j < min)&&(A->data[kk].j>min_last)) {
				min = A->data[kk].j;
			}
		}

		for (int kk = 0; kk < A->tu; kk++) {
			if (A->data[kk].j == min) count++;
		}

		for (int kkk = 0; kkk < count; kkk++) {
			min_d = A->mu + 1;
			for (int kk = 0; kk < A->tu; kk++) {
				if ((A->data[kk].j == min) && (A->data[kk].i < min_d) && (A->data[kk].i > min_dlast)) {
					min_d = A->data[kk].i;//��С�е�ֵ
					md = kk;//��С���±�

				}
			}

			AA->data[k].i = A->data[md].j;
			AA->data[k].j = A->data[md].i;
			AA->data[k].e = A->data[md].e;

			min_dlast = min_d;//��һ����С��
			k++;
		}
		min_last = min;
		
	}
    ArrangeMatrix(AA);
	return AA;

}

//�����������ڼ���
void PushBackward(TSP TSM, Triple data, int num) {
	//num�������±�
	Triple prev, curr;

	if (num >= TSM->tu) {
		TSM->data[num].i = data.i;
		TSM->data[num].j = data.j;
		TSM->data[num].e = data.e;
	}
	else {
		//��ʼ��
		prev.i = data.i;
		prev.j = data.j;
		prev.e = data.e;
		curr.i = TSM->data[num].i;
		curr.j = TSM->data[num].j;
		curr.e = TSM->data[num].e;

		for (int i = num; i <= TSM->tu; i++) {
			TSM->data[i].i = prev.i;
			TSM->data[i].j = prev.j;
			TSM->data[i].e = prev.e;

			prev.i = curr.i;
			prev.j = curr.j;
			prev.e = curr.e;

			curr.i = TSM->data[i + 1].i;
			curr.j = TSM->data[i + 1].j;
			curr.e = TSM->data[i + 1].e;
		}
	}
	(TSM->tu)++;
}

//��ӡ����Ԫ��
void PrintMatrix(TSP TSM) {
	if (TSM == NULL) {
		printf("������Ч.....\n");
		return;
	}
	printf("�������ԪΪ��\n");
	TP p;
    int flag = 0;
	for (int i = 0; i < TSM->tu; i++) {
		p = &(TSM->data[i]);
		if(p->e!=0){
            printf("�кţ�%d �кţ�%d ���ݣ�%lf\n", p->i, p->j, p->e);
            flag = 1;
            }
	}
    if(flag == 0)printf("���о���Ԫ�ؾ�Ϊ0");
}

//���ӻ���ӡ����
void PrintMatrixVisual(TSP TSM) {
	if (TSM == NULL) {
		printf("������Ч.....\n");
		return;
	}
	printf("\n");
	int k = 0;
	for (int i = 0; i < TSM->mu; i++) {
		for (int j = 0; j < TSM->nu; j++) {
			if (((i+1) == TSM->data[k].i) && ((j+1) == TSM->data[k].j)) printf("%.2f\t", TSM->data[k++].e);
			else printf("0.00\t");
		}
		printf("\n");
	}
	printf("\n\n");
}