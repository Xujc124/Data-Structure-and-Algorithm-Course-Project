#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynomial.h"

/*����ʽ��������*/

//��������ʽ
Polynomial* createPoly(){
    // char c;
    // int count = 0, nume = 0, flag = 1, 
    // double coeff = 0;
    int polyNum = 0;//����ʽ������

    Polynomial* head = (Polynomial*)malloc(sizeof(struct tagPolynomial));//����ͷ���
    // Polynomial* tail = (Polynomial*)malloc(sizeof(struct tagPolynomial));//����β���
    iniPoly(head);//ͷ����ʼ��
    // iniPoly(tail);//β����ʼ��

    /*������*/
    printf("��������������Ķ���ʽ����:");
    scanf("%d",&polyNum);
    printf("\n�����ʽ��ϵ�� �ݴ� ϵ�� �ݴ�...\n");
    printf("\n��������������Ķ���ʽ:");

    //������нڵ�
    scanf("%lf %d",&(head->coeff),&(head->nume));
    for(int i = 1;i < polyNum;i++){
        Polynomial* polyP = (Polynomial*)malloc(sizeof(struct tagPolynomial));
        iniPoly(polyP);
        scanf("%lf %d",&(polyP->coeff),&(polyP->nume));
        head = insert(head,polyP);//���½ڵ㰴���������
        printf("\n");
    }
    printf("--------------------------------------\n");

    /*��һ�����뷽ʽ*/
    // printf("ע��:����ʽ����ĸ�ʽΪA B\n");
    // printf("�������0 0��β\n");
    // printf("���������ʽ��ϵ��:\n");
    // while(1){
    //     scanf("%lf %d",&coeff,&nume);
    //     if((coeff==0)&&(nume==0))break;//����ѭ��������

    //     //��1������
    //     if(flag == 1){
    //     head->nume = nume;
    //     head->coeff = coeff;
    //     flag = 0;
    //     // printPoly(head);
    //     }

    //     //��2������
    //     else if(flag == 0){
    //         tail->nume = nume;
    //         tail->coeff = coeff;

    //         // head = insert(head,tail);
    //         if(head->nume > tail->nume){
    //             int temp1;
    //             double temp2;
    //             temp1 = head->nume;
    //             head->nume = tail->nume;
    //             tail->nume = temp1;

    //             temp2 = head->coeff;
    //             head->coeff = tail->coeff;
    //             tail->coeff = temp2;

    //             head->next = tail;
    //             tail->prior = head;
    //         }
    //         else if(head->nume == tail->nume){
    //             head->coeff += tail->coeff;
    //         }
    //         else{
    //             head->next = tail;
    //             tail->prior = head;
    //         }
    //         // printPoly(head);

    //         flag = 2;
    //     }

    //     //�ǵ�1��2������
    //     else{
    //         Polynomial* pGet;
    //         pGet = (Polynomial*)malloc(sizeof(struct tagPolynomial));

    //         pGet->nume = nume;
    //         pGet->coeff = coeff;

    //         head = insert(head,pGet);
    //         tail = head->next;
    //         while(tail->next != NULL)tail = tail->next;//��tail�����������

    //         flag = 3;
    //     }
    //     coeff = nume = 0;//����ֵ
    // }

    // if(flag == 0){
    //     head->next = NULL;//һ��ͷ����β
    // }
    return head;
}

//ɾ������ʽ
void deletePoly(Polynomial* Head){
    Polynomial* curr, *pre;
    pre = Head;
    curr = Head->next;
    //ֻ��ͷ���
    if(curr == NULL){
        Head->next = NULL;
        Head->prior = NULL;
        free(pre);
    }
    //��ͷ����β���
    else if(curr->next == NULL){
        Head->next = NULL;
        Head->prior = NULL;
        free(pre);
        free(curr);
    }
    //������3�����
    else{
        while(curr->next!=NULL){
            free(pre);
            pre = curr;
            curr = curr->next;
        }
        free(pre);
        free(curr);
    }
}

