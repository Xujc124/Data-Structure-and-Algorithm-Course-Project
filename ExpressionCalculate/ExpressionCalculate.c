#include <stdio.h>
#include <stdlib.h>
#include "Expression.h"
#define MAXSIG 100;
#define MSXNUM 100;

SigNode SigPop(SigNode top, int* SigLen){
    SigNode temp = top;
    SigNode newPop = (SigNode)malloc(sizeof(struct SignalStack));
    newPop->sig = top->sig;
    newPop->next = NULL;
    top = top->next;
    free(temp);
    (*SigLen)--;
    return newPop;
}

SigNode SigPush(SigNode top, SigNode push, int* SigLen){
    if(*SigLen >= 100){
        printf("----栈满----");
        return top;
    }
    // else if((*SigLen) == 0){
    //     (*SigLen)++;
    //     top->sig = push->sig;
    //     top->next = NULL;
    //     return top;
    // }
    else{
        // SigNode newPush = (SigNode)malloc(sizeof(struct SignalStack));
        // newPush->sig = push->sig;
        // newPush->next = top;
        // top = newPush;
        push->next = top;
        top = push;
        (*SigLen)++;
        return top;
    }
}

NumNode NumPop(NumNode top, int* NumLen){
    NumNode temp = top;
    top = top->next;
    free(temp);
    (*NumLen)--;
    return top;
}

NumNode NumPush(NumNode top, NumNode push, int* NumLen){
    if(*NumLen == 100){
        printf("----栈满----");
        return top;
    }
    else{
        push->next = top;
        *NumLen++;
        return push;
    }
}

void printSig(SigNode top){
    SigNode temp = top;
    while((temp!=NULL)&&(temp->sig!='#')){
        printf("%c ",temp->sig);
        temp = temp->next;
    }
    printf("\n");
}

//加入位次变化的标志位
SigNode state_sign(SigNode top){
    SigNode temp = (SigNode)malloc(sizeof(struct SignalStack));
    temp->next = top;
    temp->sig = '!';
    return temp;
}

//符号栈操作
SigNode SigConduct(SigNode sigTop, SigNode push, SigNode tempTop, int *SigLen, int *tempLen){
    if((*SigLen)==0){
        sigTop = SigPush(sigTop, push, SigLen);//运算符入s1
    }
    else if(sigTop->sig == '('){
        sigTop = SigPush(sigTop, push, SigLen);//运算符入s1
    }
    else if(compSig(sigTop,push)){
        sigTop = SigPush(sigTop, push, SigLen);//运算符入s1
    }
    else if((push->sig)=='('){
        sigTop = SigPush(sigTop, push, SigLen);//运算符入s1
    }
    else if((push->sig)==')'){
        SigNode c = (SigNode)malloc(sizeof(struct SignalStack));
        c->sig = SigPop(sigTop,SigLen)->sig;
        c->next = NULL;
        while(c->sig!='('){
            SigPush(tempTop,c,tempLen);
            SigNode c = (SigNode)malloc(sizeof(struct SignalStack));
            c->sig = SigPop(sigTop,SigLen)->sig;
            c->next = NULL;
        }
    }
    return tempTop;//返回s2的栈顶元素
}


int compSig(SigNode top, SigNode push){
    int i = 5,j=5;
    switch (push->sig)
    {
    case '(':
        i=0;
        break;
    case '[':
        i=0;
        break;
    case '+':
        i=1;
        break;
    case '-':
        i=1;
        break;
    case '*':
        i=2;
        break;
    case '/':
        i=2;
        break;
    default:
        break;
    }

    switch (top->sig)
    {
    case '(':
        j=0;
        break;
    case '[':
        i=0;
        break;
    case '+':
        j=1;
        break;
    case '-':
        j=1;
        break;
    case '*':
        j=2;
        break;
    case '/':
        j=2;
        break;
    default:
        break;
    }

    if(i>j)return 1;
    return 0;
}

//
int SigLength(SigNode top){
    int i = 0;
    SigNode temp = top;
    while (temp!=NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}