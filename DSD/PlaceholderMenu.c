#include <stdio.h>
#include <stdlib.h>

void placeholderControl(){
    char ph_set[999][999];
    char format[999];
    char ftwin[999];
    int ph_num[999];
    char temp;
    char replace;
    int output=0;
    int count = 0;
    int fm_count = 0;
    int ph_count = 0;
    int flag = 0;
    printf("�������ʽ�ַ���:");
    scanf("%c",&temp);
    while(temp!='\n'){
        if(temp=='{'){
            format[fm_count] = '!';
            fm_count++;
            scanf("%d",&(ph_num[count]));
            count++;
            scanf("%c",&temp);
        }
        else if(temp!='}'){
            format[fm_count] = temp;
            fm_count++;
        }
        scanf("%c",&temp);
    }
    format[fm_count] = temp;
    fm_count++;


    printf("�������滻�ַ���:");
    scanf("%c",&temp);
    while(temp!='\n'){
        if(flag==1){
            int i = 0;
            ph_set[ph_count][i] = temp;
            i++;
            scanf("%c",&replace);
            while(replace!='"'){
                ph_set[ph_count][i] = replace;
                scanf("%c",&replace);
                i++;
            }
            ph_set[ph_count][i] = '\n';
            scanf("%c",&temp);
            if(temp=='\n')break;
            flag = 0;
            ph_count++;
        }
        if(temp=='"')flag=1;
        scanf("%c",&temp);
    }

    //����������ʽ�ַ���
    int j = -1;
    do{
        j++;
        ftwin[j] = format[j];
    }while(format[j]!='\n');

    j = 0;
    int k = 0;//��¼������������ʽ�ַ����е�λ��
    int m = 0;//��¼��һ����������ֱ�ʶ
    int n = 0;//��������滻�ַ���
    printf("�������ַ���Ϊ:");
    while(ftwin[k]!='\n'){
        if(ftwin[k]=='!'){
            n = 0;
            while (ph_set[ph_num[m]][n]!='\n'){
                format[j] = ph_set[ph_num[m]][n];
                j++;
                n++;
            }
            m++;
            k++;
        }
        else{
            format[j] = ftwin[k];
            j++;
            k++;
        }
    }
    format[j] = '\n';

    //��ӡ���
    j = 0;
    do{
        printf("%c",format[j]);
        j++;
    }while(format[j]!='\n');

    printf("\n");
    system("pause");
}