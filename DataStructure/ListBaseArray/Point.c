#include <stdio.h>
#include "Point.h"

void SetPointPos(Point * ppos, int xpos, int ypos){
    ppos->xpos = xpos;
    ppos->ypos = ypos;
}

void ShowPointPost(Point * ppos){
    printf("[%d %d]", ppos->xpos, ppos->ypos);
}

int PointComp(Point * pos1, Point * pos2){
    int x1 = pos1->xpos, x2 = pos2->xpos;
    int y1 = pos1->ypos, y2 = pos2->ypos;

    if(x1 == x2 && y1 == y2) return 0;
    else if(x1 == x2) return 1;
    else if(y1 == y2) return 2;
    else return -1;
}