//��ӡ����ʽ
void printPoly(Polynomial* Head){
    Polynomial* curr = Head;
    int flag = 1;
    if(curr==NULL)printf("����Ϊ��\n");
    else{
        //��һ�����벻��ҪԼ������
        if(curr->coeff!=0){
            if((curr->nume < 0)){
                printf("%.3f*X^(%d)  ",curr->coeff,curr->nume);
                flag = 0;
            }
            else if(curr->nume == 1){
                printf("%.3f*X  ",curr->coeff,curr->nume);
                flag = 0;
            }
            else if(curr->nume == 0){
                printf("%.3f  ",curr->coeff,curr->nume);
                flag = 0;
            }
            else{
                printf("%.3f*X^%d  ",curr->coeff,curr->nume);
                flag = 0;
            }
        }
        else if(curr->coeff == 1){
            if((curr->nume < 0)){
                printf("X^(%d)  ",curr->coeff,curr->nume);
                flag = 0;
            }
            else if(curr->nume == 1){
                printf("X  ",curr->coeff,curr->nume);
                flag = 0;
            }
            else if(curr->nume == 0){
                printf("%.3f  ",curr->coeff,curr->nume);
                flag = 0;
            }
            else{
                printf("X^%d  ",curr->coeff,curr->nume);
                flag = 0;
            }
        }

        curr = curr->next;
        while(curr != NULL){
            //��ϵ��(��1)
            if((curr->coeff > 0)&&(curr->coeff != 1)){
                if((curr->nume < 0)&&(flag == 0))printf("+%.3f*X^(%d)  ",curr->coeff,curr->nume);
                else if((curr->nume < 0)&&(flag == 1))printf("%.3f*X^(%d)  ",curr->coeff,curr->nume);
                else if((curr->nume > 0)&&(flag == 0)&&(curr->nume != 1))printf("+%.3f*X^%d  ",curr->coeff,curr->nume);
                else if((curr->nume == 1)&&(flag == 0))printf("+%.3f*X  ",curr->coeff,curr->nume);
                else if((curr->nume == 1)&&(flag == 1))printf("%.3f*X  ",curr->coeff,curr->nume);
                else if((curr->nume == 0)&&(flag == 0))printf("+%.3f  ",curr->coeff,curr->nume);
                else if((curr->nume == 0)&&(flag == 1))printf("%.3f  ",curr->coeff,curr->nume);
                else printf("%.3f*X^%d  ",curr->coeff,curr->nume);
            }
            //ϵ��Ϊ1
            else if(curr->coeff == 1){
                if((curr->nume < 0)&&(flag == 0))printf("+X^(%d)  ",curr->coeff,curr->nume);
                else if((curr->nume < 0)&&(flag == 1))printf("X^(%d)  ",curr->coeff,curr->nume);
                else if((curr->nume > 0)&&(flag == 0)&&(curr->nume != 1))printf("+X^%d  ",curr->coeff,curr->nume);
                else if((curr->nume == 1)&&(flag == 0))printf("+X  ",curr->coeff,curr->nume);
                else if((curr->nume == 1)&&(flag == 1))printf("X  ",curr->coeff,curr->nume);
                else if((curr->nume == 0)&&(flag == 0))printf("+%.3f  ",curr->coeff,curr->nume);
                else if((curr->nume == 0)&&(flag == 1))printf("%.3f  ",curr->coeff,curr->nume);
                else printf("%.3f*X^%d  ",curr->coeff,curr->nume);
            }
            //��ϵ��
            else if(curr->coeff < 0){
                if(curr->nume < 0)printf("%.3f*X^(%d)  ",curr->coeff,curr->nume);
                else if(curr->nume == 1)printf("%.3f*X  ",curr->coeff,curr->nume);
                else if(curr->nume == 0)printf("%.3f  ",curr->coeff,curr->nume);
                else printf("%.3f*X^%d  ",curr->coeff,curr->nume);
            }
            //ϵ��Ϊ0�����κδ�ӡ����
            curr = curr->next;
        }   
        
    }
    printf("\n");
}

