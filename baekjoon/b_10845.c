#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

typedef int QData;

typedef struct __node{
    QData data;
    struct __node * next;
} Node;

typedef struct __queue{
    Node * front;
    Node * rear;
    int numOfData;
} Queue;


void queueInit(Queue * pq){
    pq->front = NULL;
    pq->rear = NULL;
    pq->numOfData = 0;
}

int empty(Queue * pq){
    if(pq->front == NULL) return 1;
    else return 0;
}

void push(Queue * pq, QData data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(empty(pq)) {
        pq->front = newNode;
        pq->rear = newNode;
        (pq->numOfData)++;
    } else {
        pq->rear->next = newNode;
        pq->rear = pq->rear->next;
        (pq->numOfData)++;
    }
}

QData pop(Queue * pq) {
    QData retData;
    Node * delNode;

    if(empty(pq)) {
        return -1;
    } else {
        delNode = pq->front;
        retData = delNode->data;
        
        pq->front = pq->front->next;
        (pq->numOfData)--;

        free(delNode);
        return retData;
    }
}

QData size(Queue * pq){
    return pq->numOfData;
}

QData front(Queue * pq){
    if(empty(pq)) return -1;
    else return pq->front->data;
}

QData back(Queue * pq){
    if(empty(pq)) return -1;
    else return pq->rear->data;
}

int main(void) {
    int n;
    char command[6];
    Queue qList;

    queueInit(&qList);

    scanf("%d", &n );
    for(int i = 0; i < n; i++) {
        int data;
        scanf("%s", command);
        switch(command[1])
        {
        case 'u':
            scanf(" %d", &data);
            push(&qList, data);
            break;
        case 'o':
            printf("%d\n", pop(&qList));
            break;
        case 'i':
            printf("%d\n", size(&qList));
            break;
        case 'm':
            printf("%d\n", empty(&qList));
            break;
        case 'r':
            printf("%d\n", front(&qList));
            break;;
        case 'a':
            printf("%d\n", back(&qList));
            break;
        }
    }
    

    return 0;
}




