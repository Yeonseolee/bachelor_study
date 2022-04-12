#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2){
    if(d1 < d2) return 0;
    else return 1;
}


int main(void) {
    List list;
    LData data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);

    LInsert(&list, 11); LInsert(&list, 11); 
    LInsert(&list, 22); LInsert(&list, 22); 
    LInsert(&list, 33); 

    if(LFirst(&list, &data)){
        printf("%d ", data);

        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }

    printf("\n");

    // 22모두 삭제
    if(LFirst(&list, &data)){
        if(data == 22) LRemove(&list);

        while(LNext(&list, &data)){
            if(data == 22) LRemove(&list);
        }
    }

    // 남은 데이터 조회

    if(LFirst(&list, &data)){
        printf("%d ", data);

        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }

    return 0;
}

