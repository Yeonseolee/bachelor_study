#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// invalid Pointer error

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _deque{
    Node * front;
    Node * rear;
    int size;
} Deque;

void init(Deque * pq){
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

int emtpy(Deque * pq){
    if(pq->front == NULL) return TRUE;
    else return FALSE;
}

void push_front(Deque * pq, Data data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pq->front;

    if(emtpy(pq)){
        pq->rear = newNode;
    } else {
        pq->front->prev = newNode;
    }

    newNode->prev = NULL;
    pq->front = newNode;

    (pq->size)++;
}

void push_back(Deque * pq, Data data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pq->rear;

    if(emtpy(pq)) pq->front = newNode;
    else pq->rear->next = newNode;

    newNode->next = NULL;
    pq->rear = newNode;
    (pq->size)++;
}

Data pop_front(Deque * pq){
    Node * delNode = pq->front;;
    Data retdata = delNode->data;

    if(emtpy(pq)) return -1;
    else {

        pq->front = pq->front->next;
        free(delNode);
        
        if(pq->front == NULL) pq->rear = NULL;
        else pq->front->prev = NULL;

        (pq->size)--;

        return retdata;
    }
}

Data pop_back(Deque * pq){
    Node * delNode = pq->rear;;
    Data retdata = delNode->data;

    if(emtpy(pq)) return -1;
    else {

        pq->rear = pq->rear->prev;
        free(delNode);

        if(pq->rear == NULL) pq->front = NULL;
        else pq->rear->next = NULL;

        (pq->size)--;

        return retdata;
    }
}

int size(Deque * pq){
    return pq->size;
}

int front(Deque * pq){
    if(emtpy(pq)) return -1;
    else return pq->front->data;
}

int back(Deque * pq){
    if(emtpy(pq)) return -1;
    else return pq->rear->data;
}

int main(void){

    int n; 
    Deque program;
    init(&program);
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char command[10];
        scanf("%s", command);
        // printf("this is command %s\n", command);

        if(strcmp(command, "push_front")==0) {

            int tmp;
            scanf(" %d", &tmp);
            push_front(&program, tmp);

        } else if(strcmp(command, "push_back")==0) {

            int tmp;
            scanf(" %d", &tmp);
            push_back(&program, tmp);

        } else if(strcmp(command, "pop_front")==0){

            printf("%d\n", pop_front(&program));

        } else if(strcmp(command, "pop_back")==0){

            printf("%d\n", pop_back(&program));

        } else if(strcmp(command, "size")==0) printf("%d\n", size(&program));
        else if(strcmp(command, "empty")==0) printf("%d\n", emtpy(&program));
        else if(strcmp(command, "front")==0) printf("%d\n", front(&program));
        else printf("%d\n", back(&program));
    }
    
    return 0;
}