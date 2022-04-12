#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "SimpleHeap.h"

void HeapInit(Heap * ph){
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph){
    if(ph->numOfData == 0) return TRUE;
    else return FALSE;
}


int GetParentIdx(int idx){ // 부모 노드 인덱스 반환
    return idx/2;
}

int GetLChildIdx(int idx){ // 왼쪽 자식노드 인덱스 반환
    return idx * 2;
}

int GetRChildeIdx(int idx){ // 오른쪽 자식노드 인덱스 반환
    return idx * 2 + 1;
}



void HInsert(Heap * ph, HData data, Priority pr){

    int idx = ph->numOfData+1;
    HeapElem tmp = {pr, data};
    while(idx != 1){
        if(pr < ph->heapArr[GetParentIdx(idx)].pr){
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        } else {
            break;
        }
    }

    ph->heapArr[idx] = tmp;
    (ph->numOfData++);

}

// 우선순위가 높은 자식노드 idx 반환
int GetHiPriChildIdx(Heap * ph, int idx){
    if(GetLChildIdx(idx) > ph->numOfData){ // 자식 노드가 존재하지 않을 경우
        return FALSE;
    } else if(GetLChildIdx(idx) == ph->numOfData){ // 자식 노드가 하나만 있을 경우
        return GetLChildIdx(idx);
    } else {
        if(ph->heapArr[GetLChildIdx(idx)].pr < ph->heapArr[GetRChildeIdx(idx)].pr){
            return GetLChildIdx(idx);
        } else return GetRChildeIdx(idx);
    }
}

HData HDelete(Heap * ph){

    HData retData = ph->heapArr[1].data;
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int pIdx = 1;
    int chIdx;

    while(chIdx = GetHiPriChildIdx(ph, pIdx)){
        if(lastElem.pr > ph->heapArr[chIdx].pr){
            ph->heapArr[pIdx] = ph->heapArr[chIdx];
            pIdx = chIdx;
        } else break;
    }

    ph->heapArr[chIdx] = lastElem;
    (ph->numOfData)--;
    return retData;
}