#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[]) {

    int len = strlen(exp);
    int result;
    char * expcpy = (char *)malloc(len+1);
    strcpy(expcpy, exp); // expcpy 문자열 배열에 exp 복사. exp는 변경하면 x.

    ConvToRPNExp(expcpy);
    result = EvalRPNExp(expcpy);

    free(expcpy);

    return result;
}