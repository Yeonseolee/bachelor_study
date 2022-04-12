#include <stdio.h>
#include "ArrayList.h"

// 리스트 초기화
void ListInit(List * plist) {
    (plist->numOfData) = 0; 
    (plist->curPostion) = -1; // curPosition에는 데이터 인덱스를 담으므로 처음에는 아무것도 안담겼다는 의미. 
}

void ListInsert(List * plist, LData data){

    // 저장할 공간이 없을 때
    if(plist->numOfData >= LIST_LEN){ 
        puts("저장이 불가합니다");
        return ;
    }

    plist->arr[plist->numOfData] = data; 
    (plist->numOfData)++;

}

int LFirst(List * plist, LData * pdata){
    // 저장된 데이터가 없을 때
    if(plist->numOfData == 0) return FALSE;

    (plist->curPostion) = 0;     // 참조 위치 초기화
    *pdata = plist->arr[0];     // data 변수에 데이터 저장(data는 pdata가 가르키는 공간)

    return TRUE;
}

int LNext(List * plist, LData * pdata){
    // 더 이상 참조할 데이터가 없을 때
    if(plist->curPostion >= (plist->numOfData) -1) return FALSE;

    (plist->curPostion)++;      // 참조 위치 이동
    *pdata = plist->arr[plist->curPostion];
    return TRUE;
}

LData LRemove(List * plist) {
    int rpos = plist->curPostion;
    int num = plist->numOfData;
    int i;
    LData rdata = plist->arr[rpos];

    for(i=rpos; i<num-1; i++) {
        plist->arr[i] = plist->arr[i+1];
    }

    (plist->curPostion)--;      // 참조 위치를 하나 되돌린다
    (plist->numOfData)--;

    return rdata;
}

int LCount(List * plist) {
    return plist->numOfData;
}