//����ʽ�ӷ�
Polynomial* addPoly(Polynomial* head1, Polynomial* head2){
    Polynomial* curr1 = head1;
    Polynomial* curr2 = head2;

    Polynomial* temp_head = copyPoly(head1);//��Ŷ���ʽ�ӷ��������ͷ���
    while (curr2!=NULL){
        Polynomial* newAdd = (Polynomial*)malloc(sizeof(struct tagPolynomial));//����ʽ�ӷ��õ����½��
        iniPoly(newAdd);
        newAdd->coeff = curr2->coeff;
        newAdd->nume = curr2->nume;
        temp_head = insert(temp_head,newAdd);//����ʽ�ӷ��������Ʋ������
        curr2 = curr2->next;
    }
    return temp_head;
}

//����ʽ����
Polynomial* minusPoly(Polynomial* head1, Polynomial* head2){
    //������ʽ��������1-����2 ���� ����1+(-����2)
    Polynomial* curr = head1;
    Polynomial* temp_head = copyPoly(head2);
    temp_head = negPoly(temp_head);//����������ȡ��

    if(curr==NULL)return NULL;
    while (curr!=NULL){
        Polynomial* newAdd = (Polynomial*)malloc(sizeof(struct tagPolynomial));
        iniPoly(newAdd);
        newAdd->coeff = curr->coeff;
        newAdd->nume = curr->nume;
        temp_head = insert(temp_head,newAdd);//������1�Ľ�����ȡ���������2��ʵ�ֶ���ʽ��������
        curr = curr->next;
    }
    return temp_head;
}

//����ʽ�˷�
Polynomial* multiPoly(Polynomial* head1, Polynomial* head2){
    Polynomial* curr1 = head1;
    Polynomial* curr2 = head2;
    Polynomial* newMulti = (Polynomial*)malloc(sizeof(struct tagPolynomial));//��ŵ����˷�������½��
    Polynomial* temp_head = (Polynomial*)malloc(sizeof(struct tagPolynomial));//��Ŷ���ʽ�˷������������ͷ���
    iniPoly(temp_head);
    while(curr2!=NULL){
        curr1 = head1;
        while(curr1!=NULL){
            newMulti->coeff = curr1->coeff * curr2->coeff;
            newMulti->nume = curr1->nume + curr2->nume;
            temp_head = insert(temp_head,newMulti);
            curr1 = curr1->next;
        }
        curr2 = curr2->next;
    }
    return temp_head;
}

//����ʽ���ȣ�1����¼��Ӧ����1
int lens(Polynomial* head){
    Polynomial* curr = head;
    int count = 0;
    while(curr!=NULL){
        count++;
        curr = curr->next;
    }
    return count;
}

//��̬����ʽ��������
Polynomial* insert(Polynomial* Head, Polynomial* newPoly){
    Polynomial* curr = Head;
    Polynomial* tail = Head;
    Polynomial* copynew = (Polynomial*)malloc(sizeof(struct tagPolynomial));
    copynew->coeff = newPoly->coeff;
    copynew->nume = newPoly->nume;
    if((curr->coeff==0)&&(curr->nume==0)){
        Head->coeff = copynew->coeff;
        Head->nume = copynew->nume;
    }
    else{       
        while(tail->next != NULL){
            tail = tail->next;
        }
        int flag = 1;
        //ֻ��1��ͷ���
        if((curr->next==NULL)&&(curr->prior==NULL)){
            if(copynew->nume>curr->nume){
                curr->next=copynew;
                copynew->prior = curr;
                copynew->next = NULL;
            }
            else if(copynew->nume == curr->nume)
                curr->coeff += copynew->coeff;
            else{
                copynew->next = curr;
                curr->prior = copynew;
                curr->next = NULL;
                copynew->prior = NULL;
                return copynew;
            }
            return Head;
        }

        //����������Ϊ2
        do{
            if(copynew->nume>curr->nume){
                curr = curr->next;
                continue;
                }
            if(copynew->nume == curr->nume){
                curr->coeff = curr->coeff + copynew->coeff;
                flag = 0;
                break;
                }
            copynew->prior = curr->prior;
            if(curr->prior!=NULL)curr->prior->next = copynew;
            copynew->next = curr;
            curr->prior = copynew;
            flag = 0;
            break;
        }while(curr!=NULL);

        if(flag==1){
            tail->next = copynew;
            copynew->prior = tail;
            copynew->next = NULL;
        }
    }
    
    while(Head->prior!=NULL)Head = Head->prior;

    return Head;
}

