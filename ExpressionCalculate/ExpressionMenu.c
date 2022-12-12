#include <stdio.h>
#include <stdlib.h>
#include "Expression.h"

void expMenuControl(){
    int flag=1,no_ones_place=0,flag4=1;
    int Sig = 0,total = 0,num=0;
    int div_zero = 0;//除数为0的标志位
    int* sigLen = &Sig;//s1的栈元素个数
    int* totalLen = &total;//s2的栈元素个数
    int* numLen = &num;//s3的栈元素个数
    SigNode sig_top = (SigNode)malloc(sizeof(struct SignalStack));//s1初始化
    SigNode total_top = (SigNode)malloc(sizeof(struct SignalStack));//s2初始化
    SigNode pre_curr;
    SigNode pre_head;
    sig_top->next = NULL;
    total_top->next = NULL;
    sig_top->sig = '#';//规定栈底元素
    total_top->sig = '#';//规定栈底元素
    char c;//用于接收输入
    printf("请输入需要计算的常数式：");
    scanf("%c",&c);
    while(c != '\n'){
        SigNode pre_new = (SigNode)malloc(sizeof(struct SignalStack));
        pre_new->sig = c;
        pre_new->next = NULL;

        if(flag4==1){//第一次输入
            pre_head = pre_new;
            pre_curr = pre_new;
            flag4 = 0;
            scanf("%c",&c);
            continue;
        }
        else{//非第一次输入
            pre_curr->next = pre_new;
            pre_curr = pre_new;
        }
        scanf("%c",&c);
    }

    // printSig(pre_head);

    //检测输入是否合法
    //括号对称检测
    pre_curr = pre_head;
    int left_Pa = 0;//左小括号标志位
    int left_Br = 0;//左中括号标志位
    int legal_Sign = 1;
    while(pre_curr!=NULL){
        if(pre_curr->sig == '(')left_Pa++;
        if(pre_curr->sig == ')')left_Pa--;
        if(pre_curr->sig == '[')left_Br++;
        if(pre_curr->sig == ']')left_Br--;
        //小括号包在大括号外面
        if((pre_curr->sig == '[')&&(left_Pa > 0)){
            printf("\n输入不合法：小括号包含了大括号\n");
            legal_Sign = 0;
            break;
        }
        if((left_Pa<0)|(left_Br<0)){
            printf("\n输入不合法：先出现了右括号\n");
            legal_Sign = 0;
            break;
        }
        if((pre_curr->sig == ']')&&(left_Pa > 0)){
            printf("\n输入不合法：大括号和小括号作用域交叉\n");
            legal_Sign = 0;
            break;
        }
        pre_curr = pre_curr->next;
    }

    //检验括号是否成对使用
    if((legal_Sign==1)&&((left_Pa!=0)|(left_Br!=0))){
        printf("\n输入不合法：括号没有成对使用\n");
        legal_Sign = 0;
    }

    //操作数和操作符检验
    pre_curr = pre_head;
    int cond_num = 0;
    int ctan_num = 0;
    while(pre_curr!=NULL){
        if(((cond_num>1)|(cond_num<0))&&(ctan_num != 1)){
            printf("\n输入不合法：操作数和操作符没有按次序输入\n");
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

    //没有以操作数结尾
    if((legal_Sign==1)&&(cond_num != 1)){
        printf("\n输入不合法：没有以操作数结尾\n");
        legal_Sign = 0;
    }

    if(legal_Sign==1){
        pre_curr = pre_head;
            while(pre_curr!=NULL){//未读到句末
            //排除所有空格
            if(pre_curr->sig == ' '){
                no_ones_place = 0;
                pre_curr = pre_curr->next;
                continue;
            }
            //数字入s2
            else if((pre_curr->sig>='0')&&(pre_curr->sig<='9')){
                //定义新的入栈元素
                SigNode temp = (SigNode)malloc(sizeof(struct SignalStack));
                temp->sig = pre_curr->sig;
                temp->next = NULL;
                //定义栈顶元素
                if(flag==1){
                    total_top = SigPush(total_top,temp,&total);
                    flag = 0;
                    pre_curr = pre_curr->next;
                    no_ones_place=1;
                    continue;
                }
                if((no_ones_place==1)&&(pre_curr->sig>='0')&&(pre_curr->sig<='9')){//检测到连续的数字
                    total_top = state_sign(total_top);//先添加一个!
                    total_top = SigPush(total_top,temp,&total);//数字入栈
                    pre_curr = pre_curr->next;
                    continue;
                }
                no_ones_place=1;//第一次检测到数字
                total_top = SigPush(total_top,temp,&total);
            }
            //符号判断入栈
            else{
                no_ones_place=0;
                SigNode temp = (SigNode)malloc(sizeof(struct SignalStack));
                temp->sig = pre_curr->sig;
                temp->next = NULL;
                if((*sigLen)==0){
                    sig_top = SigPush(sig_top, temp, sigLen);//运算符入s1
                }
                else if((sig_top->sig == '(')|(sig_top->sig == '[')){
                    sig_top = SigPush(sig_top, temp, sigLen);//运算符入s1
                }
                else if((temp->sig!=')')&&(temp->sig!=']')&&(compSig(sig_top,temp))){
                    sig_top = SigPush(sig_top, temp, sigLen);//运算符入s1
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
                    sig_top = SigPush(sig_top, temp, sigLen);//运算符入s1
                }
                else if((temp->sig)=='['){
                    sig_top = SigPush(sig_top, temp, sigLen);//运算符入s1
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
            total_top = SigPush(total_top,chh,&total);//将剩余s1元素弹出并依次压入s2
        }

        /*反转s2的顺序*/
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
        printf("后缀表达式结果为：");
        printSig(total_top);
        printf("\n");

        /*计算后缀表达式*/
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
            if((curr->next!=NULL)&&(curr->next->sig == '!')){//检测到连续数字
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
                if(flag3==1){//第一次输入个位数字
                    num_top->num = curr->sig-'0';
                    flag3 = 0;
                    curr = curr->next;
                }
                else{//第二次输入个位数字
                    NumNode new_num_push = (NumNode)malloc(sizeof(struct NumberStack));
                    new_num_push->num = curr->sig - '0';
                    num_top = NumPush(num_top,new_num_push,numLen);
                    curr = curr->next;
                }
            }
            else{//检测到运算符
                //定位栈顶元素
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
            printf("输入不合法：除数为0\n");
            printf("请重新输入！！\n");
        }
        else{
            printf("计算结果为;%f\n",num_top->num);
        }
    }
    system("pause");
}