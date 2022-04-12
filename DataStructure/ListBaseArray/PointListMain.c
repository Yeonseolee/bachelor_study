#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"


// 실행하려면 무슨 처리가 필요함
// https://m.blog.naver.com/ppdha/221441422172


int main(void) {
    List list;
    Point comPos;
    Point * ppos;

    ListInit(&list);

    // 데이터 저장
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    ListInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    ListInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    ListInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    ListInsert(&list, ppos);


    // 데이터 출력
    printf("현재 데이터 수 : %d", LCount(&list));

    if(LFirst(&list, ppos)){
        ShowPointPos(ppos);
        while(LNext(&list, ppos)){
            ShowPointPos(ppos);
        }
    }


    // 데이터 삭제: ypos = 인 데이터 삭제
    comPos.xpos = 0;
    comPos.ypos = 1;

    if(LFirst(&list, ppos)){
        if(PointComp(&comPos, ppos) == 2){
            ppos = LRemove(&list);
            free(ppos);
        }

        while(LNext(&list, ppos)){
            if(PointComp(&comPos, ppos) == 2){
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }

    // 삭제 후 남은 데이터 출력
    printf("삭제 후 데이터 수 : %d", LCount(&list));

    if(LFirst(&list, ppos)){
        ShowPointPos(ppos);
        while(LNext(&list, ppos)){
            ShowPointPos(ppos);
        }
    }

    return 0;
}