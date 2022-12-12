#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynomial.h"

/*多项式操作函数*/

//创建多项式
Polynomial* createPoly(){
    // char c;
    // int count = 0, nume = 0, flag = 1, 
    // double coeff = 0;
    int polyNum = 0;//多项式的项数

    Polynomial* head = (Polynomial*)malloc(sizeof(struct tagPolynomial));//定义头结点
    // Polynomial* tail = (Polynomial*)malloc(sizeof(struct tagPolynomial));//定义尾结点
    iniPoly(head);//头结点初始化
    // iniPoly(tail);//尾结点初始化

    /*引导语*/
    printf("请输入您想输入的多项式个数:");
    scanf("%d",&polyNum);
    printf("\n输入格式：系数 幂次 系数 幂次...\n");
    printf("\n请输入您想输入的多项式:");

    //填充所有节点
    scanf("%lf %d",&(head->coeff),&(head->nume));
    for(int i = 1;i < polyNum;i++){
        Polynomial* polyP = (Polynomial*)malloc(sizeof(struct tagPolynomial));
        iniPoly(polyP);
        scanf("%lf %d",&(polyP->coeff),&(polyP->nume));
        head = insert(head,polyP);//将新节点按序插入链表
        printf("\n");
    }
    printf("--------------------------------------\n");

    /*另一种输入方式*/
    // printf("注意:多项式输入的格式为A B\n");
    // printf("最后请以0 0结尾\n");
    // printf("请输入多项式的系数:\n");
    // while(1){
    //     scanf("%lf %d",&coeff,&nume);
    //     if((coeff==0)&&(nume==0))break;//跳出循环的条件

    //     //第1次输入
    //     if(flag == 1){
    //     head->nume = nume;
    //     head->coeff = coeff;
    //     flag = 0;
    //     // printPoly(head);
    //     }

    //     //第2次输入
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

    //     //非第1、2次输入
    //     else{
    //         Polynomial* pGet;
    //         pGet = (Polynomial*)malloc(sizeof(struct tagPolynomial));

    //         pGet->nume = nume;
    //         pGet->coeff = coeff;

    //         head = insert(head,pGet);
    //         tail = head->next;
    //         while(tail->next != NULL)tail = tail->next;//将tail移至链表最后

    //         flag = 3;
    //     }
    //     coeff = nume = 0;//赋初值
    // }

    // if(flag == 0){
    //     head->next = NULL;//一个头结点封尾
    // }
    return head;
}

//删除多项式
void deletePoly(Polynomial* Head){
    Polynomial* curr, *pre;
    pre = Head;
    curr = Head->next;
    //只有头结点
    if(curr == NULL){
        Head->next = NULL;
        Head->prior = NULL;
        free(pre);
    }
    //有头结点和尾结点
    else if(curr->next == NULL){
        Head->next = NULL;
        Head->prior = NULL;
        free(pre);
        free(curr);
    }
    //至少有3个结点
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

//打印多项式
void printPoly(Polynomial* Head){
    Polynomial* curr = Head;
    int flag = 1;
    if(curr==NULL)printf("链表为空\n");
    else{
        //第一次输入不需要约束符号
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
            //正系数(非1)
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
            //系数为1
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
            //负系数
            else if(curr->coeff < 0){
                if(curr->nume < 0)printf("%.3f*X^(%d)  ",curr->coeff,curr->nume);
                else if(curr->nume == 1)printf("%.3f*X  ",curr->coeff,curr->nume);
                else if(curr->nume == 0)printf("%.3f  ",curr->coeff,curr->nume);
                else printf("%.3f*X^%d  ",curr->coeff,curr->nume);
            }
            //系数为0不做任何打印操作
            curr = curr->next;
        }   
        
    }
    printf("\n");
}

//多项式加法
Polynomial* addPoly(Polynomial* head1, Polynomial* head2){
    Polynomial* curr1 = head1;
    Polynomial* curr2 = head2;

    Polynomial* temp_head = copyPoly(head1);//存放多项式加法的链表的头结点
    while (curr2!=NULL){
        Polynomial* newAdd = (Polynomial*)malloc(sizeof(struct tagPolynomial));//多项式加法得到的新结点
        iniPoly(newAdd);
        newAdd->coeff = curr2->coeff;
        newAdd->nume = curr2->nume;
        temp_head = insert(temp_head,newAdd);//多项式加法操作类似插入操作
        curr2 = curr2->next;
    }
    return temp_head;
}

//多项式减法
Polynomial* minusPoly(Polynomial* head1, Polynomial* head2){
    //将多项式减法链表1-链表2 看作 链表1+(-链表2)
    Polynomial* curr = head1;
    Polynomial* temp_head = copyPoly(head2);
    temp_head = negPoly(temp_head);//链表结点内容取负

    if(curr==NULL)return NULL;
    while (curr!=NULL){
        Polynomial* newAdd = (Polynomial*)malloc(sizeof(struct tagPolynomial));
        iniPoly(newAdd);
        newAdd->coeff = curr->coeff;
        newAdd->nume = curr->nume;
        temp_head = insert(temp_head,newAdd);//将链表1的结点加入取反后的链表2，实现多项式减法操作
        curr = curr->next;
    }
    return temp_head;
}

//多项式乘法
Polynomial* multiPoly(Polynomial* head1, Polynomial* head2){
    Polynomial* curr1 = head1;
    Polynomial* curr2 = head2;
    Polynomial* newMulti = (Polynomial*)malloc(sizeof(struct tagPolynomial));//存放单个乘法结果的新结点
    Polynomial* temp_head = (Polynomial*)malloc(sizeof(struct tagPolynomial));//存放多项式乘法结果的新链表头结点
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

//多项式长度，1条记录对应长度1
int lens(Polynomial* head){
    Polynomial* curr = head;
    int count = 0;
    while(curr!=NULL){
        count++;
        curr = curr->next;
    }
    return count;
}

//动态多项式插入排序
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
        //只有1个头结点
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

        //链表长度至少为2
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

//复制多项式
Polynomial* copyPoly(Polynomial* Head){
    Polynomial* copyhead = (Polynomial*)malloc(sizeof(struct tagPolynomial));
    Polynomial* copy_pre = copyhead;
    copyhead->prior = NULL;
    copyhead->coeff = 0;
    copyhead->nume = 0;
    Polynomial* curr = Head;
    //只有1个头结点
    if(lens(Head)==1){
        copyhead->coeff = Head->coeff;
        copyhead->nume = Head->nume;
        copyhead->next = NULL;
        return copyhead;
    }
    //2个结点
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
    //至少3个结点
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
        // //copycurr的地址在while语句之后会突然变成另一个地址
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

//初始化结点
void iniPoly(Polynomial* poly){
    poly->next = NULL;
    poly->prior = NULL;
    poly->coeff = 0;
    poly->nume = 0;
}

//链表取负
Polynomial* negPoly(Polynomial* head){
    Polynomial* curr = head;
    if(curr==NULL)return NULL;
    while (curr!=NULL){
        curr->coeff = -(curr->coeff);
        curr = curr->next;
    }
    return head;
}

