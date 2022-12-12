#include <stdio.h>
#include <stdlib.h>
#include "Expression.h"

void expMenuControl(){
    int flag=1,no_ones_place=0,flag4=1;
    int Sig = 0,total = 0,num=0;
    int div_zero = 0;//����Ϊ0�ı�־λ
    int* sigLen = &Sig;//s1��ջԪ�ظ���
    int* totalLen = &total;//s2��ջԪ�ظ���
    int* numLen = &num;//s3��ջԪ�ظ���
    SigNode sig_top = (SigNode)malloc(sizeof(struct SignalStack));//s1��ʼ��
    SigNode total_top = (SigNode)malloc(sizeof(struct SignalStack));//s2��ʼ��
    SigNode pre_curr;
    SigNode pre_head;
    sig_top->next = NULL;
    total_top->next = NULL;
    sig_top->sig = '#';//�涨ջ��Ԫ��
    total_top->sig = '#';//�涨ջ��Ԫ��
    char c;//���ڽ�������
    printf("��������Ҫ����ĳ���ʽ��");
    scanf("%c",&c);
    while(c != '\n'){
        SigNode pre_new = (SigNode)malloc(sizeof(struct SignalStack));
        pre_new->sig = c;
        pre_new->next = NULL;

        if(flag4==1){//��һ������
            pre_head = pre_new;
            pre_curr = pre_new;
            flag4 = 0;
            scanf("%c",&c);
            continue;
        }
        else{//�ǵ�һ������
            pre_curr->next = pre_new;
            pre_curr = pre_new;
        }
        scanf("%c",&c);
    }

    // printSig(pre_head);

    //��������Ƿ�Ϸ�
    //���ŶԳƼ��
    pre_curr = pre_head;
    int left_Pa = 0;//��С���ű�־λ
    int left_Br = 0;//�������ű�־λ
    int legal_Sign = 1;
    while(pre_curr!=NULL){
        if(pre_curr->sig == '(')left_Pa++;
        if(pre_curr->sig == ')')left_Pa--;
        if(pre_curr->sig == '[')left_Br++;
        if(pre_curr->sig == ']')left_Br--;
        //С���Ű��ڴ���������
        if((pre_curr->sig == '[')&&(left_Pa > 0)){
            printf("\n���벻�Ϸ���С���Ű����˴�����\n");
            legal_Sign = 0;
            break;
        }
        if((left_Pa<0)|(left_Br<0)){
            printf("\n���벻�Ϸ����ȳ�����������\n");
            legal_Sign = 0;
            break;
        }
        if((pre_curr->sig == ']')&&(left_Pa > 0)){
            printf("\n���벻�Ϸ��������ź�С���������򽻲�\n");
            legal_Sign = 0;
            break;
        }
        pre_curr = pre_curr->next;
    }

    //���������Ƿ�ɶ�ʹ��
    if((legal_Sign==1)&&((left_Pa!=0)|(left_Br!=0))){
        printf("\n���벻�Ϸ�������û�гɶ�ʹ��\n");
        legal_Sign = 0;
    }

    //�������Ͳ���������
    pre_curr = pre_head;
    int cond_num = 0;
    int ctan_num = 0;
    while(pre_curr!=NULL){
        if(((cond_num>1)|(cond_num<0))&&(ctan_num != 1)){
            printf("\n���벻�Ϸ����������Ͳ�����û�а���������\n");
            legal_Sign = 0;
            break;
        }
        if((pre_curr->sig >= '0')&&(pre_curr->sig <= '9')){
            if(ctan_num != 1)cond_num++;
            ctan_num = 1;
        }
        else ctan_num = 0;
        if((pre_curr->sig == '+')|(pre_curr->sig == '-')|(pre_curr->sig == '*')|(pre_curr->sig == '/'))cond_num--;
        pre_curr = pre_curr->next;
    }

    //û���Բ�������β
    if((legal_Sign==1)&&(cond_num != 1)){
        printf("\n���벻�Ϸ���û���Բ�������β\n");
        legal_Sign = 0;
    }

    if(legal_Sign==1){
        pre_curr = pre_head;
            while(pre_curr!=NULL){//δ������ĩ
            //�ų����пո�
            if(pre_curr->sig == ' '){
                no_ones_place = 0;
                pre_curr = pre_curr->next;
                continue;
            }
            //������s2
            else if((pre_curr->sig>='0')&&(pre_curr->sig<='9')){
                //�����µ���ջԪ��
                SigNode temp = (SigNode)malloc(sizeof(struct SignalStack));
                temp->sig = pre_curr->sig;
                temp->next = NULL;
                //����ջ��Ԫ��
                if(flag==1){
                    total_top = SigPush(total_top,temp,&total);
                    flag = 0;
                    pre_curr = pre_curr->next;
                    no_ones_place=1;
                    continue;
                }
                if((no_ones_place==1)&&(pre_curr->sig>='0')&&(pre_curr->sig<='9')){//��⵽����������
                    total_top = state_sign(total_top);//�����һ��!
                    total_top = SigPush(total_top,temp,&total);//������ջ
                    pre_curr = pre_curr->next;
                    continue;
                }
                no_ones_place=1;//��һ�μ�⵽����
                total_top = SigPush(total_top,temp,&total);
            }
            //�����ж���ջ
            else{
                no_ones_place=0;
                SigNode temp = (SigNode)malloc(sizeof(struct SignalStack));
                temp->sig = pre_curr->sig;
                temp->next = NULL;
                if((*sigLen)==0){
                    sig_top = SigPush(sig_top, temp, sigLen);//�������s1
                }
                else if((sig_top->sig == '(')|(sig_top->sig == '[')){
                    sig_top = SigPush(sig_top, temp, sigLen);//�������s1
                }
                else if((temp->sig!=')')&&(temp->sig!=']')&&(compSig(sig_top,temp))){
                    sig_top = SigPush(sig_top, temp, sigLen);//�������s1
                }
                else if((temp->sig!=')')&&(temp->sig!='(')&&(temp->sig!=']')&&(temp->sig!='[')&&(!(compSig(sig_top,temp)))){
                    if((*sigLen)==1){
                        SigNode chhh = sig_top;
                        temp->next = sig_top;
                        sig_top = temp;
                        sig_top->next->next = total_top;
                        total_top = sig_top->next;
                        (*totalLen)++;
                        sig_top->next = NULL;
                    }

                    else{
                        SigNode chh = sig_top;
                        sig_top = sig_top->next;
                        (*sigLen)--;
                        chh->next = NULL;
                        total_top = SigPush(total_top,chh,totalLen);
                        continue;
                    }
                    
                }
                else if((temp->sig)=='('){
                    sig_top = SigPush(sig_top, temp, sigLen);//�������s1
                }
                else if((temp->sig)=='['){
                    sig_top = SigPush(sig_top, temp, sigLen);//�������s1
                }
                else if((temp->sig)==')'){
                    SigNode ch = sig_top;
                    sig_top = sig_top->next;
                    (*sigLen)--;
                    ch->next = NULL;
                    while(ch->sig!='('){
                        total_top = SigPush(total_top,ch,totalLen);
                        ch = sig_top;
                        sig_top = sig_top->next;
                        (*sigLen)--;
                        ch->next = NULL;
                    }
                }
                else if((temp->sig)==']'){
                    SigNode chhhhh = sig_top;
                    sig_top = sig_top->next;
                    (*sigLen)--;
                    chhhhh->next = NULL;
                    while(chhhhh->sig!='['){
                        total_top = SigPush(total_top,chhhhh,totalLen);
                        chhhhh = sig_top;
                        sig_top = sig_top->next;
                        (*sigLen)--;
                        chhhhh->next = NULL;
                    }
                }
            }
            pre_curr = pre_curr->next;
        }
        while((*sigLen)!=0){
            SigNode chh = sig_top;
            sig_top = sig_top->next;
            (*sigLen)--;
            chh->next = NULL;
            total_top = SigPush(total_top,chh,&total);//��ʣ��s1Ԫ�ص���������ѹ��s2
        }

        /*��תs2��˳��*/
        SigNode tail = total_top;
        SigNode curr = tail->next;
        SigNode head = curr->next;
        SigNode tail_tail = tail;
        while (head->sig != '#')
        {
            curr->next = tail;
            tail = curr;
            curr = head;
            head = head->next;
        }
        curr->next = tail;
        total_top = curr;
        tail_tail->next = head;
        printf("��׺���ʽ���Ϊ��");
        printSig(total_top);
        printf("\n");

        /*�����׺���ʽ*/
        NumNode num_top = (NumNode)malloc(sizeof(struct NumberStack));
        NumNode num_temp = num_top;
        SigNode num_search = curr;
        num_top->next = NULL;
        int flag3 = 1;
        int sum = 0;
        while(curr!=NULL){
            if(curr->sig == '#'){
                curr = curr->next;
                continue;
            }
            if((curr->next!=NULL)&&(curr->next->sig == '!')){//��⵽��������
                num_search = curr;
                while(num_search->next->sig == '!'){
                    sum = sum * 10 + (num_search->sig-'0');
                    num_search = num_search->next->next;
                }
                sum = sum * 10 + (num_search->sig-'0');
                NumNode new_num_push = (NumNode)malloc(sizeof(struct NumberStack));
                new_num_push->num = sum;
                num_top = NumPush(num_top,new_num_push,numLen);
                curr = num_search->next;
            }
            else if((curr->sig>='0')&&(curr->sig<='9')){
                if(flag3==1){//��һ�������λ����
                    num_top->num = curr->sig-'0';
                    flag3 = 0;
                    curr = curr->next;
                }
                else{//�ڶ��������λ����
                    NumNode new_num_push = (NumNode)malloc(sizeof(struct NumberStack));
                    new_num_push->num = curr->sig - '0';
                    num_top = NumPush(num_top,new_num_push,numLen);
                    curr = curr->next;
                }
            }
            else{//��⵽�����
                //��λջ��Ԫ��
                switch (curr->sig)
                {
                case '+':
                    num_top->next->num = num_top->next->num + num_top->num;
                    num_temp = num_top;
                    num_top = num_top->next;
                    free(num_temp);
                    curr = curr->next;
                    break;
                case '-':
                    num_top->next->num = num_top->next->num - num_top->num;
                    num_temp = num_top;
                    num_top = num_top->next;
                    free(num_temp);
                    curr = curr->next;
                    break;
                case '*':
                    num_top->next->num = num_top->next->num * num_top->num;
                    num_temp = num_top;
                    num_top = num_top->next;
                    free(num_temp);
                    curr = curr->next;
                    break;
                case '/':
                    if(num_top->num == 0){
                        div_zero = 1;
                        break;
                    }
                    num_top->next->num = num_top->next->num / num_top->num;
                    num_temp = num_top;
                    num_top = num_top->next;
                    free(num_temp);
                    curr = curr->next;
                    break;
                default:
                    break;
                }
            }
            if(div_zero == 1)break;
        }
        if(div_zero == 1){
            printf("���벻�Ϸ�������Ϊ0\n");
            printf("���������룡��\n");
        }
        else{
            printf("������Ϊ;%f\n",num_top->num);
        }
    }
    system("pause");
}