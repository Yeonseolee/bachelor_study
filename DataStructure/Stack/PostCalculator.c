#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]){
    Stack stack;
    int expLen = strlen(exp);
    char tok, op1, op2;

    for(int i = 0; i<expLen; i++) {

        tok = exp[i];
        if(isdigit(tok)){
            SPush(&stack, tok - '0'); // 숫자 변환 방법임. 숙지할 것
        } else {
            op1 = SPop(&stack);
            op2 = SPop(&stack);
            switch (tok)
            {
            case '+': 
                SPush(&stack, op2 + op1);
                break;
            case '-': 
                SPush(&stack, op2 - op1);
                break;
            case '*':
                SPush(&stack, op2 * op1);
                break;
            case '/':
                SPush(&stack, op2 / op1);
                break;
            }
        }
    }

    return SPop(&stack);
}