//���ƶ���ʽ
Polynomial* copyPoly(Polynomial* Head){
    Polynomial* copyhead = (Polynomial*)malloc(sizeof(struct tagPolynomial));
    Polynomial* copy_pre = copyhead;
    copyhead->prior = NULL;
    copyhead->coeff = 0;
    copyhead->nume = 0;
    Polynomial* curr = Head;
    //ֻ��1��ͷ���
    if(lens(Head)==1){
        copyhead->coeff = Head->coeff;
        copyhead->nume = Head->nume;
        copyhead->next = NULL;
        return copyhead;
    }
    //2�����
    else if(lens(Head)==2){
        copyhead->coeff = Head->coeff;
        copyhead->nume = Head->nume;

        curr = curr->next;
        Polynomial* copycurr = (Polynomial*)malloc(sizeof(struct tagPolynomial));
        copycurr->coeff = curr->coeff;
        copycurr->nume = curr->nume;
        copyhead->next = copycurr;
        copycurr->prior = copyhead;
        copycurr->next = NULL;
        return copyhead;
    }
    //����3�����
    else{
        for(int i=0;i<(lens(Head)-1);i++){
            Polynomial* copycurr = (Polynomial*)malloc(sizeof(struct tagPolynomial));
            copy_pre->next = copycurr;
            copycurr->prior = copy_pre;
            copycurr->next = NULL;
            copycurr->coeff = 0;
            copycurr->nume = 0;
            copy_pre = copy_pre->next;
        }
        Polynomial* cpcurr = copyhead;
        while (curr!=NULL)
        {
            cpcurr->coeff = curr->coeff;
            cpcurr->nume = curr->nume;
            cpcurr = cpcurr->next;
            curr = curr->next;
        }

        // copy_pre->next = copycurr;
        // copycurr->prior = copy_pre;
        // copycurr->next = NULL;
        // //copycurr�ĵ�ַ��while���֮���ͻȻ�����һ����ַ
        // while ((curr->next)->next != NULL){
        //     copy_pre->coeff = curr->coeff;
        //     copy_pre->nume = curr->nume;

        //     copy_pre = copycurr;
        //     Polynomial* copycurr = (Polynomial*)malloc(sizeof(struct tagPolynomial));
        //     copy_pre->next = copycurr;
        //     copycurr->prior = copy_pre;
        //     copycurr->next = NULL;

        //     curr = curr->next;
        // }
        // copy_pre->coeff = curr->coeff;
        // copy_pre->nume = curr->nume;
        // curr = curr->next;
        // copycurr->coeff = curr->coeff;
        // copycurr->nume = curr->nume;

        return copyhead;
    }
}

//��ʼ�����
void iniPoly(Polynomial* poly){
    poly->next = NULL;
    poly->prior = NULL;
    poly->coeff = 0;
    poly->nume = 0;
}

//����ȡ��
Polynomial* negPoly(Polynomial* head){
    Polynomial* curr = head;
    if(curr==NULL)return NULL;
    while (curr!=NULL){
        curr->coeff = -(curr->coeff);
        curr = curr->next;
    }
    return head;
}

