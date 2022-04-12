#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL     100

typedef int (* HashFuc)(Key k);

typedef struct _table 
{
    List tbl[MAX_TBL];
    HashFuc * hf;
} Table;

void TBLINIT(Table * pt, HashFuc * f);
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelet(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);

#endif