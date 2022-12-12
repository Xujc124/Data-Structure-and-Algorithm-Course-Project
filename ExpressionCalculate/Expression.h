#ifndef H_expression
#define H_expression

#include <stdio.h>
#include <stdlib.h>

typedef struct SignalStack
{
    char sig;
    struct SignalStack* next;
}*SigNode;

typedef struct NumberStack
{
    double num;
    struct NumberStack* next;
}*NumNode;

SigNode SigPop(SigNode top, int* SigLen);

SigNode SigPush(SigNode top, SigNode push, int* SigLen);

NumNode NumPop(NumNode top, int* NumLen);

NumNode NumPush(NumNode top, NumNode push, int* NumLen);

void printSig(SigNode top);

SigNode state_sign(SigNode top);

SigNode SigConduct(SigNode top, SigNode push, SigNode tempTop, int *SigLen, int *tempLen);

int SigLength(SigNode top);

int compSig(SigNode top, SigNode push);

#endif