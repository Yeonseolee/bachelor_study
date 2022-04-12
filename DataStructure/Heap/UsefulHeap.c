#include <stdio.h>
#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc){
    ph->comp = pc;
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph){
    if(ph->numOfData == 0) return TRUE;
    else return FALSE;
}

int GetParentIdx(int idx) {
    return idx/2;
}

int GetLChildIdx(int idx) {
    return idx * 2;
}

int GetRChildIdx(int idx) {
    return idx * 2 + 1;
}

int GetHiPriChildIdx(Heap * ph, int idx){

    if(GetLChildIdx(idx) > ph->numOfData) 
        return FALSE; // 자식 노드 x
    else if(GetLChildIdx(idx) == ph->numOfData) 
        return GetLChildIdx(idx); // 단일노드
    else {
        if(ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) >= 0) {
            // 왼 노드가 우선순위가 높을 때 실행됨 ( return 1 )
            return GetLChildIdx(idx);
        } else {
            return GetRChildIdx(idx);
        }
    }
}

void HInsert(Heap * ph, HData data){
    int idx = ph->numOfData+1;
    while(idx != 1){
        if(ph->comp(data, ph->heapArr[GetParentIdx(idx)]) >= 0 ){
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        } else break;
    }
    ph->heapArr[idx] = data;
    (ph->numOfData)++;
}

HData HDelete(Heap * ph){
    HData retData = ph->heapArr[1];
    HData lastData = ph->heapArr[ph->numOfData];
    
    int pIdx = 1;
    int chIdx;
    while(chIdx = GetHiPriChildIdx(ph, pIdx)){
        if(!ph->comp(lastData, ph->heapArr[chIdx]) < 0){
            // lastData가 우선순위가 낮으면
            ph->heapArr[pIdx] = ph->heapArr[chIdx];
            pIdx = chIdx;
        } else break;
    }
    ph->heapArr[chIdx] = lastData;
    (ph->numOfData)--;
    
    return retData;
}

// PriorityComp 함수 구현 -> main 파일에다가 넣어야할 거
int DataPriorityComp(HData d1, HData d2){
    return d2 - d1;
}