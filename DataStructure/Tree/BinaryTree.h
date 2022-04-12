#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct __bTreeNode{
    
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;

} BTreeNode;



//BT형태를 만드는 방법(저장?) 구현. 조회와 삭제는 x.

BTreeNode * MakeBTreeNode(void);

BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);


// 순회 구현(방문)

typedef void (* VisitFuncPtr)(BTData);

// 전위순회 : 루트노드 가장먼저 방문
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);

// 중위순회 : 루트노드 중간 방문
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);

// 후위순회: 루트노드 가장 나중에 방문
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);


// 순회를 이용한 삭제 구현 : 메모리의 누수 방지 
void DeleteTree(BTreeNode * bt);



#endif