#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void){
    
    BTreeNode * nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode * bt){
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data){
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt){
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt){
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub){
    if(main->left != NULL){
        // 순회를 이용한 삭제 구현 후 작성
        DeleteTree(main->left);
    }

    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub){
    if(main->right != NULL) {
        DeleteTree(main->right);
    }

    main->right = sub;
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action){

    if(bt == NULL) return ;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);

}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action){
    if(bt == NULL) return ;
    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTravers(BTreeNode * bt, VisitFuncPtr action) {
    
    if(bt == NULL) return ;
    InorderTraverse(bt->left, action);
    InorderTraverse(bt->right, action);
    ction(bt->data);
}

void DeletTree(BTreeNode * bt){
    if(bt == NULL) return ;
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    free(bt);
}