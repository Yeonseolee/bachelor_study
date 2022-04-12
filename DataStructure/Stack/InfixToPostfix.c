#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "ListBaseStack.h"


// 연산자 우선순위 정보 반환 함수
int GetOpPrec(char op){
    switch (op)
    {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    }

    return -1; // 올바르지 않은 연산자일 경우
}


int WhoPrecOp(char op1, char op2){
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec) return 1; // 쟁반에 있는 연산자가 높은 경우
    else if(op1Prec < op2Prec) return -1;  // 쟁반에 있는 연산자가 낮은 경우
    else return 0; // 연산자 우선순위가 같은 경우

}



void ConvToRPNExp(char exp[]){

    Stack stack;  // 쟁반
    int expLen = strlen(exp);
    char * convExp = (char *)malloc(expLen+1);  // 배열 동적 할당

    int idx = 0; // 변환하는 문자열 배열 인덱스
    char tok, popOp;

    memset(convExp, 0, sizeof(char)*expLen +1); // 할당된 배열 0으로 초기화. 그냥 calloc 쓰면 안되나? 
    StackInit(&stack);


    for(int i = 0; i<expLen; i++) {
        tok = exp[i];

        if(isdigit(tok)){
            
            convExp[idx++] = tok;

        } else {
            switch(tok)
            {
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while(SPeek(&stack) != '(') {
                        char tmp = SPop(&stack);
                        convExp[idx++] = tmp;
                    }
                case '*': case '/':
                case '+': case '-':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0){
                        convExp[idx++] = tok;
                    }
                    SPush(&stack, tok);
                    break;

            }
        }
    }

    // 스택에 남아있는 연산자 옮기기
    while(!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);

    strcpy(exp, convExp); // 변환된 수식 exp 저장(exp는 배열이라 포인터처럼 사용 가능. 즉 외부에서도 값 참조 가능)
    free(convExp); // convExp 동적할당 해제
}



