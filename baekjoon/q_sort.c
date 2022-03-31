#include <stdio.h>
#include <stdlib.h>

// 퀵정렬

void q_sort(int arr[], int start, int end);

int main() {
    int n;
    scanf("%d", &n);
    int * base = (int *)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &base[i]);
    }
    q_sort(base, 0, n-1);
    for(int i = 0; i < n; i++) {
        printf("%d ", base[i]);
    }

    free(base);
    return 0;
}

void q_sort(int arr[], int start, int end){
    int L = start, R = end, tmp, pivot = arr[(start+end)/2]; // while문 돌 때 pivot값은 변하지 않음. 
    while(L <= R) {
        while(arr[L] < pivot) L++;
        while(arr[R] > pivot) R--;
        
        if(L <= R) { // R , L이 index를 벗어날 경우 고려 && 엇갈리면 바꾸기 x
            if(L != R) { 
                tmp = arr[L];
                arr[L] = arr[R];
                arr[R] = tmp;
            }
            L++; R--;
        }

        printf("for test\n");
        for(int i = 0; i < 4; i++) printf("%d ", arr[i]);
        printf("\n\n");
    } 

    printf("start: %d < R: %d\nend: %d > L: %d\n",start, R, end, L);
    if(start < R) q_sort(arr, start, R);
    if(end > L) q_sort(arr, L, end);
}